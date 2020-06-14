#include "customer_linked_list.h"

#include <functional>
#include <iostream>

#include "customer.h"

void ds::CustomerLinkedList::InsertToTail(Customer customer) {
    InsertToTail(new Customer(customer));
}

void ds::CustomerLinkedList::InsertToTail(Customer* customer) {
    if (head_ == nullptr) {
        head_ = new CustomerNode(customer);
        ++length_;
        return;
    }
    auto* current = head_;
    while (current->GetNextNode() != nullptr) {
        current = current->GetNextNode();
    }
    current->SetNextNode(new CustomerNode(customer));
    ++length_;
}
ds::CustomerLinkedList::CustomerLinkedList(bool sorted) {
    head_   = nullptr;
    length_ = 0;
    sorted_ = sorted;
}

ds::CustomerLinkedList::CustomerLinkedList(Customer* customer, bool sorted) {
    head_   = new CustomerNode(customer);
    length_ = 1;
    sorted_ = sorted;
}
ds::CustomerLinkedList::CustomerLinkedList(const CustomerLinkedList& another) {
    auto* current = another.head_;
    sorted_       = another.sorted_;
    head_         = nullptr;
    while (current != nullptr) {
        InsertToTail(*current->GetData());
        current = current->GetNextNode();
    }
    length_ = another.length_;
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
void ds::CustomerLinkedList::Insert(Customer* customer) {
    InsertToTail(customer);
}
void ds::CustomerLinkedList::Insert(Customer customer) {
    InsertToTail(customer);
}
void ds::CustomerLinkedList::InsertSorted(Customer* customer) {
    if (!sorted_)
        throw new std::bad_function_call();
    if (head_ == nullptr) {
        Insert(customer);
        ++length_;
        return;
    }
    auto* current = head_;
    auto* next    = head_;
    while (next != nullptr) {
        if (next->GetData()->GetName() > customer->GetName()) {
            if (next == head_) {
                head_ = new CustomerNode(customer, head_);

                break;
            }
            current->SetNextNode(
                new CustomerNode(customer, current->GetNextNode()));

            break;
        }
        if (next != current) {
            current = current->GetNextNode();
        }
        next = current->GetNextNode();
    }
    if (next == nullptr) {
        current->SetNextNode(new CustomerNode(customer));
    }
    ++length_;
}
void ds::CustomerLinkedList::InsertSorted(Customer customer) {
    Customer* temp_customer = new Customer(std::move(customer));
    InsertSorted(temp_customer);
}
ds::Customer* ds::CustomerLinkedList::Get(std::string customer_name) {
    auto* current = head_;
    while (current != nullptr) {
        if (current->GetData()->GetName() == customer_name) {
            break;
        }
        current = current->GetNextNode();
    }
    if (current == nullptr) {
        std::cerr << "Warning: customer doesn't exist in the list! "
                     "(ds::CustomerLinkedList::Get)";
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
                delete next;
                --length_;
                return;
            }
            current->SetNextNode(next->GetNextNode());
            delete next;
            --length_;
            return;
        }
        if (next != current) {
            current = current->GetNextNode();
        }
        next = current->GetNextNode();
    }
}

namespace ds {
    // 返回包含所有客户的数组，末尾是nullptr
    // 可以修改客户数据，小心使用
    // 不要delete
    Customer** CustomerLinkedList::GetAll() {
        auto* current     = head_;
        Customer** result = new Customer* [length_ + 1] { nullptr };

        for (int i = 0; current != nullptr; i++) {
            result[i] = current->GetData();
            current   = current->GetNextNode();
        }

        return result;
    }
}  // namespace ds