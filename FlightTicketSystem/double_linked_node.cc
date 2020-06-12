#include "double_linked_node.h"

#include <memory>

namespace sieve {
    DoubleLinkedNode::DoubleLinkedNode(int data, DoubleLinkedNode* prev_node,
                                       DoubleLinkedNode* next_node)
        : data_(data), next_node_(next_node), prev_node_(prev_node) {}

    DoubleLinkedNode::DoubleLinkedNode(DoubleLinkedNode&& another) noexcept {
        data_      = another.data_;
        next_node_ = another.next_node_;
        prev_node_ = another.prev_node_;
        another.Reset();
    }
    DoubleLinkedNode::DoubleLinkedNode(const DoubleLinkedNode& another) {
        data_      = another.data_;
        prev_node_ = another.prev_node_;
        next_node_ = another.next_node_;
    }

    DoubleLinkedNode::~DoubleLinkedNode() { Reset(); }

    void DoubleLinkedNode::SetData(int data) { data_ = data; }

    void DoubleLinkedNode::SetNextNode(DoubleLinkedNode* node) {
        next_node_ = node;
    }

    void DoubleLinkedNode::SetPrevNode(DoubleLinkedNode* node) {
        prev_node_ = node;
    }

    int DoubleLinkedNode::GetData() const { return data_; }

    DoubleLinkedNode* DoubleLinkedNode::GetNextNode() const {
        return next_node_;
    }

    DoubleLinkedNode* DoubleLinkedNode::GetPrevNode() const {
        return prev_node_;
    }

    void DoubleLinkedNode::Reset() {
        data_      = 0;
        next_node_ = nullptr;
        prev_node_ = nullptr;
    }
    DoubleLinkedNode& DoubleLinkedNode::operator=(DoubleLinkedNode another) {
        swap(another);
        return *this;
    }

    void DoubleLinkedNode::swap(DoubleLinkedNode& another) {
        std::swap(data_, another.data_);
        std::swap(next_node_, another.next_node_);
        std::swap(prev_node_, another.prev_node_);
    }
}  // namespace sieve
