#include "node.h"

#include <memory>

Node::Node(int data) : data_(data), next_node_(nullptr) {}

Node::Node(int data, Node* nextnode) : data_(data), next_node_(nextnode) {}

Node::Node(const Node& another) {
    data_      = another.data_;
    next_node_ = another.next_node_;
}

int Node::GetData() const { return data_; }

void Node::SetData(int data) { data_ = data; }

Node* Node::GetNextNode() { return next_node_; }

void Node::SetNextNode(Node* next_node) { next_node_ = next_node; }

Node::~Node() {
    data_      = 0;
    next_node_ = nullptr;
}

Node& Node::operator=(const Node& another) {
    if (!(&another == this)) {
        data_      = another.data_;
        next_node_ = another.next_node_;
    }
    return *this;
}
