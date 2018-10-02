#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "InputStream.h"
#include "Token.h"

class Lexer {
    private:
        const char ENDFILE_CHAR = '\0';
        const char NEWLINE_CHAR = '\n';
        bool isEnd = false;
        bool isEndOfFile = false;
        std::string currentStr;
        std::string fileName;
        std::vector<Token> tokenVec;
        InputStream input;
        TokenType t;
    public:
        Lexer(std::string fileName);
        ~Lexer();
        void Automata();
        void ColonMachine();
        void Advancer();
        void UnderTheHood(std::string prevCode);
        void CharMachine(char ch);
        void KeywordMachine(char ch);
        void IDMachine(char ch);
        void StringMachine(char ch);
        void CommentMachine(char ch);
        void WhitespaceMachine(char ch);
        void UndefinedMachine(char ch);
        void SingleCharStr(TokenType t);
        void TokenHandler(TokenType t);
        bool IsNotKeyword(std::string idStr);
        std::string GetString();
        std::string GetSingleLineComment();
        std::string GetBlockComment();
        std::string KeywordCheck(std::string keyword);
        
};