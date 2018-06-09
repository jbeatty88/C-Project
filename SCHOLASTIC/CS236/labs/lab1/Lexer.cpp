#include "Lexer.h"

Lexer::Lexer(std::string fileName) : input(fileName){}

Lexer::~Lexer(){}

void Lexer::tokenize()
{
	while (input.now() != '\0') {
		defType = UNDEFINED;
		defStr = "";
		char c = input.now();
		readSingleChar(c);
		readColonDash();
		readKeyword(c);
		readId(c);
		readString(c);
		readComment(c);
		readWhitespace(c);
		readNone(c);

		pushOn(defType, defStr, input.getCurrentLine());
		input.advanceBy(defStr.length());
	}
	pushOn(ENDOFILE, "", input.getCurrentLine());
}


void Lexer::readSingleChar(char c)
{
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
		tmpType = WHITESPACE; //FIXME: This needs to catch \n not WHITESPACE, this is just a temp fix
		break;
	}

	setDefTypeStr(tmpStr, tmpType);
}

void Lexer::readColonDash()
{
	if (tmpStr == ":")
	{
		if (input.lookAhead(1) == '-')
		{
			tmpStr = ":-";
			tmpType = COLON_DASH;
		}
	}
	setDefTypeStr(tmpStr, tmpType);
}

void Lexer::readKeyword(char c)
{
	std::string keyword = "";
	switch (c) {
	case 'S': {
		keyword = "Schemes";
		tmpType = SCHEMES;
	}
			  break;
	case 'F': {
		keyword = "Facts";
		tmpType = FACTS;
	}
			  break;
	case 'R': {
		keyword = "Rules";
		tmpType = RULES;
	}
			  break;
	case 'Q': {
		keyword = "Queries";
		tmpType = QUERIES;
	}
			  break;
	}
	for (unsigned int i = 0; i < keyword.length(); i++) {
		if ((input.lookAhead(i)) == keyword[i]) {
			tmpStr += keyword[i];
		}
		else {
			keyword = "";
			tmpStr = "";
		}
	}
	setDefTypeStr(tmpStr, tmpType);
}

void Lexer::readId(char c)
{
	if (isalpha(c)) {
		// string temp_id_string;
		// temp_id_string += c;
		tmpStr = c;
		int i = 1;
		while (isalnum(input.lookAhead(i))) {
			tmpStr += input.lookAhead(i);
			i++;
		}
		tmpType = ID;
		setDefTypeStr(tmpStr, tmpType);
	}
}

void Lexer::readString(char c)
{
	if (c == '\'') {
		tmpStr = c;
		bool endofstring = false;
		int i = 1;
		while (!endofstring) {
			if ((input.lookAhead(i) == '\'') && (input.lookAhead(i + 1) != '\'')) {
				tmpStr += '\'';
				endofstring = true;
				tmpType = STRING;
			}
			else if ((input.lookAhead(i) == '\'') && (input.lookAhead(i + 1) == '\''))
			{
				tmpStr += '\'';
				tmpStr += '\'';
				i += 2;
			}
			else {
				if (input.lookAhead(i) != '\0') {
					tmpStr += input.lookAhead(i);
					i++;
				}
				else {
					tmpType = UNDEFINED;
					endofstring = true;
					setDefTypeStr(tmpStr, tmpType);
					return;
				}
			}
		}
	}
	setDefTypeStr(tmpStr, STRING);
}

void Lexer::readComment(char c)
{
	if (c == '#') {
		tmpStr = c;
		int i = 1;
		bool multiline = false;
		bool endofcomment = false;
		if (input.lookAhead(1) == '|') {
			multiline = true;
			tmpStr += '|';
			i++;
		}
		if (!multiline) {
			while (!endofcomment) {
				if ((input.lookAhead(i) == '\n') || (input.lookAhead(i) == '\0')) {
					endofcomment = true;
				}
				else {
					tmpStr += input.lookAhead(i);
					i++;
				}
			}
			// temp_token_type = COMMENT;
		}
		else {
			while (!endofcomment) {
				if ((input.lookAhead(i) == '|') && (input.lookAhead(i + 1) == '#')) {
					endofcomment = true;
					tmpStr += "|#";
				}
				else if (input.lookAhead(i) == '\0') {
					endofcomment = true;
					tmpType = UNDEFINED;
					setDefTypeStr(tmpStr, tmpType);
					return;
				}
				else {
					tmpStr += input.lookAhead(i);
					i++;
				}
			}
		}
		tmpType = COMMENT;
	}
	setDefTypeStr(tmpStr, tmpType);
}

void Lexer::readWhitespace(char c)
{
	if (isspace(c)) {
		tmpStr = c;
		setDefTypeStr(tmpStr, WHITESPACE);
	}
}

void Lexer::readNone(char c)
{
	tmpStr = c;
	tmpType = UNDEFINED;
	setDefTypeStr(tmpStr, tmpType);
}

void Lexer::pushOn(TokenType tt, std::string v, int ln)
{
	if (tt != WHITESPACE) {
		Token newToken(tt, v, ln);
		tokens.push_back(newToken);
	}
}

void Lexer::setDefTypeStr(std::string s, TokenType t)
{
	if (tmpStr.length() > defStr.length()) {
		defStr = tmpStr;
		defType = tmpType;
	}
}

void Lexer::printV()
{
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		std::cout << tokens[i].toString() << std::endl;
	}
	std::cout << "Total Tokens = " << tokens.size();
	std::cout << std::endl;
}
