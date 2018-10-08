#pragma once
#include <vector>
#include <exception>
#include "Token.h"
#include "Parser.h"

class Tools {
    private:
    public:
        void CheckFor(Parser p, TokenType tt) {
            CheckType(p, tt);
            Advance();
        };
        
        void CheckType(Parser p, TokenType tt) {
            if(p.GetTokenType(p.GetToken(0)) != tt) {
                throw(std::exception) {
                    cout << "Expecting type of " + 
                }
            }
        }


};