#include "customer_linked_list.h"

#include "node.h"

namespace ds {
    CustomerLinkedList::CustomerLinkedList() {
        head_   = nullptr;
        length_ = 0;
    }

    CustomerLinkedList::CustomerLinkedList(Customer* customer) {
        head_   = new Node<Customer*>(customer);
        length_ = 1;
    }

    CustomerLinkedList::CustomerLinkedList(
        CustomerLinkedList&& customer) noexcept {
        head_   = customer.head_;
        length_ = customer.length_;
        customer.Reset();
    }

    CustomerLinkedList::CustomerLinkedList(const CustomerLinkedList& customer) {
        CustomerLinkedList();
        auto* current = customer.head_;
        while (current != nullptr) {
            head_ = new Node<Customer*>(current->GetData(), head_);
        }
    }
}  // namespace ds