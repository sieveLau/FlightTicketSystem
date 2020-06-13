#include "flight_node.h"
ds::FlightNode::FlightNode(ds::Flight* data, FlightNode* next_node) {
    data_      = data;
    next_node_ = next_node;
}
ds::FlightNode::FlightNode(const FlightNode& another) {
    data_      = new Flight(*another.data_);
    next_node_ = another.next_node_;
}
ds::FlightNode::FlightNode(FlightNode&& another) noexcept {
    data_      = std::move(another.data_);
    next_node_ = another.next_node_;
    another.Reset();
}
void ds::FlightNode::Reset() {
    data_      = nullptr;
    next_node_ = nullptr;
}
void ds::FlightNode::Swap(FlightNode& another) {
    using std::swap;
    swap(data_, another.data_);
    swap(next_node_, another.next_node_);
}
ds::FlightNode& ds::FlightNode::operator=(FlightNode another) {
    Swap(another);
    return *this;
}
ds::FlightNode::~FlightNode() {
    delete data_;
    next_node_ = nullptr;
}
ds::Flight* ds::FlightNode::GetData() const { return data_; }
void ds::FlightNode::SetData(ds::Flight* data) {
    delete data_;
    data_ = data;
}
ds::FlightNode* ds::FlightNode::GetNextNode() { return next_node_; }
void ds::FlightNode::SetNextNode(FlightNode* next_node) {
    next_node_ = next_node;
}
