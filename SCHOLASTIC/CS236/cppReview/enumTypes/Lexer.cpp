#include "Lexer.h"
#include "Token.h"

Lexer::Lexer() { /*std::cout << "Creating LEXER object" << std::endl;*/ };
Lexer::~Lexer() { /*std::cout << "Deleting LEXER object" << std::endl;*/ };

void Lexer::PrintVec(std::vector<std::string> inVec){
  for(std::vector<std::string>::iterator it = inVec.begin(); it != inVec.end(); ++it)
    std::cout << ' ' << *it << std::endl;
}

void Lexer::MapVec(int vecSize, std::vector<std::string> inVec) {
  for(unsigned int i = 0; i != vecSize; i++) {
    for(unsigned int y = 0; y != inVec[i].length(); y++) {
      if(inVec[i][y] == ',') {                     
	Token tok(inVec[i][y], i + 1, COMMA);                                    
	tokenVec.push_back(tok);
	tok.FormatCharPrint();
      }                 
      if(inVec[i][y] == '.') { 
	Token tok(inVec[i][y], i + 1, PERIOD);
	tokenVec.push_back(tok);
	tok.FormatCharPrint();
      }
      if(inVec[i][y] == '?') { 
	Token tok(inVec[i][y], i + 1, Q_MARK);
	tokenVec.push_back(tok);
	tok.FormatCharPrint();
      } 
      if(inVec[i][y] == '(') {
	Token tok(inVec[i][y], i + 1, LEFT_PAREN); 
	tokenVec.push_back(tok); 
	tok.FormatCharPrint(); 
      }   
      if(inVec[i][y] == ')') { 
	Token tok(inVec[i][y], i + 1, RIGHT_PAREN); 
	tokenVec.push_back(tok);
	tok.FormatCharPrint();
      }
      if(inVec[i][y] == ':') { 
	Token tok(inVec[i][y], i + 1, COLON); 
	tokenVec.push_back(tok); 
	tok.FormatCharPrint();
      }
    }
  }
}
