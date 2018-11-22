#include <iostream>
#include <string>
#include <set>
#include <vector>

#include "TestCase.h"
#include "Relation.h"
#include "Row.h"
#include "Header.h"

using namespace std;


void TestSelectOne() {
    TestCase tc("TEST CASE 1: FIRST SELECT METHOD: \n");

    // Create Relation
    Header h = Header();
    h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row(); r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Test SELECT(VAL, VOL)
    cout << "\033[4;35mSELECT(\"'6.0'\", 0):\033[0m\n";
    Relation r = hawgs.Select("'6.0'", 0);
    tc.AssertEquals("H='6.0', A='22', W='180', G='Male', S='BYU'\nH='6.0', A='25', W='210', G='Male', S='BYU'\n", r.ToString(), "Our output should be the full row containing what we selected");
    cout << r.ToString();
    cout << "\033[4;35mSELECT(\"'25'\", 1):\033[0m\n";
    r = hawgs.Select("'25'", 1);
    cout << r.ToString();
    cout << "\033[4;35mSELECT(\"'Female'\", 3):\033[0m\n";
    r = hawgs.Select("'Female'", 3);
    cout << r.ToString();
    cout << "\033[4;35mSELECT(\"'Male'\", 3):\033[0m\n";
    r = hawgs.Select("'Male'", 3);
    cout << r.ToString(); 
}

void TestSelectTwo() {
    TestCase tc("TEST CASE 2: SECOND SELECT METHOD: \n");

    // Create Relation
    Header h = Header(); h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row(); r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'UofU'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'6.8'"); r3.push_back("'220'"); r3.push_back("'220'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'106'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'220'"); r5.push_back("'180'"); r5.push_back("'BYU'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Test SELECT(VAL, VOL)
    cout << "\033[4;35mSELECT(1, 2):\033[0m\n";
    Relation r = hawgs.Select(1, 2);
    // cout << r.ToString();
    tc.AssertEquals("H='6.8', A='220', W='220', G='Male', S='UofU'\n", r.ToString(), "Our output should be the full row containing what we selected");

    cout << "\033[4;35mSELECT(3, 4):\033[0m\n";
    r = hawgs.Select(3, 4);
    cout << r.ToString();
}

void TestSelectBreakOne() {
    TestCase tc("TEST CASE 3: BREAKING SELECT(val, col): \n");

    // Create Relation
    Header h = Header(); h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row(); r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row();  r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Test SELECT(VAL, COL) with BAD values
    bool isOutOfRange = false;
    // This should be empty
    cout << "\033[4;35mSELECT(\"'6.3'\", 0):\033[0m\n";
    Relation r = hawgs.Select("'6.3'", 0);
    cout << r.ToString();
    tc.AssertEquals(" ", " ", "Verifies that nothing is returned if wrong value");
    // This should throw an error
    try {
        cout << "\033[4;35mSELECT(\"'25'\", 6):\033[0m\n";
        r = hawgs.Select("'25'", 6);
        cout << r.ToString();
    } catch(...) {
        isOutOfRange = true;
        tc.AssertEquals(true, isOutOfRange, "Verifies that select stops if given out of range value");
        // cout << "OUT OF BOUNDS";
    }
}

void TestSelectBreakTwo() {
    TestCase tc("TEST CASE 4: BREAKING SELECT(col, col): \n");

    // Create Relation
    Header h = Header();
    h.push_back("H");
    h.push_back("A");
    h.push_back("W");
    h.push_back("G");
    h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row();
    r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row();
    r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row();
    r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row();
    r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row();
    r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Test SELECT(COL, COL) with BAD values
    bool isOutOfRange = false;
    // Testing with wrong imput values, should be empty
    cout << "\033[4;35mSELECT(1, 0):\033[0m\n";
    Relation r = hawgs.Select(1, 0);
    cout << r.ToString();
    tc.AssertEquals(" ", " ", "Verifies that nothing is returned cols have no matches");
    // This should throw an error because of negative value (out of range)
    try {
        cout << "\033[4;35mSELECT(-1, 444):\033[0m\n";
        r = hawgs.Select(-1, 444);
        cout << r.ToString();
    } catch(...) {
        isOutOfRange = true;
        tc.AssertEquals(true, isOutOfRange, "Verifies that select stops if given crazy large numbers");
        // cout << "OUT OF BOUNDS";
    }
}

void TestProject() {
    TestCase tc("TEST CASE 5: Project Method: \n");

    // Create Relation
    Header h = Header();
    h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row(); r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'18'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'22'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Test PROJECT
    vector<size_t> cols{0,1};
    cout << "\033[4;35mPROJECT(cols):\033[0m\n";
    Relation r = hawgs.Project(cols); cout << r.ToString();
    
}

void TestProjectBreak() {
    TestCase tc("TEST CASE 6: Breaking Project Method: \n");

    // Create Relation
    Header h = Header();
    h.push_back("H");
    h.push_back("A");
    h.push_back("W");
    h.push_back("G");
    h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row();
    r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row();
    r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row();
    r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row();
    r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row();
    r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // EDGE CASES HERE

}

void TestRename() {
    TestCase tc("TEST CASE 7: RENAME METHOD: \n");

    // Create Relation
    Header h = Header(); h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row(); r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Test RENAME
    cout << "\033[4;35m RENAME(nhawg, {N, H, A, W, G}):\033[0m\n";
    Header hNew = Header();
    hNew.push_back("N"); hNew.push_back("H"); hNew.push_back("A"); hNew.push_back("W"); hNew.push_back("G");
    Relation relRen = hawgs.Rename("nhawgs", hNew);
    // Compare the names
    bool isSameName = true;
    if(hawgs.name == relRen.name) {
        isSameName = true;
    } else { isSameName = false; }
    tc.AssertEquals(false, isSameName, "Tests that there was infact a valid rename");
}

void TestRenameBreak() {
    TestCase tc("TEST CASE 8: BREAK RENAME METHOD: \n");

    // Create Relation
    Header h = Header();
    h.push_back("H");
    h.push_back("A");
    h.push_back("W");
    h.push_back("G");
    h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row();
    r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row();
    r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row();
    r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row();
    r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row();
    r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Break RENAME here
    
}

void TestQueryOne() {
    TestCase tc("TEST CASE 9: Test Query One: Heights of people ages 25 \n");
    // SIMPLE QUERY: The Heights of any body of age 25

    // Create Relation
    Header h = Header(); h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S"); Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row(); r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Simple Query : The Heights of all people 25
    // Project[HEIGHT](Select([AGE = 25](hawgs)

    // First select the row that contains 25
    Relation r;
    r = hawgs.Select("'25'", 1);
    // Then project the column
    vector<size_t> cols{0};
    Relation QueryResult = r.Project(cols);

    // Answer should be 5.10 and 6 Ft
    cout << QueryResult.ToString();
    tc.AssertEquals("H='5.10'\nH='6.0'\n", QueryResult.ToString(), "Test the strings");

}

void TestQueryTwo() {
    TestCase tc("TEST CASE 10: Test Query Two: Height of All Females \n");

    // Another Simple Query but more difficult than the last.
    // Get from the table the heights of each Female, and rename the relation
    // Rename('fh', 'H') Project[0](Select[Female](hawgs))
    // Create Relation
    Header h = Header(); h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G"); h.push_back("S");
    Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row();  r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Rename('fh', 'H') Project[0](Select[Female](hawgs))
    // Select All rows with Female
    Relation rFemale = hawgs.Select("'Female'", 3);
    cout << rFemale.ToString();
    // Project only the heights
    vector<size_t> cols{0};
    Relation femaleHeight = rFemale.Project(cols);
    cout << femaleHeight.ToString();
    // Make the new Schemes 
    Header head = Header();
    head.push_back("H");
    // Rename
    Relation newRel = femaleHeight.Rename("female height", head);
    cout << newRel.ToString();
}

void TestQueryThree() {
    TestCase tc("TEST CASE 11: Test Query Three: \n");
    // More complex query that will project two adjacent cols
    // Get the SCHOOL and AGE of all MALES
    // Project[SCHOOL^AGE](SELECT[MALES](hawgs))

    // Create Relation
    Header h = Header();  h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G");  h.push_back("S"); Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row();  r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row();  r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row();  r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    // Project[SCHOOL^AGE](SELECT[MALES](hawgs))

    // First Select the Rows of Males
    Relation rMales = hawgs.Select("'Male'", 3);
    cout << "SELECTION: "<< rMales.ToString() << endl;
    // Project the SCHOOL and AGE cols from these Selections
    vector<size_t> cols{1, 4};
    Relation ageSchoolMales = rMales.Project(cols);
    cout << ageSchoolMales.ToString();

    tc.AssertEquals("A='18', S='UofU'\nA='22', S='BYU'\nA='25', S='BYU'\n", ageSchoolMales.ToString(), "The Relation from this query should match the accepted output");

}

void TestQueryFour() {
    TestCase tc("TEST CASE 12: Test Query Four: \n");
    // This will be multilayered query, using Select 2 times and 1 project
    // Get the rows of all the BYU students. From there, get the rows of anyone who is 22 from byu
    // Project their height, gender, and weight

    //Project[HEIGHT,GENDER,WIEGHT](SELECT[25](SELECT[BYU](hawgs)))

    // Create Relation
    Header h = Header();  h.push_back("H"); h.push_back("A"); h.push_back("W"); h.push_back("G");  h.push_back("S");  Relation hawgs("hawgs", h);

    // Add Rows of Data
    Row r1 = Row();  r1.push_back("'6.0'"); r1.push_back("'25'"); r1.push_back("'210'"); r1.push_back("'Male'"); r1.push_back("'BYU'");
    hawgs.AddRow(r1);
    Row r2 = Row(); r2.push_back("'5.2'"); r2.push_back("'27'"); r2.push_back("'106'"); r2.push_back("'Female'"); r2.push_back("'Julakorn'");
    hawgs.AddRow(r2);
    Row r3 = Row(); r3.push_back("'6.8'"); r3.push_back("'18'"); r3.push_back("'256'"); r3.push_back("'Male'"); r3.push_back("'UofU'");
    hawgs.AddRow(r3);
    Row r4 = Row(); r4.push_back("'5.10'"); r4.push_back("'25'"); r4.push_back("'107'"); r4.push_back("'Female'"); r4.push_back("'BYU'");
    hawgs.AddRow(r4);
    Row r5 = Row(); r5.push_back("'6.0'"); r5.push_back("'22'"); r5.push_back("'180'"); r5.push_back("'Male'"); r5.push_back("'BYU'");
    hawgs.AddRow(r5);

    //Project[HEIGHT,GENDER,WIEGHT](SELECT[25](SELECT[BYU](hawgs)))
    // First let's make our selections
    Relation byuDingos = hawgs.Select("'BYU'", 4);
    cout << byuDingos.ToString() << endl;
    Relation youngByuDingos = byuDingos.Select("'22'", 1);
    cout << youngByuDingos.ToString() << endl;
    // Now let's make our Projections
    vector<size_t> cols{0, 2, 3};
    Relation ageHeightWeightByuDingo = youngByuDingos.Project(cols);
    cout << ageHeightWeightByuDingo.ToString() << endl;

    tc.AssertEquals("H='6.0', W='180', G='Male'\n", ageHeightWeightByuDingo.ToString(), "This compares actual results for the query");

}
void SnapTest() {
    TestCase tc("THIS WILL CHECK CREATING A SNAP TABLE");
    Header h = Header();
    h.push_back("S");
    h.push_back("N");
    h.push_back("A");
    h.push_back("P");

    Relation snap("snap", h);

    Row row1 = Row();
    row1.push_back("'Snoopy'");
    row1.push_back("'RAPPER'");
    row1.push_back("'1234 cyg'");
    row1.push_back("'PHONE'");
    snap.AddRow(row1);
    Row row2 = Row();
    row2.push_back("'Dog'");
    row2.push_back("'OBGYN'");
    row2.push_back("'6666 cat'");
    row2.push_back("'PHONE'");
    snap.AddRow(row2);
    Row row3 = Row();
    row3.push_back("'Charlie'");
    row3.push_back("'Dr'");
    row3.push_back("'5298 Galaxy'");
    row3.push_back("'dafd'");
    snap.AddRow(row3);
    Row row4 = Row();
    row4.push_back("'willie'");
    row4.push_back("'Dr'");
    row4.push_back("'5298 Galaxy'");
    row4.push_back("'PHONE'");
    snap.AddRow(row4);
    Row row5 = Row();
    row5.push_back("'gil'");
    row5.push_back("'Dr'");
    row5.push_back("'5298 axy'");
    row5.push_back("'PHONE'");
    snap.AddRow(row5);
    Row row6 = Row();
    row6.push_back("'shark'");
    row6.push_back("'shark'");
    row6.push_back("'5298 Galaxy'");
    row6.push_back("'PHONE'");
    snap.AddRow(row6);
    Row row7 = Row();
    row7.push_back("'shark'");
    row7.push_back("'Dr'");
    row7.push_back("'5298 Galaxy'");
    row7.push_back("'PHONE'");
    snap.AddRow(row7);
    Row row8 = Row();
    row8.push_back("'char'");
    row8.push_back("'Dr'");
    row8.push_back("'5298 Galaxy'");
    row8.push_back("'PHONE'");
    snap.AddRow(row8);
    Row row9 = Row();
    row9.push_back("'chill'");
    row9.push_back("'Dr'");
    row9.push_back("'5298 Galaxy'");
    row9.push_back("'PHONE'");
    snap.AddRow(row9);
    Row row10 = Row();
    row10.push_back("'Josh'");
    row10.push_back("'Dr'");
    row10.push_back("'5298 Galaxy'");
    row10.push_back("'PHONE'");
    snap.AddRow(row10);
    Row row11 = Row();
    row11.push_back("'Jerry'");
    row11.push_back("'Dr'");
    row11.push_back("'5298 Galaxy'");
    row11.push_back("'PHONE'");
    snap.AddRow(row11);
    Row row12 = Row();
    row12.push_back("'jow'");
    row12.push_back("'Dr'");
    row12.push_back("'5298 Galaxy'");
    row12.push_back("'PHONE'");
    snap.AddRow(row12);
    Row row13 = Row();
    row13.push_back("'hdgj'");
    row13.push_back("'Dr'");
    row13.push_back("'5298 Galaxy'");
    row13.push_back("'PHONE'");
    snap.AddRow(row13);
    Row row14 = Row();
    row14.push_back("'nat'");
    row14.push_back("'Dr'");
    row14.push_back("'5298 Galaxy'");
    row14.push_back("'PHONE'");
    snap.AddRow(row14);
    Row row15 = Row();
    row15.push_back("'holly'");
    row15.push_back("'Dr'");
    row15.push_back("'5298 Galaxy'");
    row15.push_back("'PHONE'");
    snap.AddRow(row15);
    Row row16 = Row();
    row16.push_back("'gym'");
    row16.push_back("'Dr'");
    row16.push_back("'5298 Galaxy'");
    row16.push_back("'PHONE'");
    snap.AddRow(row16);

    tc.AssertEquals(3, snap.rows.size(), "Should have only 3 row");
    
    // snap.ToString();
    // snap.PrintName();
    // snap.PrintHeader();
    // snap.PrintRows();

    cout << snap.ToString();
    Relation newRel;
    cout << "#########################" << endl;
    newRel = snap.Select("'gym'", 0);
    cout << newRel.ToString();
    cout << "#########################" << endl;
    Relation rel;
    rel = snap.Select(0, 1);
    cout << rel.ToString();
    cout << "########################" << endl;
    Relation ren;
    Header newHead = Header();
    newHead.push_back("H");
    // ren.Rename(newHead);

    cout << ren.ToString();
    // Relation pro;
    // vector<size_t> cols{0, 0};
    // pro = snap.Project(cols);

    // cout << pro.ToString();
}

int main(int argc, char** argv) {
    // SnapTest();
    TestSelectOne();
    TestSelectTwo();
    TestSelectBreakOne();
    TestSelectBreakTwo();
    TestProject();
    TestProjectBreak();
    TestRename();
    TestRenameBreak();
    TestQueryOne();
    TestQueryTwo();
    TestQueryThree();
    TestQueryFour();
    
    TestCase::PrintSummary();
    return 0;
}