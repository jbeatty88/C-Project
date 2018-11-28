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
        // std::cout << tmpDLog.ToString();
    } catch(Token error) {
        // std::cout << "\033[1;31mFailure! \033[m\n";
        // std::cout << "    \033[1;41m" << currentToken.ToString() << "\033[m\n";
        std::cout << "Failure!\n";
        std::cout << "  " << currentToken.ToString() << "\n";
    } 
}

void Parser::ParseScheme() {
    //scheme -> ID LEFT_PAREN ID idList RIGHT_PAREN
    tmpPred = Predicate(currentToken.GetTokenVal());
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    if(currentToken.GetTokenType() == ID)
        tmpPred.PushParam(Parameter("ID", currentToken.GetTokenVal(), false)); 
    IsMatch(ID);
    if(currentToken.GetTokenType() == COMMA)
        ParseIDList();
    IsMatch(RIGHT_PAREN);
    tmpDLog.PushScheme(tmpPred);
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
    if(currentToken.GetTokenType() == ID)
        tmpPred.PushParam(Parameter("ID", currentToken.GetTokenVal(), false));
    IsMatch(ID);
    if(currentToken.GetTokenType() == COMMA)
        ParseIDList();
}

void Parser::ParseFact() {
    //fact -> ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
    tmpPred = Predicate(currentToken.GetTokenVal());
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    if(currentToken.GetTokenType() == STRING)
        tmpPred.PushParam(Parameter("STRING", currentToken.GetTokenVal(), true));
    IsMatch(STRING);
    if(currentToken.GetTokenType() == COMMA)
        ParseStringList();
    IsMatch(RIGHT_PAREN);
    IsMatch(PERIOD);
    tmpDLog.PushFact(tmpPred);
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
    tmpRule = Rule(tmpPred);
    IsMatch(COLON_DASH);
    ParsePredicate();
    if(currentToken.GetTokenType() == COMMA)
        ParsePredicateList();
    IsMatch(PERIOD);
    tmpDLog.PushRule(tmpRule);
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
    tmpPred = Predicate(currentToken.GetTokenVal());
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    if(currentToken.GetTokenType() == ID)
        tmpPred.PushParam(Parameter("ID", currentToken.GetTokenVal(), false));
    IsMatch(ID);
    if(currentToken.GetTokenType() == COMMA)
        ParseIDList();
    IsMatch(RIGHT_PAREN);
}

void Parser::ParsePredicate() {
    //predicate	-> ID LEFT_PAREN parameter parameterList RIGHT_PAREN
    tmpPred = Predicate(currentToken.GetTokenVal());
    IsMatch(ID);
    IsMatch(LEFT_PAREN);
    ParseParameter();
    if(currentToken.GetTokenType() == COMMA)
        ParseParameterList();
    IsMatch(RIGHT_PAREN);
    tmpRule.PushPred(tmpPred); // WATCH HERE!!
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
    if(currentToken.GetTokenType() == STRING) {
        tmpPred.PushParam(Parameter("STRING", currentToken.GetTokenVal(), true));
        IsMatch(currentToken.GetTokenType());
    }
    else if(currentToken.GetTokenType() == ID) {
        tmpPred.PushParam(Parameter("ID", currentToken.GetTokenVal(), false));
        IsMatch(currentToken.GetTokenType());
    }
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
    std::stringstream ss;

    ss << currentToken.GetTokenVal();
    IsMatch(LEFT_PAREN);
    ss << ParseExpressionParameter();
    ss << ParseOperator();
    ss << ParseExpressionParameter();
    ss << currentToken.GetTokenVal();
    IsMatch(RIGHT_PAREN);
    tmpPred.PushParam(Parameter("EXPRESSION", ss.str(), true));
}

std::string Parser::ParseExpressionParameter() {
    std::string param;
    if(currentToken.GetTokenType() == STRING) {
        param = currentToken.GetTokenVal();
        IsMatch(currentToken.GetTokenType());
        return param;
    }
    else if(currentToken.GetTokenType() == ID) {
        param = currentToken.GetTokenVal();
        IsMatch(currentToken.GetTokenType());
        return param;
    }
    else if(currentToken.GetTokenType() == LEFT_PAREN)
        ParseExpression();
    else {
        return ")";
    }
    return "";
}
std::string Parser::ParseOperator() {
    //operator -> ADD | MULTIPLY
    if(currentToken.GetTokenType() == ADD) {
        // tmpPred.PushParam(Parameter("OPERATOR", currentToken.GetTokenVal()));
        IsMatch(ADD);
        return "+";
    }
    else if(currentToken.GetTokenType() == MULTIPLY) {
        // tmpPred.PushParam(Parameter("OPERATOR", currentToken.GetTokenVal()));
        IsMatch(MULTIPLY);
        return "*";
    }
    else{
        return "";
    }
}

void Parser::ParseQuery() {
    //query -> predicate Q_MARK
    tmpPred = Predicate(currentToken.GetTokenVal());
    ParsePredicate();
    IsMatch(Q_MARK);
    tmpDLog.PushQuery(tmpPred);
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
    if(currentToken.GetTokenType() == STRING)
        tmpPred.PushParam(Parameter("STRING", currentToken.GetTokenVal(), true));
    IsMatch(STRING);
    if(currentToken.GetTokenType() == COMMA)
        ParseStringList();
}

DatalogProgram Parser::GetDatalogProgram() { return tmpDLog; }