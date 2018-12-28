#include "Interpreter.h"

using namespace std;

Interpreter::Interpreter() {}

Interpreter::Interpreter(DatalogProgram dp) {
    this->datProg = dp;
    this->sVec = datProg.schemesPredVec;
    this->fVec = datProg.factsPredVec;
    this->qVec = datProg.queriesPredVec;
    this->rVec = datProg.rulesPredVec;
    this->projCol = {};
    this->oldVars = {};
    this->qVals = {};
    this->db = Database();
    this->newHead = Header();
    MakeRelation();
    EvaluateRules();
    AllQueryEval();
}

Interpreter::~Interpreter() {}

string Interpreter::GetName(size_t n) {
    string name = this->sVec[n].id;
    size_t vSize = this->sVec.size();
    if(vSize < n)
        return "NONE";
    else
        return name;
}

vector<Relation> Interpreter::MakeRelation() {
    string relationName;
    Header relationHeader = Header();
    Relation theRelation = Relation();
    vector<Relation> relations;
    Row relationRows = Row();

    // Iterate through our Schemes
    for(size_t i = 0; i < this->sVec.size(); i++) {
        // Get the name of our Relation
        relationName = this->sVec[i].id;
        // Iterate through our Header Values
        for(size_t j = 0; j < this->sVec[i].paramVec.size(); j++) {
            // Get each of the header values
            string currVal = this->sVec[i].paramVec[j].value;
            // Add them to our Header object
            relationHeader.push_back(currVal);
        }
        // Create a Relation with the Schemes Name and with our Header
        theRelation = Relation(relationName, relationHeader);
        // Add to our collection of relations to add to the DB
        relations.push_back(theRelation);
        // Clear our header P-FIX: make local
        relationHeader.clear();
    }
    // Finish making each relation of names and header into a table
    relations = MakeRow(relations);
    // Make a database obj
    // this->db = Database();
    // Iterate through our collection of now complete Relation(tables)
    for(size_t k = 0; k < relations.size(); k++) {
        // Add them into our database accessible by name of relation
        this->db.insert(pair<string, Relation>(relations[k].name, relations[k]));
    }
    // Return a collection of relations
    return relations;
}

vector<Relation> Interpreter::MakeRow(vector<Relation> r) {
    string nameChk;
    Row row = Row();
    // Iterate through the collection of Relations
    for(size_t i = 0; i < r.size(); i++) {
        // Get the name of the relation
        nameChk = r[i].name;
        // Iteratre through the collection of facts
        for(size_t j = 0; j < fVec.size(); j++) {
            // Get the name of the Relation that the facts correlate with
            string factName = this->fVec[j].id;
            // Compare with current relation to make sure the rows are added to the correct relation
            if(factName == nameChk) {
                // Get the size of the facts
                size_t vSize = this->fVec[j].paramVec.size();
                // Iterate through the facts
                for(size_t k = 0; k < vSize; k++) {
                    // Get the fact value
                    string currVal = this->fVec[j].paramVec[k].value;
                    // Add it to the Row
                    row.push_back(currVal);
                }
            }
            // Add the row to the Relation
            if(row.size() > 0) {
                r[i].AddRow(row);
            }
            // r[i].A ddRow(row);
            // Clear the row variable
            row.clear();
        }
    }
    return r;
}

void Interpreter::MakeDatabase(vector<Relation> r) {
    for(size_t i = 0; i < r.size(); i++)
        // Add each Relation from our collection to the DB
        this->db.insert(pair<string, Relation>(r[i].name, r[0]));
    
}

void Interpreter::AllQueryEval() {
    this->qVals.clear();
    // How many queries we have
    size_t qCount = this->qVec.size();
    // for(size_t i = 0; i < qCount; i++)
    //     this->qVals.push_back(qVec[i].id);
        
    // Iterate through all of the queries
    for(size_t i = 0; i < qCount; i++) {
        this->qVals.clear();
        for(size_t j = 0; j < qVec[i].paramVec.size(); j++) {
            this->qVals.push_back(qVec[i].paramVec[j].value);
        }
        // this->qVals.push_back(qVec[i].id);
        // Evaluate each query
        SingleQueryEval(qVec[i].id, i);
    }
}
Relation Interpreter::SingleQueryEval(string name, size_t idx) {
    // Copies the desired relation from the db
    try {
        Relation r = this->db.GetTable(name);
        this->projCol.clear();
        this->oldVars.clear();
        this->newHead.clear();
        // Relation r = this->db.GetTable(name);
        // Iterate through the current header to get all of the values
        for(size_t i = 0; i < r.header.size(); i++)
            // Copy the header values
            oldVars.push_back(r.header.at(i));
        
        // Perform constant select if needed
        this->ConstSelect(r);
        // Perform variable select if needed
        this->VarSelect(r);
        // Perform project **and rename** if needed
        this->Proj(r);

        // Add new Relation to DB  FIXME: This may only be necessary inside Project
        this->AddToDB(r);
        // Format results
        cout << this->Format(r, idx);
        // Return the Relation
        return r;
    }
    catch(...) {
        cout << "ERROR WITH RELATION:" << "\'" << name << "\'" <<  " IN DATABASE" << endl;
        return this->db.GetTable(name);
    }
}

void Interpreter::AddToDB(Relation& r) { this->db.insert(pair<string, Relation>(r.name, r)); }

string Interpreter::Format(Relation& r, size_t idx) {
    size_t numRows = r.GetRowCount();
    size_t newHeadSize = this->newHead.size();
    stringstream ss;
    set<Row> row = r.rows;

    // Format the Queries
    ss << this->qVec[idx].ToString();
    ss << "?";

    // If there were no results
    if(numRows <= 0) {
        // Output no
        ss << " No" << endl;
    }
    // If we had results
    else {
        // Output yes with the number of rows
        ss << " Yes(" << numRows << ")\n";
        // If we had any renames
        if(newHeadSize > 0) {
            // output with the new variables
            ss << r.ToString();
        }
    }
    // return a formatted string
    return ss.str();
}

void Interpreter::ConstSelect(Relation& r) {
    // size_t qCount = this->qVec[idx].paramVec.size();
    size_t qCount = this->qVals.size();
    // Iterate through the query values
    for(size_t i = 0; i < qCount; i++) {
        // Get the query value
        string currVal = this->qVals.at(i);
        // string currVal = this->qVec[idx].paramVec[i].value; 
        // Is it a constant
        // bool constant = this->qVec[idx].paramVec[i].isConstant;
        // If it is
        if(currVal.at(0) == '\'') {
            // Perform constant select
            r = r.Select(currVal, i);
        }
        // If it is not a constant
        else
            // Add it to the project queue
            this->ProjQueue(currVal, i);
    }
}

void Interpreter::ProjQueue(string vn, size_t col) {
    bool isDup = false;
    size_t varCount = this->newHead.size();

    // Iterate through our new head variables
    for(size_t i = 0; i < varCount; i++) {
        // get the value
        string headVal = this->newHead.at(i);
        // If value is already in the new head
        if(vn == headVal) {
            // Set the duplicate flag
            isDup = true;
        }
    }
    // If the diplicate flag is not set
    if(!isDup) {
        bool dupCol = false;
        // Add that col value to our col vector to Project
        for(size_t i = 0; i < projCol.size(); i++) {
            if(projCol.at(i) == col) {
                dupCol = true;
            }
        }
        if(!dupCol) {
            this->projCol.push_back(col);
        // Add the new variable value for the new head rename
            this->newHead.push_back(vn);
        }
        // this->projCol.push_back(col);
        // // Add the new variable value for the new head rename
        // this->newHead.push_back(vn);
    }
}
void Interpreter::RuleProjQueue(string vn, size_t col) {
    bool isDup = false;
    size_t varCount = this->newHead.size();

    // Iterate through our new head variables
    for(size_t i = 0; i < varCount; i++) {
        // get the value
        string headVal = this->newHead.at(i);
        // If value is already in the new head
        if(vn == headVal) {
            // Set the duplicate flag
            isDup = true;
        }
    }
    // If the diplicate flag is not set
    if(!isDup) {
        // Add that col value to our col vector to Project
        this->projCol.push_back(col);
        // Add the new variable value for the new head rename
        // this->newHead.push_back(vn);
    }
}

void Interpreter::VarSelect(Relation& r) {
    // size_t qCount = this->qVec[idx].paramVec.size();
    size_t qCount = this->qVals.size();
    // Iterate through the query values
    for(size_t i = 0; i < qCount; i++) {
        // Copy current value
        string var1 = this->qVals.at(i);
        // string var1 = this->qVec[idx].paramVec[i].value;
        // iterate through the rest of the query values
        for(size_t j = i + 1; j < qCount; j++) {
            // copy the other values for comparison
            string var2 = this->qVals.at(j);
            // string var2 = this->qVec[idx].paramVec[j].value;
            // If there is a match
            if(var1 == var2)
                // Perform a Select
                r = r.Select(i, j);
        }
    }

}

void Interpreter::Proj(Relation& r) {
    if(this->projCol.size() > 0) {
        // Project
        r = r.Project(this->projCol);
        // Rename
        r = r.Rename(this->newHead);
    }
}

void Interpreter::Join(Relation& r, vector<Relation>& rightHandRels) {
    size_t numRels = rightHandRels.size();
    for(size_t i = 1; i < numRels; i++) {
        if(i == 1)
            r = r.Join(rightHandRels.at(i - 1), rightHandRels.at(i));
        else
            r = r.Join(r, rightHandRels.at(i));
    }
}


void Interpreter::EvaluateRules() {
    size_t rCount = this->rVec.size();
    for(size_t x = 0; x <  rCount; x++) {
        Relation r;
        Relation leftRelFromDb = this->db.GetTable(this->rVec[x].pred.id);
        Header dbRelHeader = leftRelFromDb.header;
        
        leftRelFromDb = this->LeftHandEval(leftRelFromDb, x);
        // Evaluate predicates on the right-hand side of rule
        // this->newHead = (this->db.GetTable(this->rVec[x].pred.id).header);
        vector<Relation> rightHandPred = RightHandEval(x);

        // How many predicates were on the right side?
        size_t resultCount = rightHandPred.size();
        // If there were more than 1 predicates
        if(resultCount > 1)
        // Join the relations of that result
            this->Join(r, rightHandPred);
        else 
            r = rightHandPred.at(0);
        // Project cols that appear in head predicate
        // vector<size_t> headPredCols = {};
        vector<string> headPredVals = {};
        
        for(size_t i = 0; i < leftRelFromDb.header.size(); i++) {
            // headPredCols.push_back(i);
            headPredVals.push_back(leftRelFromDb.header.at(i));
        }
        // headPredCols = {1, 0};
        r = r.Project(headPredVals);
        // Rename relation to match schema of relation in DB
        r = r.Rename(dbRelHeader);
        // Union with relation in DB
        leftRelFromDb.header = dbRelHeader;
        leftRelFromDb.Unionize(r);
        

        map<string, Relation>::iterator itr = this->db.find(leftRelFromDb.name);
        this->db.erase(itr);
        this->db.insert(pair<string, Relation>(leftRelFromDb.name, leftRelFromDb));
    }
}

Relation Interpreter::LeftHandEval(Relation leftHand, size_t idx) {
    Header leftRuleHead = Header();
    Relation LeftRuleRel = Relation();
    LeftRuleRel = leftHand;
    for(size_t i = 0; i < this->rVec[idx].pred.paramVec.size(); i++) {
        leftRuleHead.push_back(this->rVec[idx].pred.paramVec[i].value);
    }
    LeftRuleRel.header = leftRuleHead;
    return LeftRuleRel;
}
vector<Relation> Interpreter::RightHandEval(size_t x) {
    std::vector<Relation> rightHandRels = {};
    vector<string> ruleVals = {};
    Relation newRel;

    size_t numRules = this-> rVec[x].predVec.size();
    // size_t numRules = this->rVec.size();

    for(size_t i = 0; i < numRules; i++) {
        this->projCol.clear();
        this->qVals.clear();
        this->newHead.clear();
        this->newVars.clear();
        ruleVals.clear();
        // this->oldVars.clear();
        for(size_t k = 0; k < rVec[x].predVec[i].paramVec.size(); k++) {
            ruleVals.push_back(this->rVec[x].predVec[i].paramVec[k].value);
        }
        newRel = this->db.GetTable(this->rVec[x].predVec[i].id);
        size_t numVals = ruleVals.size();
        this->qVals = ruleVals;
        for(size_t j = 0; j < numVals; j++) {
            this->ProjQueue(ruleVals.at(j), j);
        }

        this->newVars = ruleVals;
        // this->qVals = newVars;
        // this->newHead = newRel.header;
        this->ConstSelect(newRel);
        this->VarSelect(newRel);
        this->Proj(newRel);

        rightHandRels.push_back(newRel);
    }
    return rightHandRels;
}

ostream &operator<<(ostream &os, const Interpreter &s) {
    os << "Data Collected By Interpreter:" << endl;
    os << "     Vector of schemes: " << "Size: " << s.sVec.size() << endl;
    for(size_t x = 0; x < s.sVec.size(); x++) {
        os << "         NAME_" << x << ": ";
        os << s.sVec[x].id << endl;
        for(size_t y = 0; y < s.sVec[x].paramVec.size(); y++) {
            os << "             HEADER_" << y << ": ";
            os << s.sVec[x].paramVec[y].value << endl;
        }
    }
    os << endl;
    os << "   Database: " << endl;

    return os;
}

