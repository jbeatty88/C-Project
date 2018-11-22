#include "Lexer.h"

Lexer::Lexer(std::string fileName) : input(fileName) {
    Automata();
}

Lexer::~Lexer() {}

void Lexer::Automata() {
    while(!input.IsEnd()) {
        CharMachine(input.Current());
        CommentMachine(input.Current());
        StringMachine(input.Current());
        KeywordMachine(input.Current());
        IDMachine(input.Current());
        UndefinedMachine(input.Current());
        WhitespaceMachine(input.Current());
        Advancer();
        //UnderTheHood("Advancer()");
    };
    Token tok(ENDOFILE, "", input.GetCurrentLine() + 1);
    tokenVec.push_back(tok);
    std::cout << "Total Tokens = " <<  tokenVec.size() << std::endl;
}

void Lexer::Advancer() { input.AdvanceBy(currentStr.length()); }

void Lexer::UnderTheHood(std::string prevCode) {
    // Strictly for personal debugging purposes
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();

    std::cout << "\n\033[1;4;31mVALUES AFTER: \033[m" << "\033[1m" <<  prevCode << "\033[0m";

    std::cout << "\n\033[1;36mCURRENT STRING: \033[0m" << "\033[1;7m" << currentStr << "\033[0m";
    std::cout << "\n\033[1;32mLINE LENGTH: \033[0m " << "\033[1;7m" << input.GetCurrentLength() << "\033[0m";
    std::cout << "\n\033[1;32mLINE: \033[0m" << "\033[1;7m" << input.GetCurrentLine() << "\033[0m";

    std::cout << "\n\033[1;32mCURRENT INDEX: \033[0m" << "\033[1;7m" << input.GetCurrentIdx() << "\033[0m";
    std::cout << "\n\033[1;36mCURRENT VALUE: \033[0m " << "\033[1;7m" << input.Current() << "\033[0m";

    std::cout << "\n\033[1;36mNEXT VALUE: \033[0m " << "\033[1;7m" << input.Next(1, linIdx, nxtIdx) << "\033[0m";
    std::cout << "\n\033[1;32mVEC SIZE: \033[0m " << "\033[1;7m" << input.GetVecSize() << "\033[0m" << "\n\n";

}
void Lexer::CharMachine(char ch) {
    // Each of these can be thought of as simple 2 state FSA's
    // >O ch-> 0
    switch(ch) {
    case ',':
        SingleCharStr(COMMA);
        break;
    case '.':
        SingleCharStr(PERIOD);
        break;
    case '?':
        SingleCharStr(Q_MARK);
        break;
    case '(':
        SingleCharStr(LEFT_PAREN);
        break;
    case ')':
        SingleCharStr(RIGHT_PAREN);
        break;
    case ':':
        ColonMachine();
        break;
    case '*':
        SingleCharStr(MULTIPLY);
        break;
    case '+':
        SingleCharStr(ADD);
        break;
    default:
        //Whitespace
        break;
    }
}

void Lexer::SingleCharStr(TokenType t) {
    // Token handler for single chars
    std::stringstream ss;
    ss << input.Current();
    currentStr = ss.str();
    TokenHandler(t);
    return;
}

void Lexer::TokenHandler(TokenType t) {
    Token tok(t, currentStr, input.GetCurrentLine());
    tokenVec.push_back(tok);
    return;
}

void Lexer::ColonMachine() {
    // This machine has two accept states
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();;
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();
    std::stringstream ss;
    if(input.Next(1, linIdx, nxtIdx) == '-') {
        // Accept Case 1: >O ':'-> '-' -> 0
        ss << input.Current() << input.Next(1, linIdx, nxtIdx);
        currentStr = ss.str();
        TokenHandler(COLON_DASH);
    }
    else {
        // Accept Case 2: >O ':'-> 0
        ss << input.Current();
        currentStr = ss.str();
        TokenHandler(COLON);
    }
    return;
}

void Lexer::KeywordMachine(char ch) {
    TokenType type = UNDEFINED;
    std::string str = "";
    size_t lineIdx = input.GetCurrentLineIdx();
    size_t idx = input.GetCurrentIdx();

    switch(ch) {
        // This machine has 4 accept states
        case 'S':
        // Accept Case 1: >O 'S'-> 'c' -> 'h' -> 'e' -> 'm' -> 'e' -> 's' -> 0
            str = "Schemes";
            type = SCHEMES;
            break;
        case 'F':
        // Accept Case 2: >O 'F'-> 'a' -> 'c' -> 't' -> 's' -> 0
            str = "Facts";
            type = FACTS;
            break;
        case 'R':
        // Accept Case 3: >O 'R'-> 'u' -> 'l' -> 'e' -> 's' -> 0
            str = "Rules";
            type = RULES;
            break;
        case 'Q':
        // Accept Case 4: >O 'Q'-> 'u' -> 'e' -> 'r' -> 'i' -> 'e' -> 's' -> 0
            str = "Queries";
            type = QUERIES;
            break;
        default:
            return;
    }
    // This handles the transition -> O -> O -> O (inbetween start and accept)
    if(str != "") {
        currentStr = KeywordCheck(str);
        // This handles the accept state: if -> 0 -> E (Sink state for non-keyword)
        if(!isalnum(input.Next(currentStr.length(), lineIdx, idx)) /*&& !isalnum(input.Before(1)) */ && currentStr.size() >= 5) {
            TokenHandler(type);
            return;
        }
    }
    return;
}

std::string Lexer::KeywordCheck(std::string keyword) {
    std::stringstream ss;
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();
    
   
    if(keyword.length() <= input.GetCurrentLength()) {
        for(size_t i = 0; i < keyword.length(); i++) {
            if(input.Next(i, linIdx, nxtIdx) == keyword[i]) {
                ss << input.Next(i,linIdx, nxtIdx);
            }
        }
    }

    if(ss.str().length() == keyword.length()) {
      return ss.str();
    }
    else {
      return "";
    }
}

void Lexer::IDMachine(char ch) {
    std::stringstream ss;
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();
    // This machine has 3 states (unless you count the keyword sink states)
    if(isalpha(ch)) {
        // >O [a-zA-Z] ->
        size_t i(0);
        while(isalnum(input.Next(i, linIdx, nxtIdx))) {
            // Transition state: O [a-zA-Z0-9] <@- ^[a-zA-Z0-9] -> 0 (State transitions to itself for any alnum)
            ss << input.Next(i, linIdx, nxtIdx);
            i++;
        }
        if(IsNotKeyword(ss.str())) {
            // Keyword sink states 0 [keyword] -> E
            currentStr = ss.str();
            TokenHandler(ID);
        }
    }
    else
        return;
}

bool Lexer::IsNotKeyword(std::string idStr) {
    // ID keyword check, Keywords have higer precedence thus cannot be ID
    if(idStr != "Schemes" && idStr != "Facts" && idStr != "Rules" && idStr != "Queries")
        return true;
    else
        return false;
}

void Lexer::StringMachine(char ch) {
    std::stringstream ss;
    // assume we have a string
    t = STRING;
    switch(ch) {
        // Start State: >O '\''->
        case '\'':
        {
          // Transition state: O ^['\''] <@ (Transitions back to itself)
          currentStr = GetString();
          // Accept State: '\'' -> 0
          TokenHandler(t);
          return;

        }
        default:
            return;
    }
}

std::string Lexer::GetString() {
     std::stringstream ss;
     isEnd = false;
     bool isUndefined = false;
     size_t linIdx(0);
     linIdx = input.GetCurrentLineIdx();
     size_t nxtIdx(0);
     nxtIdx = input.GetCurrentIdx();
     size_t i(1);
     ss << '\'';
     size_t nextNext = i + 1;
     // while we aren't to the end of our string

     while(!isEnd) {
       //#######################################################################
         // If we ARE NOT at the last line
        if(linIdx + 1 < input.GetVecSize()) {
            // Proceed as normal
            nextNext = i + 1;
            if(input.Next(i, linIdx, nxtIdx) == '\'' && input.Next(nextNext, linIdx, nxtIdx) != '\'') {
                // we're at the end
                isEnd = true;
                // string the final string symbol
                ss << '\'';
            }
            // if we have to consecutive single quotes
            else if(input.Next(i, linIdx, nxtIdx) == '\'' && input.Next(nextNext, linIdx, nxtIdx) == '\'') {
                // string them onto the string
                ss << '\'' << '\'';
                // skipt past them and continue reading the string
                i += 2;
            }
            else {
                if(input.Next(i, linIdx, nxtIdx) == '\n') {
                    ss << input.Next(i, linIdx, nxtIdx);
                    i = 0;
                    linIdx++;
                    nxtIdx = 0;
                }
                else {
                    ss << input.Next(i, linIdx, nxtIdx);
                    i++;
                }
            }
        }
        // but if we are on the last line
        else {

            if(input.Next(i, linIdx, nxtIdx) == '\n') {
                isEnd = true;
                isUndefined = true;
            }
            // If there is room left on the line
            else if(input.Next(i, linIdx, nxtIdx) == '\'' && input.Next(nextNext, linIdx, nxtIdx) != '\'') {
            // we're at the end
            isEnd = true;
            // string the final string symbol
            ss << '\'';
            }
            // if we have to consecutive single quotes
            else if(input.Next(i, linIdx, nxtIdx) == '\'' && input.Next(nextNext, linIdx, nxtIdx) == '\'') {
                // string them onto the string
                ss << '\'' << '\'';
                // skipt past them and continue reading the string
                i += 2; 
            }
            else {
                ss << input.Next(i, linIdx, nxtIdx);
                i++;
            }
        }
             // if we don't find another single quote, then we have an incomplete string
             
    }
        
        // //  ###########################################################
        // if we have another single quote
        //  nextNext = i + 1;
        //  if(input.Next(i, linIdx, nxtIdx) == '\'' && input.Next(nextNext, linIdx, nxtIdx) != '\'') {
        //      // we're at the end
        //      isEnd = true;
        //      // string the final string symbol
        //      ss << '\'';
        //  }
        //  // if we have to consecutive single quotes
        //  else if(input.Next(i, linIdx, nxtIdx) == '\'' && input.Next(nextNext, linIdx, nxtIdx) == '\'') {
        //      // string them onto the string
        //      ss << '\'' << '\'';
        //      // skipt past them and continue reading the string
        //      i += 2;
        //  }
         // as long as we dont have a single quote or 2 single quotes
        //  else {
        //      // while we aren't to the end of the file
        //      if(linIdx < input.GetVecSize()) {
        //        if(input.Next(i, linIdx, nxtIdx) == '\n') {
        //           if(linIdx == input.GetVecSize() - 1) {
        //             ss << input.Next(i, linIdx, nxtIdx);
        //             isEnd = true;
        //             isUndefined = true;
        //           }
        //           else {
        //             ss << input.Next(i, linIdx, nxtIdx);
        //             i = 0;
        //             linIdx++;
        //             nxtIdx = 0;
        //           }
        //        }
        //        else {
        //          ss << input.Next(i, linIdx, nxtIdx);
        //          i++;
        //        }
        //      }
        //      // if we don't find another single quote, then we have an incomplete string
        //      else {
        //          //ss << input.Next(i);
        //          isEnd = true;
        //          isUndefined = true;
        //      }
        //  }
    //  }
     // if our string was flagged incomplete, our type is now UNDEFINED
     if(isUndefined)
        t = UNDEFINED;

    //input.SetCurrentPos(input.GetCurrentLine() - newLine, tmpIdx);
    return ss.str();
}

void Lexer::CommentMachine(char ch) {
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();
    std::stringstream ss;
    // assume we have a comment
    t = COMMENT;
    std::string str;
    //size_t commentLine = input.GetCurrentLine();
    switch(ch) {
        // This machine has 2 separate branches that lead to accept states
        case '#': {
            // Start State: >O '#' -> O
            if(input.Next(1, linIdx, nxtIdx) == '|') {
                // '|' -> O ^(['|']['#']) <@ ['|'] -> O ['#'] -> 0
                currentStr = GetBlockComment();
                //currentStr = " ";
            }
            else {
                // -> O ^ ['\n'] <@ ['\n'] -> 0
                currentStr = GetSingleLineComment();
                //currentStr = str;
            }
            TokenHandler(t);
            return;
        }
        default:
            return;
    }
    return;
}

std::string Lexer::GetSingleLineComment() {
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();
    std::stringstream ss;
    isEnd = false;
    size_t i(1);
    ss << '#';
    // as long we we're  not at the end
    while(!isEnd) {
        // if we are at the end of the line or end of file
        if(input.Next(i, linIdx, nxtIdx) == NEWLINE_CHAR || input.Next(i, linIdx, nxtIdx) == ENDFILE_CHAR)
            // break from the loop
            isEnd = true;

        // if we aren't to the end of the line
        else {
            // string eveything on the line
            ss << input.Next(i, linIdx, nxtIdx);
            i++;
        }
    }
    return ss.str();
}

std::string Lexer::GetBlockComment() {
    std::stringstream ss;
    isEnd = false;
    size_t linIdx(0);
    linIdx = input.GetCurrentLineIdx();
    size_t nxtIdx(0);
    nxtIdx = input.GetCurrentIdx();
    size_t i(1);
    ss << '#';
    while(!isEnd) {
        if(input.Next(i, linIdx, nxtIdx) == '|' && input.Next(i + 1, linIdx, nxtIdx) == '#') {
            isEnd = true;
            ss << '|' << '#';
        }
        else if(input.Next(i, linIdx, nxtIdx) == ENDFILE_CHAR) {
            isEnd = true;
            t = UNDEFINED;
            break;
        }
        else {
            //#########################################
            if(linIdx + 1 < input.GetVecSize()) {
                if(input.Next(i, linIdx, nxtIdx) == '\n') {
                    ss << input.Next(i, linIdx, nxtIdx);
                    linIdx++;
                    nxtIdx = 0;
                    i = 0;
                }
                else {
                    ss << input.Next(i, linIdx, nxtIdx);
                    i++;
                }
            }
            else {
                if(input.Next(i, linIdx, nxtIdx) == '\n') {
                    isEnd = true;
                    t = UNDEFINED;
                }
                else {
                    ss << input.Next(i, linIdx, nxtIdx);
                    i++;
                }
            }

            // ################################################
        //   if(input.Next(i, linIdx, nxtIdx) == '\n') {
        //     ss << input.Next(i, linIdx, nxtIdx);
        //     linIdx++;
        //     nxtIdx = 0;
        //     i = 0;
        //   }
        //   else {
        //     ss << input.Next(i, linIdx, nxtIdx);
        //     i++;
        //   }
        }
    }
    return ss.str();
}

void Lexer::UndefinedMachine(char ch) {
    std::stringstream ss;
    // This machine handles anything not already handled
    switch(ch) {
        case '.':
        case ',':
        case '?':
        case '(':
        case ')':
        case '#':
        case '\'':
        case '*':
        case '+':
        case ':':
        case '-':
        case '\n':
        //case '|':
        case ' ':
            return;
        // case '\n':
        //     NewLineHandler();
        //     return;
        default:
            if(isalpha(ch)) {
                return;
            }
            else {
                ss << input.Current();
                currentStr = ss.str();
                TokenHandler(UNDEFINED);
                return;
            }
    }
}

void Lexer::WhitespaceMachine(char ch) {
    // This machines has only two state
    std::stringstream ss;
    if(isspace(ch)) {
        // >O ' ' -> 0
        currentStr = " ";
        return;
        // ss << input.Current();
        // currentStr = ss.str();
        //Token tok(WHITESPACE, "", input.GetCurrentLine());
    }
}

void Lexer::NewLineHandler() {
    if(input.GetCurrentLine() < input.GetVecSize()) {
        input.AdvanceBy(1);
        return;
    }
    else {
        isEndOfFile = true;
    }
}
