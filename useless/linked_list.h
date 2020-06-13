#pragma once
#include <stdexcept>
#include <string>

#include "node.h"
namespace sieve {
    class LinkedList {
       public:
        LinkedList();
        explicit LinkedList(int data);
        LinkedList(const LinkedList& another);
        ~LinkedList();
        void Insert(int data, size_t position);
        void InsertToTail(int data);
        void InsertToHead(int data);
        int Find(int data);
        // bool Has(int data);
        void Delete(size_t position);
        size_t GetLength() const { return length_; };
        int GetData(size_t position) const;

        int* ToArray() const;
        std::string ToString() const;

        LinkedList& operator=(const LinkedList& another);

       private:
        Node* head_;
        size_t length_;
        Node* GetNode(size_t position) const;

        friend class SortedLinkedList;
    };

    inline Node* LinkedList::GetNode(const size_t position) const {
        if (position >= length_ || position < 0)
            throw std::out_of_range(
                "Out of range, check your call. In: "
                "sieve::LinkedList::GetNode()");
        size_t i     = 0;
        auto current = head_;
        while (i != position && i < length_) {
            current = current->GetNextNode();
            ++i;
        }
        return current;
    }
}  // namespace sieve
