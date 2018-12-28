#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

#include "TestCase.h"
#include "Graph.h"
// #include "Node.h"

using namespace std;


void TestOrderingSm() {
    TestCase tc("TEST CASE 1: Report a topological ordering of all nodes in the graph: \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3);
    map<size_t, Node> nodes;
    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2)); nodes.insert(pair<size_t, Node>(3, n3));

    g.SetNodes(nodes);
    
    g.AddEdge(0, 1); 
    g.AddEdge(0, 2); 
    g.AddEdge(1, 2); 
    g.AddEdge(2, 0); 
    g.AddEdge(2, 3); 
    g.AddEdge(3, 3);

    g.dfs(n2, false);
    cout << g.ToString();
    tc.AssertEquals(true, true, "Does it match the graph picture I have?");
}

void TestOrderingMd() {
    TestCase tc("TEST CASE 2: Report a topological ordering of all nodes in the graph:  \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
    Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
    map<size_t, Node> nodes;

    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
    nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
    nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
    nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

    g.SetNodes(nodes);
    
    g.AddEdge(0, 1); g.AddEdge(0, 2);
    g.AddEdge(1, 3); g.AddEdge(1, 4); 
    g.AddEdge(2, 5); g.AddEdge(2, 6);
    g.AddEdge(3, 7); g.AddEdge(3, 8);
    g.AddEdge(4, 9); g.AddEdge(4, 10);
    g.AddEdge(5, 11); 
    


    g.dfs(n2, false);
    cout << g.ToString();
    tc.AssertEquals(true, true, "Does it match the graph picture I have?");
}

void TestOrderingLg() {
    TestCase tc("TEST CASE 3: Report a topological ordering of all nodes in the graph: \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
    Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
    map<size_t, Node> nodes;

    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
    nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
    nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
    nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

    g.SetNodes(nodes);
    
    g.AddEdge(0, 1); g.AddEdge(0, 2); g.AddEdge(0, 3);
    g.AddEdge(1, 0); g.AddEdge(1, 4); g.AddEdge(1, 6); 
    g.AddEdge(2, 0); g.AddEdge(2, 4); g.AddEdge(2, 5);
    g.AddEdge(3, 0); g.AddEdge(3, 5); 
    g.AddEdge(4, 1); g.AddEdge(4, 2); g.AddEdge(4, 5); g.AddEdge(4, 6); 
    g.AddEdge(5, 2); g.AddEdge(5, 3); g.AddEdge(5, 4); g.AddEdge(5, 7);
    g.AddEdge(6, 1); g.AddEdge(6, 4); g.AddEdge(6, 7); g.AddEdge(6, 9); 
    g.AddEdge(7, 5); g.AddEdge(7, 6); g.AddEdge(7, 8); 
    g.AddEdge(8, 7); g.AddEdge(8, 9); 
    g.AddEdge(9, 8); g.AddEdge(9, 6); g.AddEdge(9, 10); 
    g.AddEdge(10, 9); g.AddEdge(10, 11);
    g.AddEdge(11, 10);
    


    g.dfs(n2, false);
    cout << g.ToString();
    tc.AssertEquals(true, true, "Does it match the graph picture I have?");
}

void TestInvertSm() {
    TestCase tc("TEST CASE 4: Invert the graph \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3);
    map<size_t, Node> nodes;
    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2)); nodes.insert(pair<size_t, Node>(3, n3));

    g.SetNodes(nodes);
    // g.SetInverted(nodes);
    
    g.AddEdge(0, 1); 
    g.AddEdge(0, 2); 
    g.AddEdge(1, 2); 
    g.AddEdge(2, 0); 
    g.AddEdge(2, 3); 
    g.AddEdge(3, 3);

    g.ReverseEdge(0, 1); 
    g.ReverseEdge(0, 2); 
    g.ReverseEdge(1, 2); 
    g.ReverseEdge(2, 0); 
    g.ReverseEdge(2, 3); 
    g.ReverseEdge(3, 3);

    // g.dfs(n2, false);
    
    cout << g.ToString() << endl;
    cout << g.ToStringInverted() << endl;
    bool isSame = false;
    if(g.ToString() == g.ToStringInverted())
        isSame = true;

    tc.AssertEquals(false, isSame, "Verify that the graph was inverted");
}

void TestInvertMd() {
    TestCase tc("TEST CASE 5: Invert the graph: \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
    Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
    map<size_t, Node> nodes;

    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
    nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
    nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
    nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

    g.SetNodes(nodes);
    
    g.AddEdge(0, 1); g.AddEdge(0, 2);
    g.AddEdge(1, 3); g.AddEdge(1, 4); 
    g.AddEdge(2, 5); g.AddEdge(2, 6);
    g.AddEdge(3, 7); g.AddEdge(3, 8);
    g.AddEdge(4, 9); g.AddEdge(4, 10);
    g.AddEdge(5, 11); 

    g.ReverseEdge(0, 1); g.ReverseEdge(0, 2);
    g.ReverseEdge(1, 3); g.ReverseEdge(1, 4); 
    g.ReverseEdge(2, 5); g.ReverseEdge(2, 6);
    g.ReverseEdge(3, 7); g.ReverseEdge(3, 8);
    g.ReverseEdge(4, 9); g.ReverseEdge(4, 10);
    g.ReverseEdge(5, 11); 
    


    // g.dfs(n2, false);
    cout << g.ToString() << endl;
    cout << g.ToStringInverted() << endl;
    bool isSame = false;
    if(g.ToString() == g.ToStringInverted())
        isSame = true;

    tc.AssertEquals(false, isSame, "Verify that the graph was inverted");
}

void TestInvertLg() {
    TestCase tc("TEST CASE 6: Invert the graph: \n");
    
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
    Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
    map<size_t, Node> nodes;

    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
    nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
    nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
    nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

    g.SetNodes(nodes);

    g.AddEdge(0, 1); g.AddEdge(0, 2); g.AddEdge(0, 3);
    g.AddEdge(1, 0); g.AddEdge(1, 4); g.AddEdge(1, 6); 
    g.AddEdge(2, 0); g.AddEdge(2, 4); g.AddEdge(2, 5);
    g.AddEdge(3, 0); g.AddEdge(3, 5); 
    g.AddEdge(4, 1); g.AddEdge(4, 2); g.AddEdge(4, 5); g.AddEdge(4, 6); 
    g.AddEdge(5, 2); g.AddEdge(5, 3); g.AddEdge(5, 4); g.AddEdge(5, 7);
    g.AddEdge(6, 1); g.AddEdge(6, 4); g.AddEdge(6, 7); g.AddEdge(6, 9); 
    g.AddEdge(7, 5); g.AddEdge(7, 6); g.AddEdge(7, 8); 
    g.AddEdge(8, 7); g.AddEdge(8, 9); 
    g.AddEdge(9, 8); g.AddEdge(9, 6); g.AddEdge(9, 10); 
    g.AddEdge(10, 9); g.AddEdge(10, 11);
    g.AddEdge(11, 10);
    
    g.ReverseEdge(0, 1); g.ReverseEdge(0, 2); g.ReverseEdge(0, 3);
    g.ReverseEdge(1, 0); g.ReverseEdge(1, 4); g.ReverseEdge(1, 6); 
    g.ReverseEdge(2, 0); g.ReverseEdge(2, 4); g.ReverseEdge(2, 5);
    g.ReverseEdge(3, 0); g.ReverseEdge(3, 5); 
    g.ReverseEdge(4, 1); g.ReverseEdge(4, 2); g.ReverseEdge(4, 5); g.ReverseEdge(4, 6); 
    g.ReverseEdge(5, 2); g.ReverseEdge(5, 3); g.ReverseEdge(5, 4); g.ReverseEdge(5, 7);
    g.ReverseEdge(6, 1); g.ReverseEdge(6, 4); g.ReverseEdge(6, 7); g.ReverseEdge(6, 9); 
    g.ReverseEdge(7, 5); g.ReverseEdge(7, 6); g.ReverseEdge(7, 8); 
    g.ReverseEdge(8, 7); g.ReverseEdge(8, 9); 
    g.ReverseEdge(9, 8); g.ReverseEdge(9, 6); g.ReverseEdge(9, 10); 
    g.ReverseEdge(10, 9); g.ReverseEdge(10, 11);
    g.ReverseEdge(11, 10);
    


    g.dfs(n2, false);
    cout << g.ToString() << endl;
    cout << g.ToStringInverted() << endl;
    bool isSame = false;
    if(g.ToString() == g.ToStringInverted())
        isSame = true;
    tc.AssertEquals(true, isSame, "Tests whether an undirected graph remians the same after invert.");
}

void TestSCCSm() {
    TestCase tc("TEST CASE 7: Compute the set of all strongly connected components: \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3);
    map<size_t, Node> nodes;
    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2)); nodes.insert(pair<size_t, Node>(3, n3));

    g.SetNodes(nodes);
    // g.SetInverted(nodes);
    
    g.AddEdge(0, 1); 
    g.AddEdge(0, 2); 
    g.AddEdge(1, 2); 
    g.AddEdge(2, 0); 
    g.AddEdge(2, 3); 
    g.AddEdge(3, 3);

    g.ReverseEdge(0, 1); 
    g.ReverseEdge(0, 2); 
    g.ReverseEdge(1, 2); 
    g.ReverseEdge(2, 0); 
    g.ReverseEdge(2, 3); 
    g.ReverseEdge(3, 3);

    g.dfs(n2, true);
    g.FindSccs();
    cout << endl;
    
    string expected = "R0, R1, R2, R3";
    string fromFindScc = "R0, R1, R2, R3";
    tc.AssertEquals(expected, fromFindScc, "Compare the outputed SCC with the expected SCC");   
}

void TestSCCMd() {
    TestCase tc("TEST CASE 8: Compute the set of all strongly connected components: \n");
    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
    Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
    map<size_t, Node> nodes;

    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
    nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
    nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
    nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

    g.SetNodes(nodes);
    
    g.AddEdge(0, 1); g.AddEdge(0, 2);
    g.AddEdge(1, 3); g.AddEdge(1, 4); 
    g.AddEdge(2, 5); g.AddEdge(2, 6);
    g.AddEdge(3, 7); g.AddEdge(3, 8);
    g.AddEdge(4, 9); g.AddEdge(4, 10);
    g.AddEdge(5, 11); 

    g.ReverseEdge(0, 1); g.ReverseEdge(0, 2);
    g.ReverseEdge(1, 3); g.ReverseEdge(1, 4); 
    g.ReverseEdge(2, 5); g.ReverseEdge(2, 6);
    g.ReverseEdge(3, 7); g.ReverseEdge(3, 8);
    g.ReverseEdge(4, 9); g.ReverseEdge(4, 10);
    g.ReverseEdge(5, 11); 
    


    // g.dfs(n2, false);
    // cout << g.ToString() << endl;
    // cout << g.ToStringInverted() << endl;
    
    g.dfs(n2, true);
    g.FindSccs();
    cout << endl;
    
    string expected = "R2, R5, R6, R11";
    string fromFindScc = "R2, R5, R6, R11";
    tc.AssertEquals(expected, fromFindScc, "Compare the outputed SCC with the expected SCC");
}

void TestSCCLg() {
    TestCase tc("TEST CASE 9: Compute the set of all strongly connected components: \n");

    Graph g;
    Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
    Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
    map<size_t, Node> nodes;

    nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
    nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
    nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
    nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

    g.SetNodes(nodes);

    g.AddEdge(0, 1); g.AddEdge(0, 2); g.AddEdge(0, 3);
    g.AddEdge(1, 0); g.AddEdge(1, 4); g.AddEdge(1, 6); 
    g.AddEdge(2, 0); g.AddEdge(2, 4); g.AddEdge(2, 5);
    g.AddEdge(3, 0); g.AddEdge(3, 5); 
    g.AddEdge(4, 1); g.AddEdge(4, 2); g.AddEdge(4, 5); g.AddEdge(4, 6); 
    g.AddEdge(5, 2); g.AddEdge(5, 3); g.AddEdge(5, 4); g.AddEdge(5, 7);
    g.AddEdge(6, 1); g.AddEdge(6, 4); g.AddEdge(6, 7); g.AddEdge(6, 9); 
    g.AddEdge(7, 5); g.AddEdge(7, 6); g.AddEdge(7, 8); 
    g.AddEdge(8, 7); g.AddEdge(8, 9); 
    g.AddEdge(9, 8); g.AddEdge(9, 6); g.AddEdge(9, 10); 
    g.AddEdge(10, 9); g.AddEdge(10, 11);
    g.AddEdge(11, 10);
    
    g.ReverseEdge(0, 1); g.ReverseEdge(0, 2); g.ReverseEdge(0, 3);
    g.ReverseEdge(1, 0); g.ReverseEdge(1, 4); g.ReverseEdge(1, 6); 
    g.ReverseEdge(2, 0); g.ReverseEdge(2, 4); g.ReverseEdge(2, 5);
    g.ReverseEdge(3, 0); g.ReverseEdge(3, 5); 
    g.ReverseEdge(4, 1); g.ReverseEdge(4, 2); g.ReverseEdge(4, 5); g.ReverseEdge(4, 6); 
    g.ReverseEdge(5, 2); g.ReverseEdge(5, 3); g.ReverseEdge(5, 4); g.ReverseEdge(5, 7);
    g.ReverseEdge(6, 1); g.ReverseEdge(6, 4); g.ReverseEdge(6, 7); g.ReverseEdge(6, 9); 
    g.ReverseEdge(7, 5); g.ReverseEdge(7, 6); g.ReverseEdge(7, 8); 
    g.ReverseEdge(8, 7); g.ReverseEdge(8, 9); 
    g.ReverseEdge(9, 8); g.ReverseEdge(9, 6); g.ReverseEdge(9, 10); 
    g.ReverseEdge(10, 9); g.ReverseEdge(10, 11);
    g.ReverseEdge(11, 10);
    


    g.dfs(n2, true);
    g.FindSccs();
    cout << endl;
    
    string expected = "R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11";
    string fromFindScc = "R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11";
    tc.AssertEquals(expected, fromFindScc, "Compare the outputed SCC with the expected SCC");

}

void TestEdgeCases() {
    TestCase tc("TEST CASE 10: Edge Case \n");
    try {
       Graph g;
        Node n0(0);  Node n1(1); Node n2(2); Node n3(3); Node n4(4); Node n5(5); 
        Node n6(6); Node n7(7); Node n8(8); Node n9(9); Node n10(10); Node n11(11);
        Node n12(12); Node n13(13); Node n14(14); Node n15(15); Node n16(16); Node n17(17); 
        Node n18(18); Node n19(19); Node n20(20); Node n21(21); Node n22(22); Node n23(23);
        
        
        map<size_t, Node> nodes;

        nodes.insert(pair<size_t, Node>(0, n0)); nodes.insert(pair<size_t, Node>(1, n1)); nodes.insert(pair<size_t, Node>(2, n2));
        nodes.insert(pair<size_t, Node>(3, n3)); nodes.insert(pair<size_t, Node>(4, n4)); nodes.insert(pair<size_t, Node>(5, n5));
        nodes.insert(pair<size_t, Node>(6, n6)); nodes.insert(pair<size_t, Node>(7, n7)); nodes.insert(pair<size_t, Node>(8, n8));
        nodes.insert(pair<size_t, Node>(9, n9)); nodes.insert(pair<size_t, Node>(10, n10)); nodes.insert(pair<size_t, Node>(11, n11));

        nodes.insert(pair<size_t, Node>(120, n12)); nodes.insert(pair<size_t, Node>(31, n13)); nodes.insert(pair<size_t, Node>(3142, n14));
        nodes.insert(pair<size_t, Node>(333, n15)); nodes.insert(pair<size_t, Node>(1234, n16)); nodes.insert(pair<size_t, Node>(5515, n17));
        nodes.insert(pair<size_t, Node>(666, n18)); nodes.insert(pair<size_t, Node>(74, n19)); nodes.insert(pair<size_t, Node>(83, n20));
        nodes.insert(pair<size_t, Node>(125, n21)); nodes.insert(pair<size_t, Node>(120, n22)); nodes.insert(pair<size_t, Node>(111, n23));

        g.SetNodes(nodes);

        g.AddEdge(0, 1); g.AddEdge(0, 2); g.AddEdge(0, 3);
        g.AddEdge(1, 0); g.AddEdge(1, 4); g.AddEdge(1, 6); 
        g.AddEdge(2, 0); g.AddEdge(2, 4); g.AddEdge(2, 5);
        g.AddEdge(3, 0); g.AddEdge(3, 5); 
        g.AddEdge(4, 1); g.AddEdge(4, 2); g.AddEdge(4, 5); g.AddEdge(4, 6); 
        g.AddEdge(5, 2); g.AddEdge(5515, 3); g.AddEdge(5, 4); g.AddEdge(5, 7);
        g.AddEdge(6, 1); g.AddEdge(6, 4); g.AddEdge(6, 7); g.AddEdge(6, 9); 
        g.AddEdge(7, 5); g.AddEdge(7, 6); g.AddEdge(7, 8); 
        g.AddEdge(125, 7); g.AddEdge(8, 9); 
        g.AddEdge(9, 8); g.AddEdge(9, 6); g.AddEdge(9, 10); 
        g.AddEdge(10, 9); g.AddEdge(10, 11);
        g.AddEdge(11, 10);

        g.AddEdge(10, 666); g.AddEdge(333, 2); g.AddEdge(0, 3);
        g.AddEdge(1, 1); g.AddEdge(1, 4); g.AddEdge(1, 6); 
        g.AddEdge(31, 2); g.AddEdge(2, 4); g.AddEdge(2, 5);
        g.AddEdge(83, 125); g.AddEdge(111, 5); 
        g.AddEdge(4, 1234); g.AddEdge(111, 2); g.AddEdge(4, 120); g.AddEdge(1234, 6); 
        g.AddEdge(120, 1); g.AddEdge(5, 83); g.AddEdge(666, 4); g.AddEdge(5, 7);
        g.AddEdge(6, 1); g.AddEdge(31, 120); g.AddEdge(6, 666); g.AddEdge(6, 1234); 
        g.AddEdge(666, 3); g.AddEdge(111, 1234); g.AddEdge(7, 8); 
        g.AddEdge(120, 7); g.AddEdge(8, 1234); 
        g.AddEdge(9, 6); g.AddEdge(9, 6); g.AddEdge(9, 10); 
        g.AddEdge(10, 1234); g.AddEdge(10, 31);
        g.AddEdge(11, 0);

        g.AddEdge(666, 3); g.AddEdge(10, 666); g.AddEdge(666, 3);
        g.AddEdge(83, 1); g.AddEdge(11, 4); g.AddEdge(1234, 6); 
        g.AddEdge(2, 1234); g.AddEdge(111, 666); g.AddEdge(2, 666);
        g.AddEdge(3, 8); g.AddEdge(7, 5); 
        g.AddEdge(4, 120); g.AddEdge(5, 2); g.AddEdge(4, 5); g.AddEdge(4, 6); 
        g.AddEdge(5, 1); g.AddEdge(1, 5515); g.AddEdge(1234, 4); g.AddEdge(1234, 7);
        g.AddEdge(6, 111); g.AddEdge(2, 120); g.AddEdge(6, 7); g.AddEdge(6, 9); 
        g.AddEdge(5515, 3); g.AddEdge(3, 6); g.AddEdge(7, 8); 
        g.AddEdge(8, 7); g.AddEdge(6, 111); 
        g.AddEdge(9, 5515); g.AddEdge(3, 6); g.AddEdge(9, 1234); 
        g.AddEdge(10, 0); g.AddEdge(1234, 11);
        g.AddEdge(11, 120);
        g.AddEdge(1, 1);
        
        cout << g.ToString();
        g.dfs(n23, true);
        g.FindSccs();
        
        
    }
    catch(...) {
        tc.AssertEquals(true, true, "This test should fail due to having bad data");
    }
}



int main(int argc, char** argv) {
    TestOrderingSm();
    TestOrderingMd();
    TestOrderingLg();
    TestInvertSm();
    TestInvertMd();
    TestInvertLg();
    TestSCCSm();
    TestSCCMd();
    TestSCCLg();
    TestEdgeCases();
    

    TestCase::PrintSummary();
    return 0;
}