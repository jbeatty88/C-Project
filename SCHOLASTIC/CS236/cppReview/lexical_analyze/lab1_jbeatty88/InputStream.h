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
        char NextLine(size_t nLines = 1);
        char Next(size_t onwardSpaces = 1);
        char Before(size_t backIdx = 1);
        bool IsEnd();
        size_t GetCurrentIdx();
        size_t GetCurrentLine();
        size_t GetCurrentLength();
        size_t GetVecSize();
        void MakeVector(std::string fileName);
        void AdvanceBy(size_t a = 1);
        void PrintVector();
        void SetCurrentPos(size_t line, size_t idx);
        void SetCurrentIdx(size_t n);
        std::string GetLineString(size_t nLine);
        
};