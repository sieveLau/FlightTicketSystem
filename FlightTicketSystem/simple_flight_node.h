#pragma once
#include <memory>

#include "simple_flight.h"
namespace ds {
    class SimpleFlightNode {
       public:
        SimpleFlightNode() = delete;
        explicit SimpleFlightNode(ds::SimpleFlight* data, SimpleFlightNode* next_node = nullptr);

        SimpleFlightNode(const SimpleFlightNode& another);

        SimpleFlightNode(SimpleFlightNode&& another) noexcept;
        void Reset();
        void Swap(SimpleFlightNode& another);
        SimpleFlightNode& operator=(SimpleFlightNode another);
        ~SimpleFlightNode();

        // 返回指针，可以直接修改数据
        ds::SimpleFlight* GetData() const;
        // 把原来的delete，再用复制构造器新建一个
        void SetData(ds::SimpleFlight* data);

        SimpleFlightNode* GetNextNode();

        void SetNextNode(SimpleFlightNode* next_node);

        

       private:
        ds::SimpleFlight* data_;
        SimpleFlightNode* next_node_;
    };
}  // namespace ds