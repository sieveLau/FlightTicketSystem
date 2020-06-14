#include "customer_linked_list.h"

#include <functional>
#include <iostream>

#include "customer.h"

void ds::CustomerLinkedList::InsertToTail(Customer customer) {
    if (head_ == nullptr) {
        head_ = new CustomerNode(new Customer(std::move(customer)));
        ++length_;
        return;
    }
    auto* current = head_;
    while (current->GetNextNode() != nullptr) {
        current = current->GetNextNode();
    }
    current->SetNextNode(new CustomerNode(new Customer(std::move(customer))));
    ++length_;
}

ds::CustomerLinkedList::CustomerLinkedList(bool sorted) {
    head_   = nullptr;
    length_ = 0;
    sorted_ = sorted;
}

ds::CustomerLinkedList::CustomerLinkedList(Customer customer, bool sorted) {
    head_   = new CustomerNode(new Customer(std::move(customer)));
    length_ = 1;
    sorted_ = sorted;
}
ds::CustomerLinkedList::CustomerLinkedList(const CustomerLinkedList& another) {
    auto* current = another.head_;
    head_         = nullptr;
    while (current != nullptr) {
        InsertToTail(*current->GetData());
        current = current->GetNextNode();
    }
    length_ = another.length_;
    sorted_ = another.sorted_;
}
ds::CustomerLinkedList::CustomerLinkedList(
    CustomerLinkedList&& another) noexcept {
    length_ = another.length_;
    head_   = another.head_;
    sorted_ = another.sorted_;
    another.Reset();
}
ds::CustomerLinkedList::~CustomerLinkedList() {
    auto* current = head_;
    while (current != nullptr) {
        head_ = head_->GetNextNode();
        delete current->GetData();
        delete current;
        current = head_;
    }
    length_ = 0;
}
void ds::CustomerLinkedList::Swap(CustomerLinkedList& another) {
    std::swap(head_, another.head_);
    std::swap(length_, another.length_);
}
void ds::CustomerLinkedList::Reset() {
    head_   = nullptr;
    length_ = 0;
}
ds::CustomerLinkedList& ds::CustomerLinkedList::operator=(
    CustomerLinkedList another) {
    Swap(another);
    return *this;
}

void ds::CustomerLinkedList::Insert(Customer customer) {
    InsertToTail(customer);
}

void ds::CustomerLinkedList::InsertSorted(Customer customer) {
    if (!sorted_)
        throw new std::bad_function_call();
    if (head_ == nullptr) {
        Insert(customer);
        return;
    }
    auto* current = head_;
    auto* next    = head_;
    const auto customer_name = customer.GetName();
    while (next != nullptr) {
        if (next->GetData()->GetName() > customer_name) {
            if (next == head_) {
                head_ = new CustomerNode(new Customer(std::move(customer)), head_);
                break;
            }
            current->SetNextNode(
                new CustomerNode(new Customer(std::move(customer)), current->GetNextNode()));
            break;
        }
        if (next != current) { current = current->GetNextNode(); }
        next = current->GetNextNode();
    }
    if (next == nullptr) { current->SetNextNode(new CustomerNode(new Customer(std::move(customer)))); }
    ++length_;
}
ds::Customer* ds::CustomerLinkedList::Get(std::string customer_name) {
    auto* current = head_;
    while (current != nullptr) {
        if (current->GetData()->GetName() == customer_name) { break; }
        current = current->GetNextNode();
    }
    if (current == nullptr) {
        std::cerr << "Warning: customer doesn't exist in the list! "
            "(ds::CustomerLinkedList::Get)"<<std::endl;
        return nullptr;
    }
    return current->GetData();
}
void ds::CustomerLinkedList::Delete(std::string customer_name) {
    auto* current = head_;
    auto* next    = head_;
    while (next != nullptr) {
        if (next->GetData()->GetName() == customer_name) {
            if (next == head_) {
                head_ = head_->GetNextNode();
            }else{current->SetNextNode(next->GetNextNode());}
            
            delete next->GetData();
            delete next;
            --length_;
            return;
        }
        if (next != current) { current = current->GetNextNode(); }
        next = current->GetNextNode();
    }
}

namespace ds {
    
    Customer** CustomerLinkedList::GetAll() {
        auto* current     = head_;
        Customer** result = new Customer* [length_ + 1]{nullptr};

        for (int i = 0; current != nullptr; i++) {
            result[i] = current->GetData();
            current   = current->GetNextNode();
        }

        return result;
    }
} // namespace ds
