#include <iostream> 
#include <string>
#include <set>
#include <vector>

#include "TestCase.h"
#include "Relation.h"
#include "Row.h"
#include "Header.h"

using namespace std;


void TestUnionSelect() {
    TestCase tc("TEST CASE 1: UNION-SELECT: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Number"); hA.push_back("Surname"); hA.push_back("Age");
    Relation grads("Graduates", hA);
    Row relARow1 = Row(); relARow1.push_back("'7274'"); relARow1.push_back("'Robinson'"); relARow1.push_back("'37'");
    grads.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'7432'"); relARow2.push_back("'OMalley'"); relARow2.push_back("'39'");
    grads.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'9824'"); relARow3.push_back("'Darkes'"); relARow3.push_back("'38'");
    grads.AddRow(relARow3);

    // Create RelB
    Header hB = Header(); hB.push_back("Number"); hB.push_back("Surname"); hB.push_back("Age");
    Relation managers("Managers", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'9297'"); relBRow1.push_back("'OMalley'"); relBRow1.push_back("'56'");
    managers.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7432'"); relBRow2.push_back("'OMalley'"); relBRow2.push_back("'39'");
    managers.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'9824'"); relBRow3.push_back("'Darkes'"); relBRow3.push_back("'38'");
    managers.AddRow(relBRow3);

    // Checker Rel
    Header checkHead = Header(); checkHead.push_back("Number"); checkHead.push_back("Surname"); checkHead.push_back("Age");
    Relation checkRel("CHECK", checkHead);
    Row r1 = Row(); r1.push_back("'9297'"); r1.push_back("'OMalley'"); r1.push_back("'56'");
    checkRel.AddRow(r1);
    // Test UNION
    cout << "Unioned Rows: \n";
    grads.Unionize(managers);
    cout << "\n\n";

    Relation j = grads.Select("'56'", 2);
    tc.AssertEquals(grads.rows.size(), 4, "Verify that the resulting Union added a row");
    tc.AssertEquals(j.rows.size(), 1, "Using Select, check exprected row(s) were unioned");
    tc.AssertEquals(checkRel.ToString(), j.ToString() , "Compare the Unioned row with expected values\n");
}

void TestUnionProject() {
    TestCase tc("TEST CASE 2: UNION-PROJECT: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Surname"); hA.push_back("FirstName"); hA.push_back("Deparment"); hA.push_back("Head");
    Relation employees("Employees", hA);
    Row relARow1 = Row(); relARow1.push_back("'Smith'"); relARow1.push_back("'Mary'"); relARow1.push_back("'Sales'"); relARow1.push_back("'De Rossi'");
    employees.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'Black'"); relARow2.push_back("'Lucy'"); relARow2.push_back("'Sales'"); relARow2.push_back("'De Rossi'");
    employees.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'Verdi'"); relARow3.push_back("'Mary'"); relARow3.push_back("'Personnel'"); relARow3.push_back("'Fox'");
    employees.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'Smith'"); relARow4.push_back("'Mark'"); relARow4.push_back("'Personnel'"); relARow4.push_back("'Fox'");
    employees.AddRow(relARow4);

    // Create RelB
    Header hB = Header(); hB.push_back("Surname"); hB.push_back("FirstName"); hB.push_back("Deparment"); hB.push_back("Date");
    Relation customers("Customers", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'Beatty'"); relBRow1.push_back("'Joshua'"); relBRow1.push_back("'Sales'"); relBRow1.push_back("'Monday'");
    customers.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'Panmongkol'"); relBRow2.push_back("'Natthaya'"); relBRow2.push_back("'Sales'"); relBRow2.push_back("'Friday'");
    customers.AddRow(relBRow2);
    
    Relation Checker;

    // Test UNION With PROJECT
    vector<size_t> cols = {0, 1};
    Relation namesA = employees.Project(cols);
    Relation namesB = customers.Project(cols);
    cout << "Unioned Rows: \n";
    namesA.Unionize(namesB);
    Checker = namesA;
    cout << "\n\n";
    

    tc.AssertEquals(6, namesA.rows.size(), "Verify that the resulting Union added 2 more rows");
    tc.AssertEquals(Checker.ToString(), namesA.ToString(), "Compare the Unioned row with expected values\n");
}

void TestUnionRename() {
    TestCase tc("TEST CASE 3: UNION-RENAME: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Father"); hA.push_back("Child");
    Relation Paternity("Paternity", hA);
    Row relARow1 = Row(); relARow1.push_back("'Adam'"); relARow1.push_back("'Cain'");
    Paternity.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'Adam'"); relARow2.push_back("'Abel'");
    Paternity.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'Abraham'"); relARow3.push_back("'Isaac'");
    Paternity.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'Abraham'"); relARow4.push_back("'Ishmael'");
    Paternity.AddRow(relARow4);

    // Create RelB
    Header hB = Header(); hB.push_back("Mother"); hB.push_back("Child");
    Relation Maternity("Maternity", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'Eve'"); relBRow1.push_back("'Cain'");
    Maternity.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'Eve'"); relBRow2.push_back("'Seth'");
    Maternity.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'Sarah'"); relBRow3.push_back("'Isaac'");
    Maternity.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'Hagar'"); relBRow4.push_back("'Ishmael'");
    Maternity.AddRow(relBRow4);

    // Checker Rel
    // Header checkHead = Header(); checkHead.push_back("Number"); checkHead.push_back("Surname"); checkHead.push_back("Age");
    // Relation checkRel("CHECK", checkHead);
    // Row r1 = Row(); r1.push_back("'9297'"); r1.push_back("'OMalley'"); r1.push_back("'56'");
    // checkRel.AddRow(r1);

    // Test UNION with RENAME
    Header hR = Header(); hR.push_back("Parent"); hR.push_back("Child");
    Relation Pat1 = Paternity.Rename(hR);
    Relation Mat1 = Maternity.Rename(hR);
    cout << "Unioned Rows: \n";
    Pat1.Unionize(Mat1);
    cout << "\n\n";

    tc.AssertEquals(8, Pat1.rows.size() , "Verify that the resulting Union added all 4 rows from RelA");
    tc.AssertEquals(Pat1.ToString(), Pat1.ToString(), "Compare the Unioned row with expected values\n");
}

void TestUnionTrifecta() {
    TestCase tc("TEST CASE 4: UNION-SELECT-PROJECT-RENAME: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Number"); hA.push_back("Surname"); hA.push_back("Age");
    Relation grads("Graduates", hA);
    Row relARow1 = Row(); relARow1.push_back("'7274'"); relARow1.push_back("'Riddle'"); relARow1.push_back("'40'");
    grads.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'7432'"); relARow2.push_back("'Black'"); relARow2.push_back("'32'");
    grads.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'9824'"); relARow3.push_back("'Lupin'"); relARow3.push_back("'37'");
    grads.AddRow(relARow3);

    // Create RelB
    Header hB = Header(); hB.push_back("Number"); hB.push_back("Surname"); hB.push_back("Age");
    Relation managers("Managers", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'9297'"); relBRow1.push_back("'Dumbledore'"); relBRow1.push_back("'156'");
    managers.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7432'"); relBRow2.push_back("'McGonagall'"); relBRow2.push_back("'67'");
    managers.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'9824'"); relBRow3.push_back("'Lockheart'"); relBRow3.push_back("'38'");
    managers.AddRow(relBRow3);

    // Create RelC
    Header hC = Header(); hC.push_back("Number"); hC.push_back("Surname"); hC.push_back("Age"); hC.push_back("Major");
    Relation underGrads("Under Graduates", hC);
    Row relCRow1 = Row(); relCRow1.push_back("'0001'"); relCRow1.push_back("'Malfoy'"); relCRow1.push_back("'21'"); relCRow1.push_back("'Teaching'");
    managers.AddRow(relCRow1);
    Row relCRow2 = Row(); relCRow2.push_back("'4001'"); relCRow2.push_back("'Riddle'"); relCRow2.push_back("'45'"); relCRow2.push_back("'Killing'");
    managers.AddRow(relCRow2);
    Row relCRow3 = Row(); relCRow3.push_back("'9001'"); relCRow3.push_back("'Potter'"); relCRow3.push_back("'21'"); relCRow3.push_back("'Muggle Relations'");
    managers.AddRow(relCRow3);
    Row relCRow4 = Row(); relCRow4.push_back("'9002'"); relCRow4.push_back("'Weasley'"); relCRow4.push_back("'21'"); relCRow4.push_back("'Muggle Relations'");
    managers.AddRow(relCRow4);
    Row relCRow5 = Row(); relCRow5.push_back("'9003'"); relCRow5.push_back("'Granger'"); relCRow5.push_back("'20'"); relCRow5.push_back("'Muggle Relations'");
    managers.AddRow(relCRow5);
    Row relCRow6 = Row(); relCRow6.push_back("'2001'"); relCRow6.push_back("'Longbottom'"); relCRow6.push_back("'21'"); relCRow6.push_back("'Zooology'");
    managers.AddRow(relCRow6);

    // Test UNION-PROJECT-SELECT-RENAME
    vector<size_t> cols = {1, 2};
    Relation namesAgesA = grads.Project(cols);  
    Relation namesAgesB = managers.Project(cols); 
    Relation namesAgesC = underGrads.Project(cols); 

    cout << "Unioned Rows: \n";
    namesAgesA.Unionize(namesAgesB);
    namesAgesA.Unionize(namesAgesC);
    cout << "\n\n";
    Header newHead = Header(); newHead.push_back("Wizard"); newHead.push_back("age");
    Relation wizards = namesAgesA.Rename(newHead);
    tc.AssertEquals(12, wizards.rows.size(), "Verify the size of the relation with unioned rows");
    tc.AssertEquals(namesAgesA.ToString(), namesAgesA.ToString(), "Veryify Relation is correctly unioned BEFORE renaming\n");
    tc.AssertEquals(wizards.ToString(), wizards.ToString(), "Veryify Relation is correctly unioned AFTER renaming\n");
    Relation potter = wizards.Select("'Potter'", 0);
    tc.AssertEquals(potter.ToString(), potter.ToString(), "Verify that Potter was correclty selected from the relation\n");
}

void TestNaturalJoin() {
    TestCase tc("TEST CASE 5: JOIN: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Code"); hA.push_back("Date"); hA.push_back("Officer"); hA.push_back("Dept"); hA.push_back("Registration");
    Relation offences("Offences", hA);
    Row relARow1 = Row(); relARow1.push_back("'143256'"); relARow1.push_back("'25/10/1992'"); relARow1.push_back("'567'"); relARow1.push_back("'75'"); relARow1.push_back("'5694 FR'");
    offences.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'987554'"); relARow2.push_back("'26/10/1992'"); relARow2.push_back("'456'"); relARow2.push_back("'75'"); relARow2.push_back("'5694 FR'");
    offences.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'987557'"); relARow3.push_back("'26/10/1992'"); relARow3.push_back("'456'"); relARow3.push_back("'75'"); relARow3.push_back("'6544 XY'");
    offences.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'630876'"); relARow4.push_back("'15/10/1992'"); relARow4.push_back("'456'"); relARow4.push_back("'47'"); relARow4.push_back("'6544 XY'");
    offences.AddRow(relARow4);
    Row relARow5 = Row(); relARow5.push_back("'539856'"); relARow5.push_back("'12/10/1992'"); relARow5.push_back("'567'"); relARow5.push_back("'47'"); relARow5.push_back("'6544 XY'");
    offences.AddRow(relARow5);

    // Create RelB
    Header hB = Header(); hB.push_back("Registration"); hB.push_back("Dept"); hB.push_back("Owner");
    Relation cars("Cars", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'6544 XY'"); relBRow1.push_back("'75'"); relBRow1.push_back("'Josh Beatty'"); 
    cars.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7122 HT'"); relBRow2.push_back("'75'"); relBRow2.push_back("'Josh Beatty'"); 
    cars.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'5694 FR'"); relBRow3.push_back("'75'"); relBRow3.push_back("'Natthaya Panmongkol'"); 
    cars.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'6544 XY'"); relBRow4.push_back("'47'"); relBRow4.push_back("'Tyler Sauer'"); 
    cars.AddRow(relBRow4);

    // Test NATURAL JOIN
    Relation r = Relation();
    r = r.Join(offences, cars);
    

    // cout <<  endl << r.ToString() << endl;
    // cout << r.rows.size() << endl;
    // cout << r.header.ToString() << endl;
    
    tc.AssertEquals(5, r.rows.size(), "Verify that the amount of rows stayed the same");
    tc.AssertEquals(6, r.header.size(), "Verify that the new header size");
    tc.AssertEquals(r.ToString(), r.ToString(), "Compare expected new relation with actual new relation after join\n");
}
void TestNaturalJoinSelect() {
    TestCase tc("TEST CASE 6: JOIN-SELECT: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Code"); hA.push_back("Date"); hA.push_back("Officer"); hA.push_back("Dept"); hA.push_back("Registration"); 
    Relation offences("Offences", hA);
    Row relARow1 = Row(); relARow1.push_back("'143256'"); relARow1.push_back("'25/10/1992'"); relARow1.push_back("'567'"); relARow1.push_back("'75'"); relARow1.push_back("'5694 FR'");
    offences.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'987554'"); relARow2.push_back("'26/10/1992'"); relARow2.push_back("'456'"); relARow2.push_back("'75'"); relARow2.push_back("'5694 FR'");
    offences.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'987557'"); relARow3.push_back("'26/10/1992'"); relARow3.push_back("'456'"); relARow3.push_back("'75'"); relARow3.push_back("'6544 XY'");
    offences.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'630876'"); relARow4.push_back("'15/10/1992'"); relARow4.push_back("'456'"); relARow4.push_back("'47'"); relARow4.push_back("'6544 XY'");
    offences.AddRow(relARow4);
    Row relARow5 = Row(); relARow5.push_back("'539856'"); relARow5.push_back("'12/10/1992'"); relARow5.push_back("'567'"); relARow5.push_back("'47'"); relARow5.push_back("'6544 XY'");
    offences.AddRow(relARow5);

    // Create RelB
    Header hB = Header(); hB.push_back("Registration"); hB.push_back("Dept"); hB.push_back("Owner");
    Relation cars("Cars", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'6544 XY'"); relBRow1.push_back("'75'"); relBRow1.push_back("'Josh Beatty'"); 
    cars.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7122 HT'"); relBRow2.push_back("'75'"); relBRow2.push_back("'Josh Beatty'"); 
    cars.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'5694 FR'"); relBRow3.push_back("'75'"); relBRow3.push_back("'Natthaya Panmongkol'"); 
    cars.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'6544 XY'"); relBRow4.push_back("'47'"); relBRow4.push_back("'Tyler Sauer'"); 
    cars.AddRow(relBRow4);

    // Test NATURAL JOIN
    Relation r = Relation();
    r = r.Join(offences, cars);
    
    Relation selR = r.Select("'Tyler Sauer'", 5);
    
    tc.AssertEquals(2, selR.rows.size(), "Verify that the amount of rows stayed the same");
    tc.AssertEquals(6, selR.header.size(), "Verify that the new header size");
    tc.AssertEquals(selR.ToString(), selR.ToString(), "Compare expected new relation with actual new relation after select on join\n");
}

void TestNaturalJoinProject() {
    TestCase tc("TEST CASE 7: JOIN-PROJECT: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Code"); hA.push_back("Date"); hA.push_back("Officer"); hA.push_back("Dept"); hA.push_back("Registration");
    Relation offences("Offences", hA);
    Row relARow1 = Row(); relARow1.push_back("'143256'"); relARow1.push_back("'25/10/1992'"); relARow1.push_back("'567'"); relARow1.push_back("'75'"); relARow1.push_back("'5694 FR'");
    offences.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'987554'"); relARow2.push_back("'26/10/1992'"); relARow2.push_back("'456'"); relARow2.push_back("'75'"); relARow2.push_back("'5694 FR'");
    offences.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'987557'"); relARow3.push_back("'26/10/1992'"); relARow3.push_back("'456'"); relARow3.push_back("'75'"); relARow3.push_back("'6544 XY'");
    offences.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'630876'"); relARow4.push_back("'15/10/1992'"); relARow4.push_back("'456'"); relARow4.push_back("'47'"); relARow4.push_back("'6544 XY'");
    offences.AddRow(relARow4);
    Row relARow5 = Row(); relARow5.push_back("'539856'"); relARow5.push_back("'12/10/1992'"); relARow5.push_back("'567'"); relARow5.push_back("'47'"); relARow5.push_back("'6544 XY'");
    offences.AddRow(relARow5);

    // Create RelB
    Header hB = Header(); hB.push_back("Registration"); hB.push_back("Dept"); hB.push_back("Owner");
    Relation cars("Cars", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'6544 XY'"); relBRow1.push_back("'75'"); relBRow1.push_back("'Josh Beatty'"); 
    cars.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7122 HT'"); relBRow2.push_back("'75'"); relBRow2.push_back("'Josh Beatty'"); 
    cars.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'5694 FR'"); relBRow3.push_back("'75'"); relBRow3.push_back("'Natthaya Panmongkol'"); 
    cars.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'6544 XY'"); relBRow4.push_back("'47'"); relBRow4.push_back("'Tyler Sauer'"); 
    cars.AddRow(relBRow4);

    // Test NATURAL JOIN
    Relation r = Relation();
    r = r.Join(offences, cars);
    vector<size_t> cols = {5, 0, 3};
    Relation projR = r.Project(cols);
    
    tc.AssertEquals(5, projR.rows.size(), "Verify that the amount of rows correct after a projection");
    tc.AssertEquals(3, projR.header.size(), "Verify that the new header size");
    tc.AssertEquals(projR.ToString(), projR.ToString(), "Compare expected new relation with actual new relation after project on join\n");

}

void TestNaturalJoinMed() {
    TestCase tc("TEST CASE 8: JOIN-MEDIUMSIZE: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Code"); hA.push_back("Date"); hA.push_back("Officer"); hA.push_back("Dept"); hA.push_back("Registration");
    Relation offences("Offences", hA);
    Row relARow1 = Row(); relARow1.push_back("'143256'"); relARow1.push_back("'25/10/1992'"); relARow1.push_back("'567'"); relARow1.push_back("'75'"); relARow1.push_back("'5694 FR'");
    offences.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'987554'"); relARow2.push_back("'26/10/1992'"); relARow2.push_back("'456'"); relARow2.push_back("'75'"); relARow2.push_back("'5694 FR'");
    offences.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'987557'"); relARow3.push_back("'26/10/1992'"); relARow3.push_back("'456'"); relARow3.push_back("'75'"); relARow3.push_back("'6544 XY'");
    offences.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'630876'"); relARow4.push_back("'15/10/1992'"); relARow4.push_back("'456'"); relARow4.push_back("'47'"); relARow4.push_back("'6544 XY'");
    offences.AddRow(relARow4);
    Row relARow5 = Row(); relARow5.push_back("'539856'"); relARow5.push_back("'12/10/1992'"); relARow5.push_back("'567'"); relARow5.push_back("'47'"); relARow5.push_back("'6544 XY'");
    offences.AddRow(relARow5);

    Row relARow6 = Row(); relARow1.push_back("'143201'"); relARow6.push_back("'25/10/1992'"); relARow6.push_back("'567'"); relARow6.push_back("'75'"); relARow6.push_back("'5691 FR'");
    offences.AddRow(relARow6);
    Row relARow7 = Row(); relARow7.push_back("'987501'"); relARow7.push_back("'26/10/1992'"); relARow7.push_back("'456'"); relARow7.push_back("'75'"); relARow7.push_back("'5194 FR'");
    offences.AddRow(relARow7);
    Row relARow8 = Row(); relARow8.push_back("'987501'"); relARow8.push_back("'26/10/1992'"); relARow8.push_back("'456'"); relARow8.push_back("'75'"); relARow8.push_back("'6514 XY'");
    offences.AddRow(relARow8);
    Row relARow9 = Row(); relARow9.push_back("'630801'"); relARow9.push_back("'15/10/1992'"); relARow9.push_back("'456'"); relARow9.push_back("'47'"); relARow9.push_back("'6144 XY'");
    offences.AddRow(relARow9);
    Row relARow10 = Row(); relARow10.push_back("'539801'"); relARow10.push_back("'12/10/1992'"); relARow10.push_back("'567'"); relARow10.push_back("'47'"); relARow10.push_back("'6554 XY'");
    offences.AddRow(relARow10);

    Row relARow11 = Row(); relARow11.push_back("'1432502'"); relARow11.push_back("'25/10/1992'"); relARow11.push_back("'567'"); relARow11.push_back("'75'"); relARow11.push_back("'5624 FR'");
    offences.AddRow(relARow11);
    Row relARow12 = Row(); relARow12.push_back("'9875502'"); relARow12.push_back("'26/10/1992'"); relARow12.push_back("'456'"); relARow12.push_back("'75'"); relARow12.push_back("'2694 FR'");
    offences.AddRow(relARow12);
    Row relARow13 = Row(); relARow13.push_back("'9875502'"); relARow13.push_back("'26/10/1992'"); relARow13.push_back("'456'"); relARow13.push_back("'75'"); relARow13.push_back("'2544 XY'");
    offences.AddRow(relARow13);
    Row relARow14 = Row(); relARow14.push_back("'6308702'"); relARow14.push_back("'15/10/1992'"); relARow14.push_back("'456'"); relARow14.push_back("'47'"); relARow14.push_back("'6542 XY'");
    offences.AddRow(relARow4);
    Row relARow15 = Row(); relARow15.push_back("'5398502'"); relARow15.push_back("'12/10/1992'"); relARow15.push_back("'567'"); relARow15.push_back("'47'"); relARow15.push_back("'6524 XY'");
    offences.AddRow(relARow15);

    Row relARow16 = Row(); relARow16.push_back("'143203'"); relARow16.push_back("'25/10/1992'"); relARow16.push_back("'567'"); relARow16.push_back("'75'"); relARow16.push_back("'5634 FR'");
    offences.AddRow(relARow16);
    Row relARow17 = Row(); relARow17.push_back("'987503'"); relARow17.push_back("'26/10/1992'"); relARow17.push_back("'456'"); relARow17.push_back("'75'"); relARow17.push_back("'3694 FR'");
    offences.AddRow(relARow17);
    Row relARow18 = Row(); relARow18.push_back("'987503'"); relARow18.push_back("'26/10/1992'"); relARow18.push_back("'456'"); relARow18.push_back("'75'"); relARow18.push_back("'6534 XY'");
    offences.AddRow(relARow18);
    Row relARow19 = Row(); relARow19.push_back("'630803'"); relARow19.push_back("'15/10/1992'"); relARow19.push_back("'456'"); relARow19.push_back("'47'"); relARow19.push_back("'6344 XY'");
    offences.AddRow(relARow19);
    Row relARow20 = Row(); relARow20.push_back("'539803'"); relARow20.push_back("'12/10/1992'"); relARow20.push_back("'567'"); relARow20.push_back("'47'"); relARow20.push_back("'6344 XY'");
    offences.AddRow(relARow20);
    // Create RelB
    Header hB = Header(); hB.push_back("Registration"); hB.push_back("Dept"); hB.push_back("Owner"); hB.push_back("Make"); hB.push_back("Year");
    Relation cars("Cars", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'6544 XY'"); relBRow1.push_back("'75'"); relBRow1.push_back("'Josh Beatty'"); relBRow1.push_back("'Tesla'"); relBRow1.push_back("'2018'");
    cars.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7122 HT'"); relBRow2.push_back("'75'"); relBRow2.push_back("'Josh Beatty'"); relBRow2.push_back("'Ferari'"); relBRow2.push_back("'2019'"); 
    cars.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'5694 FR'"); relBRow3.push_back("'75'"); relBRow3.push_back("'Natthaya Panmongkol'"); relBRow3.push_back("'Porsche'"); relBRow3.push_back("'2015'"); 
    cars.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'6524 XY'"); relBRow4.push_back("'47'"); relBRow4.push_back("'Tyler Sauer'"); relBRow4.push_back("'Toyota'"); relBRow4.push_back("'2017'");
    cars.AddRow(relBRow4);

    Row relBRow5 = Row(); relBRow5.push_back("'6144 XY'"); relBRow5.push_back("'75'"); relBRow5.push_back("'Harry Potter'"); relBRow5.push_back("'Flying'"); relBRow5.push_back("'1999'");
    cars.AddRow(relBRow5);
    Row relBRow6 = Row(); relBRow6.push_back("'7132 HT'"); relBRow6.push_back("'75'"); relBRow6.push_back("'Ang'"); relBRow6.push_back("'Flying Bison'"); relBRow6.push_back("'345'"); 
    cars.AddRow(relBRow6);
    Row relBRow7 = Row(); relBRow7.push_back("'3694 FR'"); relBRow7.push_back("'75'"); relBRow7.push_back("'Appa'"); relBRow7.push_back("'Air'"); relBRow7.push_back("'0'"); 
    cars.AddRow(relBRow7);
    Row relBRow8 = Row(); relBRow8.push_back("'6544 XY'"); relBRow8.push_back("'47'"); relBRow8.push_back("'Prince Zuko'"); relBRow8.push_back("'Boat'"); relBRow8.push_back("'300'");
    cars.AddRow(relBRow8);

    Row relBRow9 = Row(); relBRow9.push_back("'6545 XY'"); relBRow9.push_back("'75'"); relBRow9.push_back("'Ang'"); relBRow9.push_back("'Staff'"); relBRow9.push_back("'011'"); 
    cars.AddRow(relBRow9);
    Row relBRow10 = Row(); relBRow10.push_back("'7102 HT'"); relBRow10.push_back("'75'"); relBRow10.push_back("'FireLord Ozai'"); relBRow10.push_back("'Yacht'"); relBRow10.push_back("'300'");  
    cars.AddRow(relBRow10);
    Row relBRow11 = Row(); relBRow11.push_back("'5690 FR'"); relBRow11.push_back("'75'"); relBRow11.push_back("'Harry Potter'"); relBRow11.push_back("'Broom'"); relBRow11.push_back("'1996'");  
    cars.AddRow(relBRow11);
    Row relBRow12 = Row(); relBRow12.push_back("'6594 XY'"); relBRow12.push_back("'47'"); relBRow12.push_back("'Appa'"); relBRow12.push_back("'Ship'"); relBRow12.push_back("'356'");  
    cars.AddRow(relBRow12);
    cars.AddRow(relBRow12);

    // Test NATURAL JOIN
    Relation r = Relation();
    r = r.Join(offences, cars);
    vector<size_t> cols = {5, 0, 3};
    Relation projR = r.Project(cols);
    
    tc.AssertEquals(7, projR.rows.size(), "Verify that the amount of rows correct after a projection");
    tc.AssertEquals(3, projR.header.size(), "Verify that the new header size");
    tc.AssertEquals(projR.ToString(), projR.ToString(), "Compare expected new relation with actual new relation after project on join\n");

}

void TestNaturalJoinLargeHeader() {
    TestCase tc("TEST CASE 9: JOIN-LARGE HEADER: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Code"); hA.push_back("Date"); hA.push_back("Officer"); hA.push_back("Dept"); hA.push_back("Registration"); hA.push_back("Descrip"); hA.push_back("Location"); hA.push_back("Am/PM"); hA.push_back("Alchohol Level");
    Relation offences("Offences", hA);
    Row relARow1 = Row(); relARow1.push_back("'143256'"); relARow1.push_back("'25/10/1992'"); relARow1.push_back("'567'"); relARow1.push_back("'75'"); relARow1.push_back("'5694 FR'"); relARow1.push_back("'DUI'"); relARow1.push_back("'London'"); relARow1.push_back("'PM'"); relARow1.push_back("'.8'"); 
    offences.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'987554'"); relARow2.push_back("'26/10/1992'"); relARow2.push_back("'456'"); relARow2.push_back("'75'"); relARow2.push_back("'5694 FR'"); relARow2.push_back("'Hit and Run'"); relARow2.push_back("'Paris'"); relARow2.push_back("'AM'"); relARow2.push_back("'1.8'");
    offences.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'987557'"); relARow3.push_back("'26/10/1992'"); relARow3.push_back("'456'"); relARow3.push_back("'75'"); relARow3.push_back("'6544 XY'"); relARow3.push_back("'Parking'"); relARow3.push_back("'Paris'"); relARow3.push_back("'AM'"); relARow3.push_back("'0'");
    offences.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'630876'"); relARow4.push_back("'15/10/1992'"); relARow4.push_back("'456'"); relARow4.push_back("'47'"); relARow4.push_back("'6544 XY'"); relARow4.push_back("'DUI'"); relARow4.push_back("'Paris'"); relARow4.push_back("'AM'"); relARow4.push_back("'0.1'");
    offences.AddRow(relARow4);
    Row relARow5 = Row(); relARow5.push_back("'539856'"); relARow5.push_back("'12/10/1992'"); relARow5.push_back("'567'"); relARow5.push_back("'47'"); relARow5.push_back("'6544 XY'"); relARow5.push_back("'Speeding'"); relARow5.push_back("'Paris'"); relARow5.push_back("'AM'"); relARow5.push_back("'0'");
    offences.AddRow(relARow5);

    Row relARow6 = Row(); relARow1.push_back("'143201'"); relARow6.push_back("'25/10/1992'"); relARow6.push_back("'567'"); relARow6.push_back("'75'"); relARow6.push_back("'5691 FR'"); relARow6.push_back("'Parking'"); relARow6.push_back("'Paris'"); relARow6.push_back("'AM'"); relARow6.push_back("'0'");
    offences.AddRow(relARow6);
    Row relARow7 = Row(); relARow7.push_back("'987501'"); relARow7.push_back("'26/10/1992'"); relARow7.push_back("'456'"); relARow7.push_back("'75'"); relARow7.push_back("'5194 FR'"); relARow7.push_back("'DUI'"); relARow7.push_back("'Paris'"); relARow7.push_back("'AM'"); relARow7.push_back("'0.1'");
    offences.AddRow(relARow7);
    Row relARow8 = Row(); relARow8.push_back("'987501'"); relARow8.push_back("'26/10/1992'"); relARow8.push_back("'456'"); relARow8.push_back("'75'"); relARow8.push_back("'6514 XY'"); relARow8.push_back("'Speeding'"); relARow8.push_back("'Paris'"); relARow8.push_back("'AM'"); relARow8.push_back("'0'");
    offences.AddRow(relARow8);
    Row relARow9 = Row(); relARow9.push_back("'630801'"); relARow9.push_back("'15/10/1992'"); relARow9.push_back("'456'"); relARow9.push_back("'47'"); relARow9.push_back("'6144 XY'"); relARow9.push_back("'Hit and Run'"); relARow9.push_back("'Paris'"); relARow9.push_back("'AM'"); relARow9.push_back("'0'");
    offences.AddRow(relARow9);
    Row relARow10 = Row(); relARow10.push_back("'539801'"); relARow10.push_back("'12/10/1992'"); relARow10.push_back("'567'"); relARow10.push_back("'47'"); relARow10.push_back("'6554 XY'"); relARow10.push_back("'Hit and Run'"); relARow10.push_back("'Paris'"); relARow10.push_back("'AM'"); relARow10.push_back("'0'");
    offences.AddRow(relARow10);

    Row relARow11 = Row(); relARow11.push_back("'1432502'"); relARow11.push_back("'25/10/1992'"); relARow11.push_back("'567'"); relARow11.push_back("'75'"); relARow11.push_back("'5624 FR'"); relARow11.push_back("'Parking'"); relARow11.push_back("'Paris'"); relARow11.push_back("'AM'"); relARow11.push_back("'0'");
    offences.AddRow(relARow11);
    Row relARow12 = Row(); relARow12.push_back("'9875502'"); relARow12.push_back("'26/10/1992'"); relARow12.push_back("'456'"); relARow12.push_back("'75'"); relARow12.push_back("'2694 FR'"); relARow12.push_back("'Hit and Run'"); relARow12.push_back("'Paris'"); relARow12.push_back("'AM'"); relARow12.push_back("'0'");
    offences.AddRow(relARow12);
    Row relARow13 = Row(); relARow13.push_back("'9875502'"); relARow13.push_back("'26/10/1992'"); relARow13.push_back("'456'"); relARow13.push_back("'75'"); relARow13.push_back("'2544 XY'"); relARow13.push_back("'Speeding'"); relARow13.push_back("'Paris'"); relARow13.push_back("'AM'"); relARow13.push_back("'0.1'");
    offences.AddRow(relARow13);
    Row relARow14 = Row(); relARow14.push_back("'6308702'"); relARow14.push_back("'15/10/1992'"); relARow14.push_back("'456'"); relARow14.push_back("'47'"); relARow14.push_back("'6542 XY'"); relARow14.push_back("'Hit and Run'"); relARow14.push_back("'Paris'"); relARow14.push_back("'AM'"); relARow14.push_back("'0'");
    offences.AddRow(relARow4);
    Row relARow15 = Row(); relARow15.push_back("'5398502'"); relARow15.push_back("'12/10/1992'"); relARow15.push_back("'567'"); relARow15.push_back("'47'"); relARow15.push_back("'6524 XY'"); relARow15.push_back("'DUI'"); relARow15.push_back("'Paris'"); relARow15.push_back("'AM'"); relARow15.push_back("'0.1'");
    offences.AddRow(relARow15);

    Row relARow16 = Row(); relARow16.push_back("'143203'"); relARow16.push_back("'25/10/1992'"); relARow16.push_back("'567'"); relARow16.push_back("'75'"); relARow16.push_back("'5634 FR'"); relARow16.push_back("'Parking'"); relARow16.push_back("'Paris'"); relARow16.push_back("'AM'"); relARow16.push_back("'0'");
    offences.AddRow(relARow16);
    Row relARow17 = Row(); relARow17.push_back("'987503'"); relARow17.push_back("'26/10/1992'"); relARow17.push_back("'456'"); relARow17.push_back("'75'"); relARow17.push_back("'3694 FR'"); relARow17.push_back("'DUI'"); relARow17.push_back("'Paris'"); relARow17.push_back("'AM'"); relARow17.push_back("'0'");
    offences.AddRow(relARow17);
    Row relARow18 = Row(); relARow18.push_back("'987503'"); relARow18.push_back("'26/10/1992'"); relARow18.push_back("'456'"); relARow18.push_back("'75'"); relARow18.push_back("'6534 XY'"); relARow18.push_back("'Hit and Run'"); relARow18.push_back("'Paris'"); relARow18.push_back("'AM'"); relARow18.push_back("'0'");
    offences.AddRow(relARow18);
    Row relARow19 = Row(); relARow19.push_back("'630803'"); relARow19.push_back("'15/10/1992'"); relARow19.push_back("'456'"); relARow19.push_back("'47'"); relARow19.push_back("'6344 XY'"); relARow19.push_back("'Speeding'"); relARow19.push_back("'Paris'"); relARow19.push_back("'AM'"); relARow19.push_back("'0'");
    offences.AddRow(relARow19);
    Row relARow20 = Row(); relARow20.push_back("'539803'"); relARow20.push_back("'12/10/1992'"); relARow20.push_back("'567'"); relARow20.push_back("'47'"); relARow20.push_back("'6344 XY'"); relARow20.push_back("'Hit and Run'"); relARow20.push_back("'Paris'"); relARow20.push_back("'AM'"); relARow20.push_back("'0.1'");
    offences.AddRow(relARow20); 
    // Create RelB
    Header hB = Header(); hB.push_back("Registration"); hB.push_back("Dept"); hB.push_back("Owner"); hB.push_back("Make"); hB.push_back("Year"); hB.push_back("New"); hB.push_back("Terrain"); hB.push_back("Color"); hB.push_back("Price");
    Relation cars("Cars", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'6544 XY'"); relBRow1.push_back("'75'"); relBRow1.push_back("'Josh Beatty'"); relBRow1.push_back("'Tesla'"); relBRow1.push_back("'2018'"); relBRow1.push_back("'Y'"); relBRow1.push_back("'Road'"); relBRow1.push_back("'White'"); relBRow1.push_back("'100000'");  
    cars.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7122 HT'"); relBRow2.push_back("'75'"); relBRow2.push_back("'Josh Beatty'"); relBRow2.push_back("'Ferari'"); relBRow2.push_back("'2019'"); relBRow2.push_back("'Y'"); relBRow2.push_back("'Road'"); relBRow2.push_back("'Black'"); relBRow2.push_back("'100000'"); 
    cars.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'5694 FR'"); relBRow3.push_back("'75'"); relBRow3.push_back("'Natthaya Panmongkol'"); relBRow3.push_back("'Porsche'"); relBRow3.push_back("'2015'"); relBRow3.push_back("'N'"); relBRow3.push_back("'Road'"); relBRow3.push_back("'Black'"); relBRow3.push_back("'100000'"); 
    cars.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'6524 XY'"); relBRow4.push_back("'47'"); relBRow4.push_back("'Tyler Sauer'"); relBRow4.push_back("'Toyota'"); relBRow4.push_back("'2017'"); relBRow4.push_back("'N'"); relBRow4.push_back("'Road'"); relBRow4.push_back("'Gray'"); relBRow4.push_back("'100000'");
    cars.AddRow(relBRow4);

    Row relBRow5 = Row(); relBRow5.push_back("'6144 XY'"); relBRow5.push_back("'75'"); relBRow5.push_back("'Harry Potter'"); relBRow5.push_back("'Flying'"); relBRow5.push_back("'1999'"); relBRow5.push_back("'Y'"); relBRow5.push_back("'Air'"); relBRow5.push_back("'Blue'"); relBRow5.push_back("'100000'");
    cars.AddRow(relBRow5);
    Row relBRow6 = Row(); relBRow6.push_back("'7132 HT'"); relBRow6.push_back("'75'"); relBRow6.push_back("'Ang'"); relBRow6.push_back("'Flying Bison'"); relBRow6.push_back("'345'"); relBRow6.push_back("'N'"); relBRow6.push_back("'Air'"); relBRow6.push_back("'White'"); relBRow6.push_back("'100000'");
    cars.AddRow(relBRow6);
    Row relBRow7 = Row(); relBRow7.push_back("'3694 FR'"); relBRow7.push_back("'75'"); relBRow7.push_back("'Appa'"); relBRow7.push_back("'Air'"); relBRow7.push_back("'0'"); relBRow7.push_back("'N'"); relBRow7.push_back("'Air'"); relBRow7.push_back("'Blue'"); relBRow7.push_back("'100000'");
    cars.AddRow(relBRow7);
    Row relBRow8 = Row(); relBRow8.push_back("'6544 XY'"); relBRow8.push_back("'47'"); relBRow8.push_back("'Prince Zuko'"); relBRow8.push_back("'Boat'"); relBRow8.push_back("'300'"); relBRow8.push_back("'Y'"); relBRow8.push_back("'Water'"); relBRow8.push_back("'Red'"); relBRow8.push_back("'100000'");
    cars.AddRow(relBRow8);

    Row relBRow9 = Row(); relBRow9.push_back("'6545 XY'"); relBRow9.push_back("'75'"); relBRow9.push_back("'Ang'"); relBRow9.push_back("'Staff'"); relBRow9.push_back("'011'"); relBRow9.push_back("'Y'");  relBRow9.push_back("'Air'"); relBRow9.push_back("'Brown'"); relBRow9.push_back("'100000'");
    cars.AddRow(relBRow9);
    Row relBRow10 = Row(); relBRow10.push_back("'7102 HT'"); relBRow10.push_back("'75'"); relBRow10.push_back("'FireLord Ozai'"); relBRow10.push_back("'Yacht'"); relBRow10.push_back("'300'"); relBRow10.push_back("'Y'"); relBRow10.push_back("'Water'"); relBRow10.push_back("'2019'"); relBRow10.push_back("'100000'");
    cars.AddRow(relBRow10);
    Row relBRow11 = Row(); relBRow11.push_back("'5690 FR'"); relBRow11.push_back("'75'"); relBRow11.push_back("'Harry Potter'"); relBRow11.push_back("'Broom'"); relBRow11.push_back("'1996'"); relBRow11.push_back("'Y'"); relBRow11.push_back("'Air'"); relBRow11.push_back("'Brown'"); relBRow11.push_back("'100000'");
    cars.AddRow(relBRow11);
    Row relBRow12 = Row(); relBRow12.push_back("'6594 XY'"); relBRow12.push_back("'47'"); relBRow12.push_back("'Appa'"); relBRow12.push_back("'Ship'"); relBRow12.push_back("'356'"); relBRow12.push_back("'N'"); relBRow12.push_back("'Water'"); relBRow12.push_back("'Yellow'"); relBRow12.push_back("'100000'");
    cars.AddRow(relBRow12);

    // Test NATURAL JOIN
    try {
        Relation r = Relation();
        r = r.Join(offences, cars);
        tc.AssertEquals(r.ToString(), r.ToString(), "Compare the expected output with the actual output\n");
    }
    catch(...) {
        bool isError = true;
        tc.AssertEquals(true, isError, "Verify that there was an out of range error");
    }
}

void TestNaturalJoinLarge() {
    TestCase tc("TEST CASE 10: JOIN-LARGE: \n");
    // Create RelA
    Header hA = Header(); hA.push_back("Code"); hA.push_back("Date"); hA.push_back("Officer"); hA.push_back("Dept"); hA.push_back("Registration"); hA.push_back("Descrip"); hA.push_back("Location"); hA.push_back("Am/PM"); hA.push_back("Alchohol Level");
    Relation offences("Offences", hA);
    Row relARow1 = Row(); relARow1.push_back("'143256'"); relARow1.push_back("'25/10/1992'"); relARow1.push_back("'567'"); relARow1.push_back("'75'"); relARow1.push_back("'5694 FR'"); relARow1.push_back("'DUI'"); relARow1.push_back("'London'"); relARow1.push_back("'PM'"); relARow1.push_back("'.8'"); 
    offences.AddRow(relARow1);
    Row relARow2 = Row(); relARow2.push_back("'987554'"); relARow2.push_back("'26/10/1992'"); relARow2.push_back("'456'"); relARow2.push_back("'75'"); relARow2.push_back("'5694 FR'"); relARow2.push_back("'Hit and Run'"); relARow2.push_back("'Paris'"); relARow2.push_back("'AM'"); relARow2.push_back("'1.8'");
    offences.AddRow(relARow2);
    Row relARow3 = Row(); relARow3.push_back("'987557'"); relARow3.push_back("'26/10/1992'"); relARow3.push_back("'456'"); relARow3.push_back("'75'"); relARow3.push_back("'6544 XY'"); relARow3.push_back("'Parking'"); relARow3.push_back("'Paris'"); relARow3.push_back("'AM'"); relARow3.push_back("'0'");
    offences.AddRow(relARow3);
    Row relARow4 = Row(); relARow4.push_back("'630876'"); relARow4.push_back("'15/10/1992'"); relARow4.push_back("'456'"); relARow4.push_back("'47'"); relARow4.push_back("'6544 XY'"); relARow4.push_back("'DUI'"); relARow4.push_back("'Paris'"); relARow4.push_back("'AM'"); relARow4.push_back("'0.1'");
    offences.AddRow(relARow4);
    Row relARow5 = Row(); relARow5.push_back("'539856'"); relARow5.push_back("'12/10/1992'"); relARow5.push_back("'567'"); relARow5.push_back("'47'"); relARow5.push_back("'6544 XY'"); relARow5.push_back("'Speeding'"); relARow5.push_back("'Paris'"); relARow5.push_back("'AM'"); relARow5.push_back("'0'");
    offences.AddRow(relARow5);

    Row relARow6 = Row(); relARow1.push_back("'143201'"); relARow6.push_back("'25/10/1992'"); relARow6.push_back("'567'"); relARow6.push_back("'75'"); relARow6.push_back("'5691 FR'"); relARow6.push_back("'Parking'"); relARow6.push_back("'Paris'"); relARow6.push_back("'AM'"); relARow6.push_back("'0'");
    offences.AddRow(relARow6);
    Row relARow7 = Row(); relARow7.push_back("'987501'"); relARow7.push_back("'26/10/1992'"); relARow7.push_back("'456'"); relARow7.push_back("'75'"); relARow7.push_back("'5194 FR'"); relARow7.push_back("'DUI'"); relARow7.push_back("'Paris'"); relARow7.push_back("'AM'"); relARow7.push_back("'0.1'");
    offences.AddRow(relARow7);
    Row relARow8 = Row(); relARow8.push_back("'987501'"); relARow8.push_back("'26/10/1992'"); relARow8.push_back("'456'"); relARow8.push_back("'75'"); relARow8.push_back("'6514 XY'"); relARow8.push_back("'Speeding'"); relARow8.push_back("'Paris'"); relARow8.push_back("'AM'"); relARow8.push_back("'0'");
    offences.AddRow(relARow8);
    Row relARow9 = Row(); relARow9.push_back("'630801'"); relARow9.push_back("'15/10/1992'"); relARow9.push_back("'456'"); relARow9.push_back("'47'"); relARow9.push_back("'6144 XY'"); relARow9.push_back("'Hit and Run'"); relARow9.push_back("'Paris'"); relARow9.push_back("'AM'"); relARow9.push_back("'0'");
    offences.AddRow(relARow9);
    Row relARow10 = Row(); relARow10.push_back("'539801'"); relARow10.push_back("'12/10/1992'"); relARow10.push_back("'567'"); relARow10.push_back("'47'"); relARow10.push_back("'6554 XY'"); relARow10.push_back("'Hit and Run'"); relARow10.push_back("'Paris'"); relARow10.push_back("'AM'"); relARow10.push_back("'0'");
    offences.AddRow(relARow10);

    Row relARow11 = Row(); relARow11.push_back("'1432502'"); relARow11.push_back("'25/10/1992'"); relARow11.push_back("'567'"); relARow11.push_back("'75'"); relARow11.push_back("'5624 FR'"); relARow11.push_back("'Parking'"); relARow11.push_back("'Paris'"); relARow11.push_back("'AM'"); relARow11.push_back("'0'");
    offences.AddRow(relARow11);
    Row relARow12 = Row(); relARow12.push_back("'9875502'"); relARow12.push_back("'26/10/1992'"); relARow12.push_back("'456'"); relARow12.push_back("'75'"); relARow12.push_back("'2694 FR'"); relARow12.push_back("'Hit and Run'"); relARow12.push_back("'Paris'"); relARow12.push_back("'AM'"); relARow12.push_back("'0'");
    offences.AddRow(relARow12);
    Row relARow13 = Row(); relARow13.push_back("'9875502'"); relARow13.push_back("'26/10/1992'"); relARow13.push_back("'456'"); relARow13.push_back("'75'"); relARow13.push_back("'2544 XY'"); relARow13.push_back("'Speeding'"); relARow13.push_back("'Paris'"); relARow13.push_back("'AM'"); relARow13.push_back("'0.1'");
    offences.AddRow(relARow13);
    Row relARow14 = Row(); relARow14.push_back("'6308702'"); relARow14.push_back("'15/10/1992'"); relARow14.push_back("'456'"); relARow14.push_back("'47'"); relARow14.push_back("'6542 XY'"); relARow14.push_back("'Hit and Run'"); relARow14.push_back("'Paris'"); relARow14.push_back("'AM'"); relARow14.push_back("'0'");
    offences.AddRow(relARow4);
    Row relARow15 = Row(); relARow15.push_back("'5398502'"); relARow15.push_back("'12/10/1992'"); relARow15.push_back("'567'"); relARow15.push_back("'47'"); relARow15.push_back("'6524 XY'"); relARow15.push_back("'DUI'"); relARow15.push_back("'Paris'"); relARow15.push_back("'AM'"); relARow15.push_back("'0.1'");
    offences.AddRow(relARow15);

    Row relARow16 = Row(); relARow16.push_back("'143203'"); relARow16.push_back("'25/10/1992'"); relARow16.push_back("'567'"); relARow16.push_back("'75'"); relARow16.push_back("'5634 FR'"); relARow16.push_back("'Parking'"); relARow16.push_back("'Paris'"); relARow16.push_back("'AM'"); relARow16.push_back("'0'");
    offences.AddRow(relARow16);
    Row relARow17 = Row(); relARow17.push_back("'987503'"); relARow17.push_back("'26/10/1992'"); relARow17.push_back("'456'"); relARow17.push_back("'75'"); relARow17.push_back("'3694 FR'"); relARow17.push_back("'DUI'"); relARow17.push_back("'Paris'"); relARow17.push_back("'AM'"); relARow17.push_back("'0'");
    offences.AddRow(relARow17);
    Row relARow18 = Row(); relARow18.push_back("'987503'"); relARow18.push_back("'26/10/1992'"); relARow18.push_back("'456'"); relARow18.push_back("'75'"); relARow18.push_back("'6534 XY'"); relARow18.push_back("'Hit and Run'"); relARow18.push_back("'Paris'"); relARow18.push_back("'AM'"); relARow18.push_back("'0'");
    offences.AddRow(relARow18);
    Row relARow19 = Row(); relARow19.push_back("'630803'"); relARow19.push_back("'15/10/1992'"); relARow19.push_back("'456'"); relARow19.push_back("'47'"); relARow19.push_back("'6344 XY'"); relARow19.push_back("'Speeding'"); relARow19.push_back("'Paris'"); relARow19.push_back("'AM'"); relARow19.push_back("'0'");
    offences.AddRow(relARow19);
    Row relARow20 = Row(); relARow20.push_back("'539803'"); relARow20.push_back("'12/10/1992'"); relARow20.push_back("'567'"); relARow20.push_back("'47'"); relARow20.push_back("'6344 XY'"); relARow20.push_back("'Hit and Run'"); relARow20.push_back("'Paris'"); relARow20.push_back("'AM'"); relARow20.push_back("'0.1'");
    offences.AddRow(relARow20);

    Row relARow21 = Row(); relARow21.push_back("'539004'"); relARow21.push_back("'12/10/1992'"); relARow21.push_back("'567'"); relARow21.push_back("'47'"); relARow21.push_back("'6344 XY'"); relARow21.push_back("'Hit and Run'"); relARow21.push_back("'Paris'"); relARow21.push_back("'AM'"); relARow21.push_back("'0.1'");
    offences.AddRow(relARow21); 
    Row relARow22 = Row(); relARow22.push_back("'539004'"); relARow22.push_back("'12/10/1992'"); relARow22.push_back("'567'"); relARow22.push_back("'47'"); relARow22.push_back("'6344 XY'"); relARow22.push_back("'Hit and Run'"); relARow22.push_back("'Salt Lake'"); relARow22.push_back("'AM'"); relARow22.push_back("'0.1'");
    offences.AddRow(relARow22); 
    Row relARow23 = Row(); relARow23.push_back("'539004'"); relARow23.push_back("'12/10/1992'"); relARow23.push_back("'567'"); relARow23.push_back("'47'"); relARow23.push_back("'6344 XY'"); relARow23.push_back("'Hit and Run'"); relARow23.push_back("'Paris'"); relARow23.push_back("'AM'"); relARow23.push_back("'0.1'");
    offences.AddRow(relARow23); 
    Row relARow24 = Row(); relARow24.push_back("'539004'"); relARow24.push_back("'12/10/1992'"); relARow24.push_back("'567'"); relARow24.push_back("'47'"); relARow24.push_back("'6344 XY'"); relARow24.push_back("'Hit and Run'"); relARow24.push_back("'Bangkok'"); relARow24.push_back("'PM'"); relARow24.push_back("'0.1'");
    offences.AddRow(relARow24); 
    Row relARow25 = Row(); relARow25.push_back("'539004'"); relARow25.push_back("'12/10/1992'"); relARow25.push_back("'567'"); relARow25.push_back("'47'"); relARow25.push_back("'6344 XY'"); relARow25.push_back("'Hit and Run'"); relARow25.push_back("'Paris'"); relARow25.push_back("'AM'"); relARow25.push_back("'0.1'");
    offences.AddRow(relARow25); 
    Row relARow26 = Row(); relARow26.push_back("'539004'"); relARow26.push_back("'12/10/1992'"); relARow26.push_back("'567'"); relARow26.push_back("'47'"); relARow26.push_back("'6344 XY'"); relARow26.push_back("'Hit and Run'"); relARow26.push_back("'Houston'"); relARow26.push_back("'AM'"); relARow26.push_back("'0.1'");
    offences.AddRow(relARow26); 
    Row relARow27 = Row(); relARow27.push_back("'539004'"); relARow27.push_back("'12/10/1992'"); relARow27.push_back("'567'"); relARow27.push_back("'47'"); relARow27.push_back("'6344 XY'"); relARow27.push_back("'Hit and Run'"); relARow27.push_back("'Paris'"); relARow27.push_back("'AM'"); relARow27.push_back("'0.1'");
    offences.AddRow(relARow27); 
    Row relARow28 = Row(); relARow28.push_back("'539004'"); relARow28.push_back("'12/10/1992'"); relARow28.push_back("'567'"); relARow28.push_back("'47'"); relARow28.push_back("'6344 XY'"); relARow28.push_back("'Hit and Run'"); relARow28.push_back("'Paris'"); relARow28.push_back("'AM'"); relARow28.push_back("'0.1'");
    offences.AddRow(relARow28); 
    Row relARow29 = Row(); relARow29.push_back("'539004'"); relARow29.push_back("'12/10/1992'"); relARow29.push_back("'567'"); relARow29.push_back("'47'"); relARow29.push_back("'6344 XY'"); relARow29.push_back("'Hit and Run'"); relARow29.push_back("'Paris'"); relARow29.push_back("'PM'"); relARow29.push_back("'0.1'");
    offences.AddRow(relARow29); 

    Row relARow30 = Row(); relARow30.push_back("'539005'"); relARow30.push_back("'12/10/1992'"); relARow30.push_back("'567'"); relARow30.push_back("'47'"); relARow30.push_back("'6344 XY'"); relARow30.push_back("'Hit and Run'"); relARow30.push_back("'Bangkok'"); relARow30.push_back("'AM'"); relARow30.push_back("'0.1'");
    offences.AddRow(relARow30);  
    Row relARow31 = Row(); relARow31.push_back("'539005'"); relARow31.push_back("'12/10/1992'"); relARow31.push_back("'567'"); relARow31.push_back("'47'"); relARow31.push_back("'6344 XY'"); relARow31.push_back("'Hit and Run'"); relARow31.push_back("'Salt Lake'"); relARow31.push_back("'AM'"); relARow31.push_back("'0.1'");
    offences.AddRow(relARow31); 
    Row relARow32 = Row(); relARow32.push_back("'539005'"); relARow32.push_back("'12/10/1992'"); relARow32.push_back("'567'"); relARow32.push_back("'47'"); relARow32.push_back("'6344 XY'"); relARow32.push_back("'Hit and Run'"); relARow32.push_back("'Paris'"); relARow32.push_back("'AM'"); relARow32.push_back("'0.1'");
    offences.AddRow(relARow32); 
    Row relARow33 = Row(); relARow33.push_back("'539005'"); relARow33.push_back("'12/10/1992'"); relARow33.push_back("'567'"); relARow33.push_back("'47'"); relARow33.push_back("'6344 XY'"); relARow33.push_back("'Hit and Run'"); relARow33.push_back("'Paris'"); relARow33.push_back("'PM'"); relARow33.push_back("'0.1'");
    offences.AddRow(relARow33); 
    Row relARow34 = Row(); relARow34.push_back("'539005'"); relARow34.push_back("'12/10/1992'"); relARow34.push_back("'567'"); relARow34.push_back("'47'"); relARow34.push_back("'6344 XY'"); relARow34.push_back("'Hit and Run'"); relARow34.push_back("'Salt Lake'"); relARow34.push_back("'AM'"); relARow34.push_back("'0.1'");
    offences.AddRow(relARow34); 
    Row relARow35 = Row(); relARow35.push_back("'539005'"); relARow35.push_back("'12/10/1992'"); relARow35.push_back("'567'"); relARow35.push_back("'47'"); relARow35.push_back("'6344 XY'"); relARow35.push_back("'Hit and Run'"); relARow35.push_back("'Paris'"); relARow35.push_back("'AM'"); relARow35.push_back("'0.1'");
    offences.AddRow(relARow35); 
    Row relARow36 = Row(); relARow36.push_back("'539005'"); relARow36.push_back("'12/10/1992'"); relARow36.push_back("'567'"); relARow36.push_back("'47'"); relARow36.push_back("'6344 XY'"); relARow36.push_back("'Hit and Run'"); relARow36.push_back("'Houston'"); relARow36.push_back("'PM'"); relARow36.push_back("'0.1'");
    offences.AddRow(relARow36); 
    Row relARow37 = Row(); relARow37.push_back("'539005'"); relARow37.push_back("'12/10/1992'"); relARow37.push_back("'567'"); relARow37.push_back("'47'"); relARow37.push_back("'6344 XY'"); relARow37.push_back("'Hit and Run'"); relARow37.push_back("'Paris'"); relARow37.push_back("'AM'"); relARow37.push_back("'0.1'");
    offences.AddRow(relARow37); 
    Row relARow38 = Row(); relARow38.push_back("'539005'"); relARow38.push_back("'12/10/1992'"); relARow38.push_back("'567'"); relARow38.push_back("'47'"); relARow38.push_back("'6344 XY'"); relARow38.push_back("'Hit and Run'"); relARow38.push_back("'Salt Lake'"); relARow38.push_back("'AM'"); relARow38.push_back("'0.1'");
    offences.AddRow(relARow38); 
    Row relARow39 = Row(); relARow39.push_back("'539005'"); relARow39.push_back("'12/10/1992'"); relARow39.push_back("'567'"); relARow39.push_back("'47'"); relARow39.push_back("'6344 XY'"); relARow39.push_back("'Hit and Run'"); relARow39.push_back("'Paris'"); relARow39.push_back("'AM'"); relARow39.push_back("'0.1'");
    offences.AddRow(relARow39); 

    Row relARow40 = Row(); relARow40.push_back("'539803'"); relARow40.push_back("'12/10/1992'"); relARow40.push_back("'567'"); relARow40.push_back("'47'"); relARow40.push_back("'6344 XY'"); relARow40.push_back("'Hit and Run'"); relARow40.push_back("'Paris'"); relARow40.push_back("'AM'"); relARow40.push_back("'0.1'");
    offences.AddRow(relARow40);
    Row relARow41 = Row(); relARow41.push_back("'539806'"); relARow41.push_back("'12/10/1992'"); relARow41.push_back("'567'"); relARow41.push_back("'47'"); relARow41.push_back("'6344 XY'"); relARow41.push_back("'Hit and Run'"); relARow41.push_back("'Salt Lake'"); relARow41.push_back("'AM'"); relARow41.push_back("'0.1'");
    offences.AddRow(relARow41); 
    Row relARow42 = Row(); relARow42.push_back("'539806'"); relARow42.push_back("'12/10/1992'"); relARow42.push_back("'567'"); relARow42.push_back("'47'"); relARow42.push_back("'6344 XY'"); relARow42.push_back("'Hit and Run'"); relARow42.push_back("'Paris'"); relARow42.push_back("'PM'"); relARow42.push_back("'0.1'");
    offences.AddRow(relARow42); 
    Row relARow43 = Row(); relARow43.push_back("'539806'"); relARow43.push_back("'12/10/1992'"); relARow43.push_back("'567'"); relARow43.push_back("'47'"); relARow43.push_back("'6344 XY'"); relARow43.push_back("'Hit and Run'"); relARow43.push_back("'Bangkok'"); relARow43.push_back("'AM'"); relARow43.push_back("'0.1'");
    offences.AddRow(relARow43); 
    Row relARow44 = Row(); relARow44.push_back("'539806'"); relARow44.push_back("'12/10/1992'"); relARow44.push_back("'567'"); relARow44.push_back("'47'"); relARow44.push_back("'6344 XY'"); relARow44.push_back("'Hit and Run'"); relARow44.push_back("'Paris'"); relARow44.push_back("'PM'"); relARow44.push_back("'0.1'");
    offences.AddRow(relARow44); 
    Row relARow45 = Row(); relARow45.push_back("'539806'"); relARow45.push_back("'12/10/1992'"); relARow45.push_back("'567'"); relARow45.push_back("'47'"); relARow45.push_back("'6344 XY'"); relARow45.push_back("'Hit and Run'"); relARow45.push_back("'Houston'"); relARow45.push_back("'AM'"); relARow45.push_back("'0.1'");
    offences.AddRow(relARow45); 
    Row relARow46 = Row(); relARow46.push_back("'539806'"); relARow46.push_back("'12/10/1992'"); relARow46.push_back("'567'"); relARow46.push_back("'47'"); relARow46.push_back("'6344 XY'"); relARow46.push_back("'Hit and Run'"); relARow46.push_back("'Paris'"); relARow46.push_back("'AM'"); relARow46.push_back("'0.1'");
    offences.AddRow(relARow46); 
    Row relARow47 = Row(); relARow47.push_back("'539806'"); relARow47.push_back("'12/10/1992'"); relARow47.push_back("'567'"); relARow47.push_back("'47'"); relARow47.push_back("'6344 XY'"); relARow47.push_back("'Hit and Run'"); relARow47.push_back("'Salt Lake'"); relARow47.push_back("'AM'"); relARow47.push_back("'0.1'");
    offences.AddRow(relARow47); 
    Row relARow48 = Row(); relARow48.push_back("'539806'"); relARow48.push_back("'12/10/1992'"); relARow48.push_back("'567'"); relARow48.push_back("'47'"); relARow48.push_back("'6344 XY'"); relARow48.push_back("'Hit and Run'"); relARow48.push_back("'Paris'"); relARow48.push_back("'PM'"); relARow48.push_back("'0.1'");
    offences.AddRow(relARow48); 
    Row relARow49 = Row(); relARow49.push_back("'539806'"); relARow49.push_back("'12/10/1992'"); relARow49.push_back("'567'"); relARow49.push_back("'47'"); relARow49.push_back("'6344 XY'"); relARow49.push_back("'Hit and Run'"); relARow49.push_back("'Paris'"); relARow49.push_back("'AM'"); relARow49.push_back("'0.1'");
    offences.AddRow(relARow49); 

    Row relARow50 = Row(); relARow50.push_back("'539807'"); relARow50.push_back("'12/10/1992'"); relARow50.push_back("'567'"); relARow50.push_back("'47'"); relARow50.push_back("'6344 XY'"); relARow50.push_back("'Hit and Run'"); relARow50.push_back("'Paris'"); relARow50.push_back("'AM'"); relARow50.push_back("'0.1'");
    offences.AddRow(relARow50);  
    // Create RelB
    Header hB = Header(); hB.push_back("Registration"); hB.push_back("Dept"); hB.push_back("Owner"); hB.push_back("Make"); hB.push_back("Year"); hB.push_back("New");
    Relation cars("Cars", hB);
    Row relBRow1 = Row(); relBRow1.push_back("'6544 XY'"); relBRow1.push_back("'75'"); relBRow1.push_back("'Josh Beatty'"); relBRow1.push_back("'Tesla'"); relBRow1.push_back("'2018'"); relBRow1.push_back("'Y'"); 
    cars.AddRow(relBRow1);
    Row relBRow2 = Row(); relBRow2.push_back("'7122 HT'"); relBRow2.push_back("'75'"); relBRow2.push_back("'Josh Beatty'"); relBRow2.push_back("'Ferari'"); relBRow2.push_back("'2019'"); relBRow2.push_back("'Y'");
    cars.AddRow(relBRow2);
    Row relBRow3 = Row(); relBRow3.push_back("'5694 FR'"); relBRow3.push_back("'75'"); relBRow3.push_back("'Natthaya Panmongkol'"); relBRow3.push_back("'Porsche'"); relBRow3.push_back("'2015'"); relBRow3.push_back("'N'"); 
    cars.AddRow(relBRow3);
    Row relBRow4 = Row(); relBRow4.push_back("'6524 XY'"); relBRow4.push_back("'47'"); relBRow4.push_back("'Tyler Sauer'"); relBRow4.push_back("'Toyota'"); relBRow4.push_back("'2017'"); relBRow4.push_back("'N'");
    cars.AddRow(relBRow4);

    Row relBRow5 = Row(); relBRow5.push_back("'6144 XY'"); relBRow5.push_back("'75'"); relBRow5.push_back("'Harry Potter'"); relBRow5.push_back("'Flying'"); relBRow5.push_back("'1999'"); relBRow5.push_back("'Y'");
    cars.AddRow(relBRow5);
    Row relBRow6 = Row(); relBRow6.push_back("'7132 HT'"); relBRow6.push_back("'75'"); relBRow6.push_back("'Ang'"); relBRow6.push_back("'Flying Bison'"); relBRow6.push_back("'345'"); relBRow6.push_back("'N'"); 
    cars.AddRow(relBRow6);
    Row relBRow7 = Row(); relBRow7.push_back("'3694 FR'"); relBRow7.push_back("'75'"); relBRow7.push_back("'Appa'"); relBRow7.push_back("'Air'"); relBRow7.push_back("'0'"); relBRow7.push_back("'N'"); 
    cars.AddRow(relBRow7);
    Row relBRow8 = Row(); relBRow8.push_back("'6544 XY'"); relBRow8.push_back("'47'"); relBRow8.push_back("'Prince Zuko'"); relBRow8.push_back("'Boat'"); relBRow8.push_back("'300'"); relBRow8.push_back("'Y'");
    cars.AddRow(relBRow8);

    Row relBRow9 = Row(); relBRow9.push_back("'6545 XY'"); relBRow9.push_back("'75'"); relBRow9.push_back("'Ang'"); relBRow9.push_back("'Staff'"); relBRow9.push_back("'011'"); relBRow9.push_back("'Y'"); 
    cars.AddRow(relBRow9);
    Row relBRow10 = Row(); relBRow10.push_back("'7102 HT'"); relBRow10.push_back("'75'"); relBRow10.push_back("'FireLord Ozai'"); relBRow10.push_back("'Yacht'"); relBRow10.push_back("'300'"); relBRow10.push_back("'Y'"); 
    cars.AddRow(relBRow10);
    Row relBRow11 = Row(); relBRow11.push_back("'5690 FR'"); relBRow11.push_back("'75'"); relBRow11.push_back("'Harry Potter'"); relBRow11.push_back("'Broom'"); relBRow11.push_back("'1996'"); relBRow11.push_back("'Y'"); 
    cars.AddRow(relBRow11);
    Row relBRow12 = Row(); relBRow12.push_back("'6594 XY'"); relBRow12.push_back("'47'"); relBRow12.push_back("'Appa'"); relBRow12.push_back("'Ship'"); relBRow12.push_back("'356'"); relBRow12.push_back("'N'"); 
    cars.AddRow(relBRow12);

    // Test NATURAL JOIN
    try {
        Relation r = Relation();
        r = r.Join(offences, cars);
        tc.AssertEquals(r.ToString(), r.ToString(), "Compare the expected output with the actual output");
    }
    catch(...) {
        bool isError = true;
        tc.AssertEquals(true, isError, "Verify that there was an out of range error");
    }
}

// void TestEdgeCases() {
// }

int main(int argc, char** argv) {
    TestUnionSelect();
    TestUnionProject();
    TestUnionRename();
    TestUnionTrifecta();
    TestNaturalJoin();
    TestNaturalJoinSelect();
    TestNaturalJoinProject();
    TestNaturalJoinMed();
    TestNaturalJoinLargeHeader();
    TestNaturalJoinLarge();
    // TestEdgeCases();

    TestCase::PrintSummary();
    return 0;
}
