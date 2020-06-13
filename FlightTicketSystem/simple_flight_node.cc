#include "simple_flight_node.h"
ds::SimpleFlightNode::SimpleFlightNode(ds::SimpleFlight* data, SimpleFlightNode* next_node) {
    data_      = data;
    next_node_ = next_node;
}
ds::SimpleFlightNode::SimpleFlightNode(const SimpleFlightNode& another) {
    data_      = new SimpleFlight(*another.data_);
    next_node_ = another.next_node_;
}
ds::SimpleFlightNode::SimpleFlightNode(SimpleFlightNode&& another) noexcept {
    data_      = std::move(another.data_);
    next_node_ = another.next_node_;
    another.Reset();
}
void ds::SimpleFlightNode::Reset() {
    data_      = nullptr;
    next_node_ = nullptr;
}
void ds::SimpleFlightNode::Swap(SimpleFlightNode& another) {
    using std::swap;
    swap(data_, another.data_);
    swap(next_node_, another.next_node_);
}
ds::SimpleFlightNode& ds::SimpleFlightNode::operator=(SimpleFlightNode another) {
    Swap(another);
    return *this;
}
ds::SimpleFlightNode::~SimpleFlightNode() {
    delete data_;
    next_node_ = nullptr;
}
ds::SimpleFlight* ds::SimpleFlightNode::GetData() const { return data_; }
void ds::SimpleFlightNode::SetData(ds::SimpleFlight* data) {
    delete data_;
    data_ = data;
}
ds::SimpleFlightNode* ds::SimpleFlightNode::GetNextNode() { return next_node_; }
void ds::SimpleFlightNode::SetNextNode(SimpleFlightNode* next_node) {
    next_node_ = next_node;
}
