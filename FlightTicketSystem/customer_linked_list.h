#pragma once

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
        explicit CustomerLinkedList(Customer customer, bool sorted);
        CustomerLinkedList(const CustomerLinkedList& another);
        CustomerLinkedList(CustomerLinkedList&& another) noexcept;
        ~CustomerLinkedList();
        void Swap(CustomerLinkedList& another);
        void Reset();
        CustomerLinkedList& operator=(CustomerLinkedList another);

        // 无序版
        // FIFO所以适合候补队列
        void Insert(Customer customer);

        // 有序版，按姓名排序
        // 适合已经买票的队列
        void InsertSorted(Customer customer);

        // 假设名字是唯一的，所以只会返回一个Customer
        // 请勿delete
        // 转给别人用请复制
        Customer* Get(std::string customer_name);
        // 返回包含所有客户的数组，末尾是nullptr
    // 可以修改客户数据，小心使用
    // 不要delete内容，务必delete本方法的返回值
        Customer** GetAll();

        void Delete(std::string customer_name);
    };
}  // namespace ds
