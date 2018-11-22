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