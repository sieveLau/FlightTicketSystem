#pragma once
#include <bits/stdint-uintn.h>

#include <array>
#include <cstddef>

#include "customer_node.h"
namespace ds {
    class CustomerLinkedList {
        CustomerNode* head_;
        size_t length_;
        bool sorted_;

        void InsertToTail(Customer customer);
        void InsertToTail(Customer* customer);

       public:
        explicit CustomerLinkedList(bool sorted);
        explicit CustomerLinkedList(Customer* customer, bool sorted = false);
        CustomerLinkedList(const CustomerLinkedList& another);
        CustomerLinkedList(CustomerLinkedList&& another) noexcept;
        ~CustomerLinkedList();
        void Swap(CustomerLinkedList& another);
        void Reset();
        CustomerLinkedList& operator=(CustomerLinkedList another);

        // 无序版
        // FIFO所以适合候补队列
        void Insert(Customer* customer);
        void Insert(Customer customer);

        // 有序版，按姓名排序
        // 适合已经买票的队列
        void InsertSorted(Customer* customer);
        void InsertSorted(Customer customer);

        // 假设名字是唯一的，所以只会返回一个Customer
        Customer* Get(std::string customer_name);
        Customer** GetAll();

        void Delete(std::string customer_name);
    };
}  // namespace ds
