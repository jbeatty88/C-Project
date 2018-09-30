#pragma once

#include<iostream>
#include<fstream>
#include<vector>

class InputStream {
    private:
        bool isEnd;
        size_t currentIdx;
        size_t currentLine;
        std::vector<std::string> inVec;
        std::string file;
        friend class Lexer;

    public:
        InputStream(std::string fileName);
        ~InputStream();
        char Current();
        char NextLine();
        char Next(size_t n = 1);
        char Before(size_t n = 1);
        bool IsEnd();
        size_t GetCurrentIdx();
        size_t GetCurrentLine();
        size_t GetCurrentLength();
        size_t GetVecSize();
        void MakeVector(std::string fileName);
        void AdvanceBy(size_t a = 1);
        void PrintVector();
        
};