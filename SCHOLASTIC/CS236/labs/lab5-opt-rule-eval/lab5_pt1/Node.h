#pragma once

#include <iostream>
#include <set>
#include <string>
#include <sstream>

class Node {
    public:
        size_t node;
        std::set<size_t> adjNodeIdx;
        bool isVisited;
        size_t postOrderNum;

    public:
        Node();
        Node(size_t n);
        ~Node();
        
        size_t GetNode();
        void SetNodeNum(size_t n);

        bool GetVisited();
        void SetVisited(bool visited);

        size_t GetPostOrder();
        void SetPostOrder(size_t n);

        std::set<size_t> GetAdjNodeIdx();
        void SetAdjNodeIdx(std::set<size_t> idxs);
        bool AddedAdjNode(size_t idx);
        std::string AdjNodeToString();

        std::string ToString();
};