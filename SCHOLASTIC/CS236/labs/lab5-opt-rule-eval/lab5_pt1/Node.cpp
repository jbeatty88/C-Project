#include "Node.h"
using namespace std;

Node::Node() {
	this->adjNodeIdx = {};
	this->node = -1;
	this->postOrderNum = 0;
	this->isVisited = false;
}

Node::Node(size_t n) {
	this->adjNodeIdx = {};
	this->node = n;
	this->postOrderNum = 0;
	this->isVisited = false;
}


Node::~Node() {}

size_t Node::GetNode() { return this->node; }

void Node::SetNodeNum(size_t n) { this->node = n; }

bool Node::GetVisited() { return this->isVisited; }

void Node::SetVisited(bool visited) { this->isVisited = visited; }

size_t Node::GetPostOrder() { return this->postOrderNum; }

void Node::SetPostOrder(size_t n) { this->postOrderNum = n; }

set<size_t> Node::GetAdjNodeIdx() { return this->adjNodeIdx; }

void Node::SetAdjNodeIdx(set<size_t> idxs) { this->adjNodeIdx = idxs; }

bool Node::AddedAdjNode(size_t idx) {
    // Attempt to add the node
    if(this->adjNodeIdx.insert(idx).second)
        // If it was added, return true
        return true;
    else 
        // Otherwise, it wasn't added
        return false;
}

string Node::AdjNodeToString() {
    stringstream ss;
    set<size_t>::iterator itr = this->adjNodeIdx.begin();
    set<size_t>::iterator last = this->adjNodeIdx.end();

    for(; itr != last; itr++) {
        if(next(itr) == last)
            ss << "R" << *itr;
        else 
            ss << "R" << *itr << ",";
    }
    return ss.str();
}

string Node::ToString() {
    stringstream ss;
    ss << "R" << this->node << endl;
    ss << "VISITED: ";
    if(this->isVisited)
        ss << "YES" << endl;
    else
        ss << "NO" << endl;
    ss << "POST ORDER NUM: " << this->postOrderNum << endl;
    return ss.str();
}