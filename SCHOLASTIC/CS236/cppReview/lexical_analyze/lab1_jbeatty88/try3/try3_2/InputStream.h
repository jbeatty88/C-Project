#pragma once

#include<iostream>
#include<fstream>
#include<vector>

class InputStream {
    private:
        bool isEnd = false;
        size_t currentIdx = 0;
        size_t currentLine = 0;
        size_t tmpLineIncr = 0;
        size_t tmpIdxIncr = 0;
        std::vector<std::string> inVec;
        std::string file;
        //friend class Lexer;

    public:
        InputStream(std::string fileName);
        ~InputStream();
        char Current();
        char NextLine(size_t nLines = 1);
        char Next(size_t n = 1, size_t line = 0, size_t idx = 0);
        char Before(size_t backIdx = 1);
        bool IsEnd();
        size_t GetCurrentIdx();
        size_t GetCurrentLine();
        size_t GetCurrentLength();
        size_t GetVecSize();
        void MakeVector(std::string fileName);
        void AdvanceBy(size_t a = 1);
        void PrintVector();
        void SetCurrentPos(size_t line = 0, size_t idx = 0);
        void SetCurrentIdx(size_t n = 0);
        std::string GetLineString(size_t nLine = 0);

};
