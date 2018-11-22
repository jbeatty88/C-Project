#include "Database.h"

using namespace std;

Database::Database() {}

Database::~Database() {}

Relation Database::GetTable(string tName) { return this->at(tName); }