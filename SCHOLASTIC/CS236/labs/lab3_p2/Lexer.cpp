#include "Lexer.h"

Lexer::Lexer(std::string fileName) : input(fileName){
	Automata();
}

Lexer::~Lexer(){}

void Lexer::Automata() {
	while (input.Current() != '\0') {
		defaultType = UNDEFINED;
		defaultStr = "";
		char c = input.Current();
		CharMachine(c);
		ColonMachine();
		KeywordMachine(c);
		IDMachine(c);
		StringMachine(c);
		CommentMachine(c);
		WhitespaceMachine(c);
		UndefinedMachine(c);
		
		if(defaultType != COMMENT) 
			MakeTokenVec(defaultType, defaultStr, input.GetCurrentLine() + 1);
		// MakeTokenVec(defaultType, defaultStr, input.GetCurrentLine() + 1);
		input.AdvanceBy(defaultStr.length());
	}
	MakeTokenVec(ENDOFILE, "", input.GetCurrentLine() + 1);
}

// void Lexer::UnderTheHood(std::string prevCode) {
//     // Strictly for personal debugging purposes
//     std::cout << "\n\033[1;4;31mVALUES AFTER: \033[m" << "\033[1m" <<  prevCode << "\033[0m";

//     //std::cout << "\n\033[1;36mCURRENT STRING: \033[0m" << "\033[1;7m" << currentStr << "\033[0m";
//     //std::cout << "\n\033[1;32mLINE LENGTH: \033[0m " << "\033[1;7m" << input.GetCurrentLength() << "\033[0m";
//     std::cout << "\n\033[1;32mLINE: \033[0m" << "\033[1;7m" << input.GetCurrentLine() << "\033[0m";

//     std::cout << "\n\033[1;32mCURRENT INDEX: \033[0m" << "\033[1;7m" << input.GetCurrentIdx() << "\033[0m";
//     std::cout << "\n\033[1;36mCURRENT VALUE: \033[0m " << "\033[1;7m" << input.Current() << "\033[0m";

//     std::cout << "\n\033[1;36mNEXT VALUE: \033[0m " << "\033[1;7m" << input.Next(1) << "\033[0m";
//     //std::cout << "\n\033[1;32mVEC SIZE: \033[0m " << "\033[1;7m" << input.GetVecSize() << "\033[0m" << "\n\n";

// }

void Lexer::CharMachine(char c) {
	// Each of these can be thought of as simple 2 state FSA's
    // >O ch-> 0
	tmpStr = c;

	switch (c) {
	case '.':
	  tmpType = PERIOD;
	  break;
	case ',':
	  tmpType = COMMA;
	  break;
	case '?':
	  tmpType = Q_MARK;
	  break;
	case '(':
	  tmpType = LEFT_PAREN;
	  break;
	case ')':
	  tmpType = RIGHT_PAREN;
	  break;
	case ':':
	  tmpType = COLON;
	  break;
	case '*':
	  tmpType = MULTIPLY;
	  break;
	case '+':
	  tmpType = ADD;
	  break;
	default:
	  tmpStr = "";
		tmpType = WHITESPACE;
		break;
	}

	SetDefaults(tmpStr, tmpType);
}

void Lexer::ColonMachine() {
	// This machine has two accept states
	// Accept Case 1: >O ':'-> 0
	if (tmpStr == ":") {
		// Accept Case 2: >O ':'-> '-' -> 0
		if (input.Next(1) == '-') {
			tmpStr = ":-";
			tmpType = COLON_DASH;
		}
	}
	SetDefaults(tmpStr, tmpType);
}

void Lexer::KeywordMachine(char c) {
	// This machine has 4 accept states
	std::string keyword = "";
	switch (c) {
	// Accept Case 1: >O 'S'-> 'c' -> 'h' -> 'e' -> 'm' -> 'e' -> 's' -> 0
	case 'S': {
		keyword = "Schemes";
		tmpType = SCHEMES;
	}
			  break;
	// Accept Case 2: >O 'F'-> 'a' -> 'c' -> 't' -> 's' -> 0
	case 'F': {
		keyword = "Facts";
		tmpType = FACTS;
	}
			  break;
	// Accept Case 3: >O 'R'-> 'u' -> 'l' -> 'e' -> 's' -> 0
	case 'R': {
		keyword = "Rules";
		tmpType = RULES;
	}
			  break;
	// Accept Case 4: >O 'Q'-> 'u' -> 'e' -> 'r' -> 'i' -> 'e' -> 's' -> 0
	case 'Q': {
		keyword = "Queries";
		tmpType = QUERIES;
	}
			  break;
	}
    // This handles the accept state: if -> 0 -> E (Sink state for non-keyword)
	for (size_t i = 0; i < keyword.length(); i++) {
		if ((input.Next(i)) == keyword[i])
			tmpStr += keyword[i];
		else {
			keyword = "";
			tmpStr = "";
		}
	}
	SetDefaults(tmpStr, tmpType);
}

void Lexer::IDMachine(char c) {
	if (isalpha(c)) {
		// This machine has 3 states (unless you count the keyword sink states)
		tmpStr = c;
		size_t i = 1;
		while (isalnum(input.Next(i))) {
			// Transition state: O [a-zA-Z0-9] <@- ^[a-zA-Z0-9] -> 0 (State transitions to itself for any alnum)
			tmpStr += input.Next(i);
			i++;
		}
		tmpType = ID;
		SetDefaults(tmpStr, tmpType);
	}
}

void Lexer::StringMachine(char c) {
	// Start State: >O '\''->
	if (c == '\'') {
		tmpStr = c;
		bool endofstring = false;
		size_t i = 1;
		// Transition states: O ^['\''] <@ (Transitions back to itself)
		while (!endofstring) {
			// Accept State: '\'' -> 0
			if ((input.Next(i) == '\'') && (input.Next(i + 1) != '\'')) {
				tmpStr += '\'';
				endofstring = true;
				tmpType = STRING;
			}
			else if ((input.Next(i) == '\'') && (input.Next(i + 1) == '\'')) {
				tmpStr += '\'';
				tmpStr += '\'';
				i += 2;
			}
			else {
				if (input.Next(i) != '\0') {
					tmpStr += input.Next(i);
					i++;
				}
				else {
					tmpType = UNDEFINED;
					endofstring = true;
					SetDefaults(tmpStr, tmpType);
					return;
				}
			}
		}
	}
	SetDefaults(tmpStr, STRING);
}

void Lexer::CommentMachine(char c) {
	// This machine has 2 separate branches that lead to accept states
	if (c == '#') {
		// Start State: >O '#' -> O
		tmpStr = c;
		size_t i = 1;
		bool multiLineComment = false;
		bool isEnd = false;
		if (input.Next(1) == '|') {
			// '|' -> O ^(['|']['#']) <@ ['|'] -> O ['#'] -> 0
			multiLineComment = true;
			tmpStr += '|';
			i++;
		}
		if (!multiLineComment) {
			while (!isEnd) {
				if ((input.Next(i) == '\n') || (input.Next(i) == '\0'))
					isEnd = true;
				else {
					tmpStr += input.Next(i);
					i++;
				}
			}
			// temp_token_type = COMMENT;
		}
		else {
			// -> O ^ ['\n'] <@ ['\n'] -> 0
			while (!isEnd) {
				if ((input.Next(i) == '|') && (input.Next(i + 1) == '#')) {
					isEnd = true;
					tmpStr += "|#";
				}
				else if (input.Next(i) == '\0') {
					isEnd = true;
					tmpType = UNDEFINED;
					SetDefaults(tmpStr, tmpType);
					return;
				}
				else {
					tmpStr += input.Next(i);
					i++;
				}
			}
		}
		tmpType = COMMENT;
	}
	SetDefaults(tmpStr, tmpType);
}

// void MultiLineCommentHandler() {}

void Lexer::WhitespaceMachine(char c) {
	// This machine handles whitespace not already handled
	if (isspace(c)) {
		tmpStr = c;
		SetDefaults(tmpStr, WHITESPACE);
	}
}

void Lexer::UndefinedMachine(char c) {
	// This machine handles anything not already handled
	tmpStr = c;
	tmpType = UNDEFINED;
	SetDefaults(tmpStr, tmpType);
}

void Lexer::MakeTokenVec(TokenType tt, std::string v, size_t ln) {
	if (tt != WHITESPACE) {
		Token newToken(tt, v, ln);
		tokens.push_back(newToken);
	}
}

void Lexer::SetDefaults(std::string s, TokenType t) {
	if (tmpStr.length() > defaultStr.length()) {
		defaultStr = tmpStr;
		defaultType = tmpType;
	}
}

void Lexer::PrintVec() {
	for (size_t i = 0; i < tokens.size(); i++) {
		std::cout << tokens[i].ToString() << std::endl;
	}
	std::cout << "Total Tokens = " << tokens.size();
	std::cout << std::endl;
}

std::vector<Token> Lexer::GetTokenVec() { return tokens; }

