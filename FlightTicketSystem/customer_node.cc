#include "customer_node.h"
ds::CustomerNode::CustomerNode(ds::Customer* data, CustomerNode* next_node) {
    data_      = data;
    next_node_ = next_node;
}
ds::CustomerNode::CustomerNode(const CustomerNode& another) {
    data_      = new Customer(*another.data_);
    next_node_ = another.next_node_;
}
ds::CustomerNode::CustomerNode(CustomerNode&& another) noexcept {
    data_      = another.data_;
    next_node_ = another.next_node_;
    another.Reset();
}
void ds::CustomerNode::Reset() {
    data_      = nullptr;
    next_node_ = nullptr;
}
void ds::CustomerNode::Swap(CustomerNode& another) {
    using std::swap;
    swap(data_, another.data_);
    swap(next_node_, another.next_node_);
}
ds::CustomerNode& ds::CustomerNode::operator=(CustomerNode another) {
    Swap(another);
    return *this;
}
ds::CustomerNode::~CustomerNode() {
    data_ = nullptr;
    next_node_ = nullptr;
}
ds::Customer* ds::CustomerNode::GetData() const { return data_; }

ds::CustomerNode* ds::CustomerNode::GetNextNode() { return next_node_; }
void ds::CustomerNode::SetNextNode(CustomerNode* next_node) {
    next_node_ = next_node;
}
