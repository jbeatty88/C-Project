#include "Parser.h"

Parser::Parser(std::vector<Token> tokVec) { 
    this->tokens = tokVec;
    this->idx = 0;
    this->currentToken = tokens[idx]; 
    ParseDataLogProgram();
}

Parser::~Parser() {}

bool Parser::IsMatch(TokenType type) {
    if(type == currentToken.GetTokenType()) {
        idx++;
        currentToken = tokens[idx];
        return true;
    }
    else {
        throw currentToken;
        return false;
    }
}

Token Parser::GetToken(size_t i) { return tokens[i]; }

//TokenType Parser::GetTokenType() { return currentToken.GetTokenType(); }

// void Parser::Parse() { 
//     ParseDataLogProgram(); 
// }
   

void Parser::ParseDataLogProgram() {
    // datalogProgram -> SCHEMES COLON scheme schemelist FACTS COLON factList RULES COLON ruleList QUERIES COLON query queryList
    try {
        IsMatch(SCHEMES);
        IsMatch(COLON);
        ParseScheme();
        ParseSchemeList();
        IsMatch(FACTS);
        IsMatch(COLON);
        ParseFactList();
        IsMatch(RULES);
        IsMatch(COLON);
        ParseRuleList();
        IsMatch(QUERIES);
        IsMatch(COLON);
        ParseQuery();
        ParseQueryList();
        std::cout << "\033[1;32mSuccess! \033[m\n";
    } catch(Token error) {
        std::cout << "\033[1;31mFailure! \033[m\n";
        std::cout << "    \033[1;41m" << currentToken.ToString() << "\033[m\n";
    } 
}

void Parser::ParseScheme() {
    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    IsMatch(ID);
    if(currentToken.GetTokenType() == COMMA)
        ParseIDList();
    IsMatch(RIGHT_PAREN);
}

void Parser::ParseSchemeList() {
    //schemeList ->	scheme schemeList | lambda
    if(currentToken.GetTokenType() == ID)
        ParseScheme();
    if(currentToken.GetTokenType() == ID)
        ParseSchemeList();
}

void Parser::ParseIDList() {
    //idList ->	COMMA ID idList | lambda
    IsMatch(COMMA);
    IsMatch(ID);
    if(currentToken.GetTokenType() == COMMA)
        ParseIDList();
}

void Parser::ParseFact() {
    //fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    IsMatch(STRING);
    if(currentToken.GetTokenType() == COMMA)
        ParseStringList();
    IsMatch(RIGHT_PAREN);
    IsMatch(PERIOD);
}

void Parser::ParseFactList() {
    // factList	-> fact factList | lambda
    if(currentToken.GetTokenType() == ID) {
        ParseFact();
        if(currentToken.GetTokenType() == ID)
            ParseFactList();
    }
}

void Parser::ParseRule() {
    //rule -> headPredicate COLON_DASH predicate predicateList PERIOD
    ParseHeadPredicate();
    IsMatch(COLON_DASH);
    ParsePredicate();
    if(currentToken.GetTokenType() == COMMA)
        ParsePredicateList();
    IsMatch(PERIOD);
}

void Parser::ParseRuleList() {
    //ruleList -> rule ruleList | lambda
    if(currentToken.GetTokenType() == ID) {
        ParseRule();
        if(currentToken.GetTokenType() == ID)
            ParseRuleList();
    }
}

void Parser::ParseHeadPredicate() {
    //headPredicate	-> ID LEFT_PAREN ID idList RIGHT_PAREN
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    IsMatch(ID);
    if(currentToken.GetTokenType() == COMMA)
        ParseIDList();
    IsMatch(RIGHT_PAREN);
    
}

void Parser::ParsePredicate() {
    //predicate	-> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    ParseParameter();
    if(currentToken.GetTokenType() == COMMA)
        ParseParameterList();
    IsMatch(RIGHT_PAREN);
}

void Parser::ParsePredicateList() {
    //predicateList	-> COMMA predicate predicateList | lambda
    IsMatch(COMMA);
    ParsePredicate();
    if(currentToken.GetTokenType() == COMMA)
        ParsePredicateList();
}

void Parser::ParseParameter() {
    //parameter	-> STRING | ID | expression
    if(currentToken.GetTokenType() == STRING || currentToken.GetTokenType() == ID)
        IsMatch(currentToken.GetTokenType());
    if(currentToken.GetTokenType() == LEFT_PAREN)
        ParseExpression();
}

void Parser::ParseParameterList() {
    //parameterList	-> COMMA parameter parameterList | lambda
    IsMatch(COMMA);
    ParseParameter();
    if(currentToken.GetTokenType() == COMMA)
        ParseParameterList();
}

void Parser::ParseExpression() {
    //expression -> LEFT_PAREN parameter operator parameter RIGHT_PAREN
    IsMatch(LEFT_PAREN);
    ParseParameter();
    ParseOperator();
    ParseParameter();
    IsMatch(RIGHT_PAREN);
}

void Parser::ParseOperator() {
    //operator -> ADD | MULTIPLY
    if(currentToken.GetTokenType() == ADD)
        IsMatch(ADD);
    if(currentToken.GetTokenType() == MULTIPLY)
        IsMatch(MULTIPLY);
}

void Parser::ParseQuery() {
    //query -> predicate Q_MARK
    ParsePredicate();
    IsMatch(Q_MARK);
}

void Parser::ParseQueryList() {
    //queryList	-> query queryList | lambda
    if(currentToken.GetTokenType() == ENDOFILE)
        return;
    else {
        ParseQuery();
        if(currentToken.GetTokenType() == ID)
            ParseQueryList();  
    }
}

void Parser::ParseStringList() {
    //stringList ->	COMMA STRING stringList | lambda 
    IsMatch(COMMA);
    IsMatch(STRING);
    if(currentToken.GetTokenType() == COMMA)
        ParseStringList();
}