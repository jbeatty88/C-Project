#pragma once

#include "Node.h"
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>


class Graph {
    public:
        std::map<size_t, Node> nodes;
        std::map<size_t, Node> invertedNodes;
        std::stack<size_t> postOrder;
        std::set<size_t> scc;
        std::vector<std::set<size_t>> allSccs;

    public:
        Graph();
        ~Graph();

        void InvertGraph(std::map<size_t, Node> n);
        void SetNodes(std::map<size_t, Node> n);
        // void SetInverted(std::map<size_t, Node> n);
        bool AddedNode(size_t idx);
        std::map<size_t, Node> GetNodes();
        void AddEdge(size_t nA, size_t nB);
        void ReverseEdge(size_t nA, size_t nB);

        void PostOrderPush(size_t n);
        size_t PostOrderPop();
        std::stack<size_t> GetPostOrder();
        void SetPostOrder(std::stack<size_t> o);

        std::vector<std::set<size_t>> FindSccs();
        void dfsForest();
        void dfs(Node& node, bool numChange); 

        std::string ToString();
        std::string ToStringSCC(std::set<size_t> scc);
        std::string ToStringInverted();


};
