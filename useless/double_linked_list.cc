#include "double_linked_list.h"

#include <memory>
#include <stdexcept>

#include "double_linked_node.h"

namespace sieve {
    DoubleLinkedNode* DoubleLinkedList::GetNode(size_t position) {
        BoundaryCheck(position);

        if (length_ / 2 - position < 0) {
            auto* current = tail_;
            size_t count  = length_;
            while (count != position + 1) {
                current = current->GetPrevNode();
                --count;
            }
        }

        auto* current = head_;
        size_t count  = position;
        while (count != 0) {
            current = current->GetNextNode();
            --count;
        }

        return current;
    }

    void DoubleLinkedList::BoundaryCheck(size_t position) {
        if (position < 0 || position >= length_)
            throw std::out_of_range(
                "sieve::DoubleLinkedList::BoundaryCheck: Out of range.");
    }

    DoubleLinkedList::DoubleLinkedList(int data) {
        head_ = tail_ = new DoubleLinkedNode(data);
        length_       = 1;
    }

    DoubleLinkedList::DoubleLinkedList() {
        head_ = tail_ = nullptr;
        length_       = 0;
    }

    DoubleLinkedList::~DoubleLinkedList() { Clear(); }

    DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList another) {
        Swap(another);
        return *this;
    }
    void DoubleLinkedList::Swap(DoubleLinkedList& another) {
        std::swap(head_, another.head_);
        std::swap(tail_, another.tail_);
        std::swap(length_, another.length_);
        another.Clear();
    }

    void DoubleLinkedList::Insert(int data, size_t position) {
        if (position != length_)
            BoundaryCheck(position);
        if (length_ == 0) {
            head_ = tail_ = new DoubleLinkedNode(data);
        } else if (position == length_) {
            tail_->SetNextNode(new DoubleLinkedNode(data, tail_));
            tail_ = tail_->GetNextNode();
        } else {
            auto* origin_node = GetNode(position);
            auto* new_node    = new DoubleLinkedNode(
                data, origin_node->GetPrevNode(), origin_node);
            if (position != 0) {
                new_node->GetPrevNode()->SetNextNode(new_node);
            } else {
                head_ = new_node;
            }

            origin_node->SetPrevNode(new_node);
        }

        ++length_;
    }

    void DoubleLinkedList::InsertToHead(int data) { Insert(data, 0); }

    void DoubleLinkedList::InsertToTail(int data) { Insert(data, length_); }

    int DoubleLinkedList::Find(int data) {
        auto* current = tail_;
        auto count    = length_ - 1;
        while (count >= 0) {
            if (current->GetData() == data)
                break;
            current = current->GetPrevNode();
            --count;
        }
        return count;
    }

    bool DoubleLinkedList::Has(int data) { return Find(data) != -1; }
    int DoubleLinkedList::Get(size_t position) {
        return GetNode(position)->GetData();
    }
    size_t DoubleLinkedList::Size() const { return length_; }

    void DoubleLinkedList::Delete(size_t position) {
        BoundaryCheck(position);
        if (length_ == 0)
            return;
        auto* target = GetNode(position);
        if (position != 0) {
            target->GetPrevNode()->SetNextNode(target->GetNextNode());
        } else {
            head_ = target->GetNextNode();
        }

        if (position != length_ - 1) {
            target->GetNextNode()->SetPrevNode(target->GetPrevNode());
        } else {
            tail_ = target->GetPrevNode();
        }
        delete target;
        --length_;
    }

    void DoubleLinkedList::Clear() {
        while (length_ != 0) Delete(0);
    }

    std::string DoubleLinkedList::ToString() {
        if (length_ == 0) {
            return std::string("[]");
        }
        std::string result("[");
        auto* current = head_;

        while (current != nullptr) {
            result.append(std::to_string(current->GetData()));
            result.append(",");
            current = current->GetNextNode();
        }
        return result.append("]");
    }
}  // namespace sieve