#ifndef __CUSTOMER_LINKED_LIST_H__
#define __CUSTOMER_LINKED_LIST_H__

#include "customer.h"
#include "defs.h"
#include "node.h"
namespace ds {
    class CustomerLinkedList {
       private:
        Node<Customer*>* head_;
        size_t length_;

       public:
        CustomerLinkedList();
        explicit CustomerLinkedList(Customer* customer);
        CustomerLinkedList(CustomerLinkedList&& customer) noexcept;
        CustomerLinkedList(const CustomerLinkedList& customer);
        ~CustomerLinkedList();
        void Swap(CustomerLinkedList& another);
        void Reset();
        CustomerLinkedList& operator=(CustomerLinkedList another);
    };

}  // namespace ds
#endif  // __CUSTOMER_LINKED_LIST_H__