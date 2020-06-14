#pragma once
#include <stdexcept>
#include <string>

#include "node.h"
#include "simple_flight.h"
#include "simple_flight_node.h"

namespace ds {
    // LinkedList存的是输入的副本，原来的东西根本不管
    class SimpleFlightLinkedList {
       public:
        SimpleFlightLinkedList();
        explicit SimpleFlightLinkedList(SimpleFlight sf);
        SimpleFlightLinkedList(const SimpleFlightLinkedList& another);
        SimpleFlightLinkedList(SimpleFlightLinkedList&& another) noexcept;
        SimpleFlightLinkedList& operator=(SimpleFlightLinkedList another);
        void Swap(SimpleFlightLinkedList& another);
        void Reset();
        ~SimpleFlightLinkedList();

        // 只允许插在头部，不提供其他插入
        // 是复制品
        void Insert(SimpleFlight sf);

        // 删除第一个匹配number的项
        void Delete(std::string flight_number);

        size_t GetLength() const { return length_; }

        // 可以直接修改数据项的Get
        // 找不到会返回nullptr
        // 请勿delete
        ds::SimpleFlight* Get(std::string flight_number) const;

        //生成新的array
        // 请务必delete
        ds::SimpleFlight** ToArray() const;

        void Clear();

       private:
        SimpleFlightNode* head_;
        size_t length_;
    };

}  // namespace ds
