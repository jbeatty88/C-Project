#include "Relation.h"

using namespace std;

Relation::Relation() {
    // this->name = "";
    // this->header = {};
    // this->rows = {};
}

Relation::Relation(string n, set<string> header) {
    this->name = n;
    // this->schema = header;
    // this->rows = {};
}

Relation::Relation(string n, Header h) {
    this->name = n;
    this->header = h;
    // this->rows = {};
}

Relation::~Relation() {}

void Relation::AddRow(Row r) { this->rows.insert(r); }

string Relation::ToString() {
    stringstream ss;
    size_t y = 0;
    for(Row r: rows) {
        y = 0;
        while(y < r.size()){
            if(y < r.size() - 1) 
                ss << "  " <<  header.at(y) << "=" << r.at(y) << ", ";
            else 
                ss << "  " <<  header.at(y) << "=" << r.at(y);
            y++;
        }
        ss << endl;
    }
    return ss.str();
}

void Relation::PrintRows() {
    for(Row r: rows) {
        cout << r.ToString();
    }
}

void Relation::PrintHeader() {
    cout << header.ToString();
}

void Relation::PrintName() {
    cout <<  this->name << endl;
}

size_t Relation::GetRowCount() { return this->rows.size(); }

void Relation::SetRelName(string n) { this->name = n; }

void Relation::SetHeader(Header h) { this->header = h; }

void Relation::SetRows(set<Row> r) {this->rows = r; }

Relation Relation::Select(string val, size_t col) {
    // Our new relation will be a subset of name and schemes
    Relation newRel = Relation(this->name, this->header);
    // For each row in our set of rows
    for(const Row& r : this->rows) {
        string curr = r.at(col);
        if(curr == val)
            // If we have a match, add it to the new relation
            newRel.AddRow(r);
    }
    // Return a new relation
    return newRel;
}

Relation Relation::Select(size_t col1, size_t col2) {
    // The resulting relation is a subset of our schemes
    Relation newRel = Relation(this->name, this->header);
    // For each row in our set of rows
    for(const Row& r : this->rows) {
        // Select the values at the indexes given as parameter
        string val1 = r.at(col1);
        string val2 = r.at(col2);
        // If they match, add them to the new relation
        if(val1 == val2)
            newRel.AddRow(r);
    }
    // return a new relation
    return newRel;
}

Relation Relation::Project(vector<size_t> cols) {
    Relation newRel = Relation();
    newRel.SetRelName(this->name);
    Header oldHeader = this->header;
    Header newHeader = Header();
    Row newRow = Row();
    size_t newColNum = cols.size();

    // Get the cols that to project
    for(size_t i = 0; i < newColNum; i++) {
        size_t colIdx = cols.at(i);
        string colName = oldHeader.at(colIdx);
        // Push it to your Header
        newHeader.push_back(colName);
    }
    // If you have multiple cols, make new rows
    for(const Row& r: this->rows) {
        newRow = {};
        for(size_t i = 0; i < newColNum; i++) {
            size_t colIdx = cols.at(i);
            newRow.push_back(r.at(colIdx));
        }
        // Add the Row
        newRel.AddRow(newRow);
    }
    newRel.SetHeader(newHeader);
    // newRel.name = newHeader.ToString();
    // Return the new realtion
    return newRel;
}

Relation Relation::Rename(Header head) {
    // Rename the output relation and change attributes(schemes)
    Relation newRel = Relation(this->name, this->header);
    newRel.SetHeader(head);
    newRel.SetRows(this->rows);
    // Return a new relation
    return newRel;
}

void Relation::Unionize(Relation& ruleEvalRelation) {
    for(Row row : ruleEvalRelation.rows) {
        // Check if tuple from rule eval already exists
        // If it doesn't already exists
        if(this->IsDuplicateRow(row) == false) {
            // Print it out
            cout << this->RowStringer(row);
            // Add it to DB Relation
            this->AddRow(row);
        }
    }
}

bool Relation::IsDuplicateRow(Row r) {
    if( this->rows.insert(r).second) 
        return false;
    else 
        return true;
}

string Relation::RowStringer(Row& row) {
    std::stringstream ss;
    size_t numCol = row.size();
    vector<string> headers = this->header;
    
    ss << "  ";
    for(size_t i = 0; i < numCol; i++) {
        if(i < numCol - 1) {
            ss << headers.at(i) << "=" << row.at(i) << ", ";
        }
        else {
            ss << headers.at(i) << "=" << row.at(i);
        }
    }
    ss << "\n";
    return ss.str();
}

Relation Relation::Join(Relation& relA, Relation& relB) {
    Relation newRel = Relation();

    Header newHead = this->CombineSchemes(relA.header, relB.header); // Combine the Headers to cread a new head
    newRel.SetHeader(newHead); // Set the header for the new relation

    // Iterate through the rows of both relations
    for( Row r1 : relA.rows) {
        for (Row r2 : relB.rows) {
            // Check if they are joinable rows
            if(this->IsJoinable(r1, r2, relA.header, relB.header)) {
                // If they are joinable, combine them
                Row newRow = this->CombineTuples(r1, r2, relA.header, relB.header);
                // Add new row to the new relation
                newRel.AddRow(newRow);
            }
        }
    }
    return newRel;
}

Header Relation::CombineSchemes(Header& hA, Header& hB) {
    Header hAHeader = hA;
    Header hBHeader = hB;
    Header newHead = hAHeader; // Keep everything all cols from first relation

    // How many Columns are there
    size_t hANumCol = hAHeader.size(); 
    size_t hBNumCol = hBHeader.size();

    // Loop through and check if any cols match
    for(size_t i = 0; i < hBNumCol; i++) {
        bool isUnique = true;
        string headVal = hBHeader.at(i);
        for(size_t j = 0; j < hANumCol; j++) {
            if(hAHeader.at(j) == headVal) {
                isUnique = false;
            }
        }
        if(isUnique) {
            newHead.push_back(headVal);
        }
    }
    return newHead;
}

bool Relation::IsJoinable(Row& rowA, Row& rowB, Header& headA, Header& headB) {
    // get the sizes of the headers
    size_t headAColNum = headA.size();
    size_t headBColNum = headB.size();

    // Iterate through the header attributes
    for(size_t i = 0; i < headAColNum; i++) {
        string headAVal = headA.at(i);
        string rowAVal = rowA.at(i);
        for(size_t j = 0; j < headBColNum; j++) {
            string headBVal = headB.at(j);
            string rowBVal = rowB.at(j);
            // Compare the attributres
            if(headAVal == headBVal) {
                // Compare the row values
                if(rowAVal != rowBVal) {
                    // If not equal, it is not joinable
                    return false;
                }
            }
        }
    }
    return true;
}

Row Relation::CombineTuples(Row& rowA, Row& rowB, Header& headA, Header& headB) {
    Row newRow = rowA;
    size_t rowBSize = rowB.size();

    // Iterate through one of the relations rows to be combines
    for(size_t i = 0; i < rowBSize; i++) {
        // Get the value to compare
        string val = rowB.at(i);
        // Get the attribute to compare
        string headBAttrib = headB.at(i);
        // Check if the attribute is different
        if(IsDiffAttr(headA, headBAttrib)) {
            // If it is different, you can add it. 
            newRow.push_back(val);
        }
    }
    return newRow;
}

bool Relation::IsDiffAttr(Header h, string attr) {
    // Iterate through all of the header attributes
    for(string attributesColA : h) {
        // If any of them match
        if(attributesColA == attr) {
            return false;
        }
    }
    return true;
}
