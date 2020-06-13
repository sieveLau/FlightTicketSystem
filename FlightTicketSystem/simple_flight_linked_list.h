#pragma once
#include <stdexcept>
#include <string>

#include "node.h"
#include "simple_flight.h"
namespace ds {

    class SimpleFlightLinkedList {
       public:
        SimpleFlightLinkedList();
        explicit SimpleFlightLinkedList(SimpleFlight sf);
        SimpleFlightLinkedList(const SimpleFlightLinkedList& another);
        ~SimpleFlightLinkedList();
        
        // 只允许插在头部，不提供其他插入
        void Insert(SimpleFlight sf);

        // 删除第一个匹配number的项
        void Delete(std::string flight_number);

        size_t GetLength() const { return length_; }

        // 可以直接修改数据项的Get
        // 找不到会返回nullptr
        ds::SimpleFlight* Get(std::string flight_number) const;

       private:
        Node<ds::SimpleFlight>* head_;
        size_t length_;
    };

}  // namespace sieve
