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
        //UnderTheHood("End of While Loop", "AdvanceBy");
    };
    Token tok(ENDOFILE, "", input.GetCurrentLine() + 1);
    tokenVec.push_back(tok);
    std::cout << "Total Tokens = " <<  tokenVec.size() << std::endl;
}

void Lexer::Advancer() {
    if(input.GetCurrentLine() == input.GetVecSize()) { // If last line
            // if((input.GetCurrentLength() - currentStr.length()) >= 1 ) {
            if((input.GetCurrentIdx() + currentStr.length()) < input.GetCurrentLength()) {
                input.AdvanceBy(currentStr.length());
            }
            else {
                isEndOfFile = true;
            }
        }
        else {
            input.AdvanceBy(currentStr.length());
        }
}

bool Lexer::IsEndOfFile() {
    if(input.GetCurrentLine() == input.GetVecSize())
        return true;
    else
        return false;
}

void Lexer::UnderTheHood(std::string nextCode, std::string prevCode) {
    std::cout << "\nVALUES AFTER: " << prevCode << " && ";
    std::cout << "VALUES BEFORE: " << nextCode << std::endl;
    std::cout << "CURRENT LINE: [ " << input.GetCurrentLine() << " ]\n";
    std::cout << "CURRENT IDX: [ " << input.GetCurrentIdx() << " ]\n";
    std::cout << "CURRENT VALUE: [ " << input.Current() << " ]\n";
    std::cout << "NEXT VALUE: [ " << input.Next() << " ]\n\n";
}
void Lexer::CharMachine(char ch) {
    // Each of these can be thought of as simple 2 state FSA's
    switch(ch) {
    case ',':
        TokenVec(COMMA);
        break;
    case '.':
        TokenVec(PERIOD);
        break;
    case '?':
        TokenVec(Q_MARK);
        break;
    case '(':
        TokenVec(LEFT_PAREN);
        break;
    case ')':
        TokenVec(RIGHT_PAREN);
        break;
    case ':':
        ColonMachine();
        break;
    case '*':
        TokenVec(MULTIPLY);
        break;
    case '+':
        TokenVec(ADD);
        break;
    default:
        //Whitespace
        break;
    }
}

void Lexer::TokenVec(TokenType t) {
    std::stringstream ss;
    ss << input.Current();
    currentStr = ss.str();
    Token tok(t, currentStr, input.GetCurrentLine());
    tokenVec.push_back(tok);
    return;
}

void Lexer::ColonMachine() {
    std::stringstream ss;
    if(input.Next() == '-') {
        ss << input.Current() << input.Next();
        currentStr = ss.str();
        Token tok(COLON_DASH, currentStr, input.GetCurrentLine());
        tokenVec.push_back(tok);
    }
    else {
        ss << input.Current();
        currentStr = ss.str();
        Token tok(COLON, currentStr, input.GetCurrentLine());
        tokenVec.push_back(tok);
    }
    return;
}

void Lexer::KeywordMachine(char ch) {
    TokenType type;
    std::string str;
    switch(ch) {
        case 'S':
            str = "Schemes";
            type = SCHEMES;
            break;
        case 'F':
            str = "Facts";
            type = FACTS;
            break;
        case 'R':
            str = "Rules";
            type = RULES;
            break;
        case 'Q':
            str = "Queries";
            type = QUERIES;
            break;
        default:
            return;
    }
    currentStr = KeywordCheck(str);
    // std::cout << "CURRENT STR: " << currentStr << std::endl;
    // std::cout << "AFTER KEYWORD: " << input.Next(currentStr.length()) << std::endl;
    if(!isalnum(input.Next(currentStr.length())) && !isalnum(input.Before()) && currentStr.size() >= 5) {
        Token tok(type, currentStr, input.GetCurrentLine());
        tokenVec.push_back(tok);
        return;
    }
}

std::string Lexer::KeywordCheck(std::string keyword) {
    std::stringstream ss;
    bool isKeyword = false;
    for(size_t i = 0; i < keyword.length(); i++) {
        if(input.Next(i) == keyword[i]) {
            ss << input.Next(i);
        }
    }
    //std::cout << "STRING IS: " << ss.str() << std::endl;
    return ss.str();
}

void Lexer::IDMachine(char ch) {
    std::stringstream ss;
    if(isalpha(ch)) {
        size_t i(0);
        while(isalnum(input.Next(i))) {
            ss << input.Next(i);
            i++;
        }
        if(IsNotKeyword(ss.str())) {
            currentStr = ss.str();
            Token tok(ID, currentStr, input.GetCurrentLine());
            tokenVec.push_back(tok);  
        }        
    }
}

bool Lexer::IsNotKeyword(std::string idStr) {
    if(idStr != "Schemes" && idStr != "Facts" && idStr != "Rules" && idStr != "Queries")
        return true;
    else
        return false;
}

void Lexer::StringMachine(char ch) {
    std::stringstream ss;
    bool atEnd = false;
    t = STRING;
    size_t i(1);
    switch(ch) {
        // Start State
        case '\'':  
        {
            ss << '\'';
            // Middle State with the loop
            currentStr = GetString();
            // Accept State
            Token tok(t, currentStr, input.GetCurrentLine());
            tokenVec.push_back(tok);
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
     while(!isEnd) {
         if(input.Next(i) == '\'' && input.Next(i + 1) != '\'') {
             isEnd = true;
             ss << '\'';
         }
         else if(input.Next(i) == '\'' && input.Next(i + 1) == '\'') {
             ss << '\'' << '\'';
             i += 2;
         }
         else {
             if(input.Next(i) != ENDFILE_CHAR) {
                ss << input.Next(i);
                i++; 
             }
             else {
                 isEnd = true;
                 isUndefined = true;
             }
         }
     }
     if(!isUndefined) 
         return ss.str();
     else {
         t = UNDEFINED;
         return ss.str();
     }
}

void Lexer::UndefinedCase(std::string str) {
    currentStr = str;
    Token tok(UNDEFINED, currentStr, input.GetCurrentLine());
    tokenVec.push_back(tok);
    return;
}

void Lexer::CommentMachine(char ch) {
    std::stringstream ss;
    t = COMMENT;
    size_t commentLine = input.GetCurrentLine();
    switch(ch) {
        case '#': {
            if(input.Next() == '|')
                currentStr = GetBlockComment();
            else
                currentStr = GetSingleLineComment();

            Token tok(t, currentStr, commentLine);
            tokenVec.push_back(tok);
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
    while(!isEnd) {
        if(input.Next(i) == NEWLINE_CHAR || input.Next(i) == ENDFILE_CHAR) {
            isEnd = true;
        }
        else {
            ss << input.Next(i);
            i++;
        }
    }
    return ss.str();
}

std::string Lexer::GetBlockComment() {
    std::stringstream ss;
    isEnd = false;
    bool isUndefined = false;
    size_t i(1);
    ss << '#';
    while(!isEnd) {
        if(input.Next(i) == '|' && input.Next(i + 1) == '#') {
            isEnd = true;
            ss << '|' << '#';
        }
        else if(input.Next(i) == ENDFILE_CHAR) {
            isUndefined = true;
            isEnd = true;
            t = UNDEFINED;
        }
        else {
            ss << input.Next(i);
            i++;
        }
    }
    return ss.str();
}

void Lexer::UndefinedMachine(char ch) {
    std::stringstream ss;
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
        case '|':
        case ' ':
            return;
        default:
            if(isalnum(ch)) {
                return;
            }
            else {
                ss << input.Current();
                currentStr = ss.str();
                Token tok(UNDEFINED, currentStr, input.GetCurrentLine());
                tokenVec.push_back(tok);
                return;
            }
    }
}

void Lexer::WhitespaceMachine(char ch) {
    std::stringstream ss;
    if(isspace(ch)) {
        ss << input.Current();
        currentStr = ss.str();
        //Token tok(WHITESPACE, "", input.GetCurrentLine());
    }
}

