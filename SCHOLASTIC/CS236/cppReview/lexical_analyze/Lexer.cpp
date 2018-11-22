#include "Lexer.h"

Lexer::Lexer(std::string fileName) : input(fileName) { 
    Automata(); 
}

Lexer::~Lexer() {}

void Lexer::Automata() {
    while(!isEndOfFile) {
        CharMachine(input.Current());
        CommentMachine(input.Current());
        StringMachine(input.Current());
        KeywordMachine(input.Current());
        IDMachine(input.Current());
        UndefinedMachine(input.Current());
        WhitespaceMachine(input.Current());
        Advancer();
        UnderTheHood("Advancer()");
    };
    Token tok(ENDOFILE, "", input.GetCurrentLine() + 1);
    tokenVec.push_back(tok);
    std::cout << "Total Tokens = " <<  tokenVec.size() << std::endl;
}

void Lexer::Advancer() {
    // If we're at the last line of the file
    if(input.GetCurrentLine() == input.GetVecSize()) { 
            // If we still have some stuff on the line
            if((input.GetCurrentIdx() + currentStr.length()) < input.GetCurrentLength())
                // advance onward 
                input.AdvanceBy(currentStr.length());
            else 
                // if we are at the end of the last line, it's over
                isEndOfFile = true;   
    }
    // If we are not at the last line of the file
    else 
        // advance onward
        input.AdvanceBy(currentStr.length()); 
}

void Lexer::UnderTheHood(std::string prevCode) {
    // Strictly for personal debugging purposes
    std::cout << "\n\033[1;4;31mVALUES AFTER: \033[m" << "\033[1m" <<  prevCode << "\033[0m";

    std::cout << "\n\033[1;36mCURRENT STRING: \033[0m" << "\033[1;7m" << currentStr << "\033[0m";
    std::cout << "\n\033[1;32mLINE LENGTH: \033[0m " << "\033[1;7m" << input.GetCurrentLength() << "\033[0m";
    std::cout << "\n\033[1;32mLINE: \033[0m" << "\033[1;7m" << input.GetCurrentLine() << "\033[0m";

    std::cout << "\n\033[1;32mCURRENT INDEX: \033[0m" << "\033[1;7m" << input.GetCurrentIdx() << "\033[0m";
    std::cout << "\n\033[1;36mCURRENT VALUE: \033[0m " << "\033[1;7m" << input.Current() << "\033[0m";
    
    std::cout << "\n\033[1;36mNEXT VALUE: \033[0m " << "\033[1;7m" << input.Next() << "\033[0m";
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
    std::stringstream ss;
    if(input.Next() == '-') {
        // Accept Case 1: >O ':'-> '-' -> 0
        ss << input.Current() << input.Next();
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
    TokenType type;
    std::string str;
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
    currentStr = KeywordCheck(str);

    // This handles the accept state: if -> 0 -> E (Sink state for non-keyword)
    if(!isalnum(input.Next(currentStr.length())) && !isalnum(input.Before()) && currentStr.size() >= 5) {
        TokenHandler(type);
        return;
    }
}

std::string Lexer::KeywordCheck(std::string keyword) {
    std::stringstream ss;
    // compare side by side the keyword and whatever is next in input
    for(size_t i = 0; i < keyword.length(); i++) {
        // while they are matching, string it
        if(input.Next(i) == keyword[i]) {
            ss << input.Next(i);
        }
    }
    // return the string
    return ss.str();
}

void Lexer::IDMachine(char ch) {
    std::stringstream ss;
    // This machine has 3 states (unless you count the keyword sink states)
    if(isalpha(ch)) {
        // >O [a-zA-Z] -> 
        size_t i(0);
        while(isalnum(input.Next(i))) {
            // Transition state: O [a-zA-Z0-9] <@- ^[a-zA-Z0-9] -> 0 (State transitions to itself for any alnum)
            ss << input.Next(i);
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
            //ss << '\'';
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
     size_t i(1);
     ss << '\'';
     // while we aren't to the end of our string
     while(!isEnd) {
         // if we have another single quote
         if(input.Next(i) == '\'' && input.Next(i + 1) != '\'') {
             // we're at the end
             isEnd = true;
             // string the final string symbol
             ss << '\'';
         }
         // if we have to consecutive single quotes
         else if(input.Next(i) == '\'' && input.Next(i + 1) == '\'') {
             // string them onto the string
             ss << '\'' << '\'';
             // skipt past them and continue reading the string
             i += 2;
         }
         // as long as we dont have a single quote or 2 single quotes
         else {
             // while we aren't to the end of the file
             if(input.Next(i) != ENDFILE_CHAR) {
                // continue string'n everything after the initial single quote
                ss << input.Next(i);
                i++; 
             }
             // if we don't find another single quote, then we have an incomplete string
             else {
                 isEnd = true;
                 isUndefined = true;
             }
         }
     }
     // if our string was flagged incomplete, our type is now UNDEFINED
     if(isUndefined) 
        t = UNDEFINED;
         
    return ss.str();
}

void Lexer::CommentMachine(char ch) {
    std::stringstream ss;
    // assume we have a comment
    t = COMMENT;
    std::string str;
    //size_t commentLine = input.GetCurrentLine();
    switch(ch) {
        // This machine has 2 separate branches that lead to accept states
        case '#': {
            // Start State: >O '#' -> O
            if(input.Next() == '|') {
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
    }
    return;
}

std::string Lexer::GetSingleLineComment() {
    std::stringstream ss;
    isEnd = false;
    size_t i(1);
    ss << '#';
    // as long we we're  not at the end
    while(!isEnd) {
        // if we are at the end of the line or end of file
        if(input.Next(i) == NEWLINE_CHAR || input.Next(i) == ENDFILE_CHAR)
            // break from the loop
            isEnd = true;
        
        // if we aren't to the end of the line
        else {
            // string eveything on the line
            ss << input.Next(i);
            i++;
        }
    }
    return ss.str();
}

std::string Lexer::GetBlockComment() {
    std::stringstream ss;
    isEnd = false;
    //size_t lineIncr(0);
    //size_t idxCount(0);
    size_t i(1);
    ss << '#';
    while(!isEnd) {
        if(input.Next(i) == '|' && input.Next(i + 1) == '#') {
            isEnd = true;
            ss << '|' << '#';
        }
        else if(input.Next(i) == ENDFILE_CHAR) {
            isEnd = true;
            t = UNDEFINED;
            break;
        }
        else {
            // std::cout << "\033[1;33mNext(" << i << "): " << input.Next(i) << "\033[0m\n";
            // if(input.GetLineString(lineIncr).length() <= idxCount) {
            //     lineIncr++;
            //     idxCount = 0;
            // }
            ss << input.Next(i);
            i++;
            //idxCount++;
        }
    }
   //input.SetCurrentPos(lineIncr, idxCount + 2);
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
        //case '|':
        case ' ':
            return;
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
        ss << input.Current();
        currentStr = ss.str();
        //Token tok(WHITESPACE, "", input.GetCurrentLine());
    }
}

