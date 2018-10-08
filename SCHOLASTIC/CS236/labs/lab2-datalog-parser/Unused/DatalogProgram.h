#pragma once

#include <string>
#include <vector>
#include "Token.h"
#include "Schemes.h"
#include "Facts.h"
#include "Rules.h"
#include "Queries.h"

/* datalogProgram	->	SCHEMES COLON scheme schemeList   FACTS COLON factList   RULES COLON ruleList   QUERIES COLON query queryList */

class DatalogProgram {
private:
    // Schemes schemes;
    // Facts facts;
    // Rules rules;
    // Queries queries;

public:
    DatalogProgram(std::vector<Token> tokVec);
    ~DatalogProgram();
    void Parse();

};
