#include "Graph.h"
using namespace std;

Graph::Graph() {
    this->nodes = {};
	this->scc = {};
	this->allSccs = {};
}

Graph::~Graph() {}

void Graph::InvertGraph(map<size_t, Node> n) {

}

void Graph::SetNodes(map<size_t, Node> n) { this->nodes = n; this->invertedNodes = n;}

// void Graph::SetInverted(map<size_t, Node> n) { this->invertedNodes = n; }

// void Graph::SetNodes(vector<size_t> n) { this->nodes = n; }

bool Graph::AddedNode(size_t idx) {
    // Attempt to create a new node to be added to the graph
    Node newNode = Node(idx);
    // If it was added, there was no duplicate and it worked
    if(this->nodes.insert({ idx, newNode }).second)
        return true;
    // If it wasn't added, it was a duplicate
    else
        return false;
}

std::map<size_t, Node> Graph::GetNodes() { return this->nodes; }

void Graph::AddEdge(size_t nA, size_t nB) { this->nodes.find(nA)->second.AddedAdjNode(nB); }

void Graph::ReverseEdge(size_t nA, size_t nB) { this->invertedNodes.find(nB)->second.AddedAdjNode(nA); }

void Graph::PostOrderPush(size_t n) { this->postOrder.push(n); }

size_t Graph::PostOrderPop() {
    // Save the top of the stack
    size_t topNum = this->postOrder.top();
    // Pop the top of the stack
    this->postOrder.pop();
    // Return the top of the stack
    return topNum;
}

stack<size_t> Graph::GetPostOrder() { return this-> postOrder; }

void Graph::SetPostOrder(std::stack<size_t> o) { this->postOrder = o; }

vector<set<size_t>> Graph::FindSccs() {
    // Travers throuth the post order numbers
    while(this->postOrder.size() > 0) {
        size_t idx = this->PostOrderPop();
        // Clear previously saved components
        this->scc.clear();
        // If the node has not been visited
        if(this->nodes.at(idx).GetVisited() == false) {
            // Traverse the graph in this direction
            this->dfs(this->nodes.at(idx), false);
            // Add it to our vector of components
            this->allSccs.push_back(this->scc);
        }
    }
    cout << this->ToStringSCC(this->scc);
    return this->allSccs;
}

void Graph::dfsForest() {
    // Traverse the nodes for visted univisted nodes
    for(auto& itr : this->nodes) {
        // If the node was no visited
        if(itr.second.GetVisited() == false) {
            // Traverse this direction
            this->dfs(itr.second, true);
        }
    }
}

void Graph::dfs(Node& node, bool numChange) {
    node.SetVisited(true);
    // Travers through the graph
    for(size_t idx : node.GetAdjNodeIdx()) {
        // If has not been visited
        if(this->nodes.at(idx).GetVisited() == false) {
            // And if the post order number has not changed
            if(numChange) 
                // Go this direction
                this->dfs(this->nodes.at(idx), true);
            else 
                // Or go the other direction
                this->dfs(this->nodes.at(idx), false);
        }
    }
    // If the post order number changed
    if(numChange) {
        // Update it
        this->PostOrderPush(node.GetNode());
    }
    // Add it to the collection
    this->scc.insert(node.GetNode());
}

string Graph::ToString() {
    stringstream ss;
    map<size_t, Node>::iterator itr = this->nodes.begin();
    map<size_t, Node>::iterator last = this->nodes.end();

    for(; itr  != last; itr++) {
        ss << "R" << itr->first << ":" << itr->second.AdjNodeToString() << endl;
    }
    return ss.str();
}

string Graph::ToStringSCC(set<size_t> scc) {
    stringstream ss;
    // vector<set<size_t>>::iterator itr = this->allSccs.begin();
    // vector<set<size_t>>::iterator last = this->allSccs.end();
    set<size_t>::iterator itr = scc.begin();
    set<size_t>::iterator setLast = scc.end();

    for(; itr  != setLast; itr++) {
        if (next(itr) == setLast)
			ss << "R" << *itr;
		else 
			ss << "R" << *itr << ", ";
    }
    return ss.str();
}

string Graph::ToStringInverted() {
    stringstream ss;
    map<size_t, Node>::iterator itr = this->invertedNodes.begin();
    map<size_t, Node>::iterator last = this->invertedNodes.end();

    for(; itr  != last; itr++) {
        ss << "R" << itr->first << ":" << itr->second.AdjNodeToString() << endl;
    }
    return ss.str();
}