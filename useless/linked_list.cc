#include "linked_list.h"

#include <stdexcept>
#include <string>
#define NOTFOUND (-1)

namespace sieve {
    LinkedList::LinkedList() {
        head_   = nullptr;
        length_ = 0;
    }

    LinkedList::LinkedList(int data) {
        head_   = new Node(data, nullptr);
        length_ = 1;
    }

    LinkedList::LinkedList(const LinkedList& another) {
        if (!(&another == this)) {
            head_        = new Node(*another.head_);
            auto* current = head_;
            while (current != nullptr) {
                if (current->GetNextNode() == nullptr)
                    break;
                current->SetNextNode(new Node(*current->GetNextNode()));
                current = current->GetNextNode();
            }
            length_ = another.length_;
        }
    }

    LinkedList::~LinkedList() { while (head_ != nullptr) Delete(0); }

    void LinkedList::Insert(const int data, const size_t position) {
        if (position == 0) {
            Node* new_node = new Node(data, head_);
            head_          = new_node;
        } else {
            Node* pre_node    = GetNode(position - 1);
            Node* origin_node = pre_node->GetNextNode();
            Node* new_node    = new Node(data, origin_node);
            pre_node->SetNextNode(new_node);
        }
        ++length_;
    }

    void LinkedList::InsertToTail(int data) { Insert(data, length_); }

    void LinkedList::InsertToHead(const int data) { Insert(data, 0); }

    int LinkedList::Find(const int data) {
        auto current    = head_;
        size_t position = 0;
        while (current != nullptr && current->GetData() != data) {
            current = current->GetNextNode();
            ++position;
        }
        if (current == nullptr) { return NOTFOUND; }
        return position;
    }

    void LinkedList::Delete(const size_t position) {
        if (position == 0) {
            if (head_ == nullptr)
                return;
            auto* const kOriginNode = head_;
            head_                  = head_->GetNextNode();
            delete kOriginNode;
        } else {
            auto* pre_node = GetNode(position - 1);
            auto* const kOriginNode = pre_node->GetNextNode();
            pre_node->SetNextNode(kOriginNode->GetNextNode());
            delete kOriginNode;
        }
        --length_;
    }

    int LinkedList::GetData(const size_t position) const {
        return GetNode(position)->GetData();
    }

    int* LinkedList::ToArray() const {
        auto* result   = new int[length_];
        auto* current = head_;
        for (size_t i = 0; i < length_; ++i) {
            result[i] = current->GetData();
            current   = current->GetNextNode();
        }
        return result;
    }

    std::string LinkedList::ToString() const {
        if (length_ == 0) { return std::string("[]"); }
        std::string str;
        auto* current = head_;
        str.append("[");

        for (size_t i = 0; i < length_; i++) {
            str.append(std::to_string(current->GetData()));
            str.append(",");
            current = current->GetNextNode();
        }
        str.append("]");
        return str;
    }

    LinkedList& LinkedList::operator=(const LinkedList& another) {
        if (!(&another == this)) {
            head_   = another.head_;
            length_ = another.length_;
        }
        return *this;
    }
} // namespace sieve
