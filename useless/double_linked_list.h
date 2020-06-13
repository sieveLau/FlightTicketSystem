#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include <cstddef>
#include <string>

#include "double_linked_node.h"
namespace sieve {
    class DoubleLinkedNode;
    class DoubleLinkedList {
        DoubleLinkedNode* head_;
        DoubleLinkedNode* tail_;
        size_t length_;
        DoubleLinkedNode* GetNode(size_t position);
        void BoundaryCheck(size_t position);

       public:
        explicit DoubleLinkedList(int data);
        DoubleLinkedList();
        ~DoubleLinkedList();
        DoubleLinkedList& operator=(DoubleLinkedList another);
        void Swap(DoubleLinkedList& another);

        void Insert(int data, size_t position);
        void InsertToHead(int data);
        void InsertToTail(int data);

        int Find(int data);
        bool Has(int data);

        int Get(size_t position);
        size_t Size() const;

        void Delete(size_t position);
        void Clear();

        std::string ToString();
    };
}  // namespace sieve

#endif  // __DOUBLE_LINKED_LIST_H__