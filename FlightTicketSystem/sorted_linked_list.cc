
#include "sorted_linked_list.h"

#include <memory>

namespace sieve {

    SortedLinkedList::SortedLinkedList() { ll_ = new LinkedList(); }

    SortedLinkedList::SortedLinkedList(const SortedLinkedList& source) {
        ll_ = new LinkedList(*source.ll_);
    }

    SortedLinkedList::SortedLinkedList(const int data) { ll_ = new LinkedList(data); }

    SortedLinkedList::SortedLinkedList(const LinkedList& ll) {
        ll_           = new LinkedList();
        auto* current = ll.head_;
        for (size_t i = 0; i < ll.GetLength(); i++) {
            Insert(current->GetData());
            current = current->GetNextNode();
        }
    }

    void SortedLinkedList::Insert(int data) {
        const auto kLength = GetLength();

        //空表，直接插入在第一个
        // 非空，如果第一个大于要插入的，插在第一个
        auto* current = ll_->head_;
        if (kLength == 0 || current->GetData() - data > 0) {
            ll_->InsertToHead(data);
            return;
        }

        
        // 非空，要找插入的地方
        for (;;) {
            auto* next = current->GetNextNode();
            // data要插在current后一个位置

            if (next == nullptr) {
                ll_->InsertToTail(data);
                return;
            }

            // 下一个的值比data小，那就下一个循环
            if (next->GetData() <= data) {
                current = next;
            } else {
                // 下一个的值比data大，确定位置就是current后一个
                current->SetNextNode(new Node(data, next));
                ++(ll_->length_);
                return;
            }
        }
    }

    SortedLinkedList& SortedLinkedList::operator=(
        const SortedLinkedList& another) {
        delete ll_;
        ll_ = another.ll_;
        return *this;
    }
}  // namespace sieve