#pragma once
#include <memory>

#include "simple_flight.h"
namespace ds {
    // Node本身并不会删除数据，Node只是方便构建结构
    // Node只会删掉自己，不会删data
    class SimpleFlightNode {
       public:
        SimpleFlightNode() = delete;
        explicit SimpleFlightNode(ds::SimpleFlight* data,
                                  SimpleFlightNode* next_node = nullptr);

        SimpleFlightNode(const SimpleFlightNode& another);

        SimpleFlightNode(SimpleFlightNode&& another) noexcept;
        void Reset();
        void Swap(SimpleFlightNode& another);
        SimpleFlightNode& operator=(SimpleFlightNode another);
        ~SimpleFlightNode();

        // 返回指针，可以直接修改数据
        ds::SimpleFlight* GetData() const;

        SimpleFlightNode* GetNextNode();

        void SetNextNode(SimpleFlightNode* next_node);

       private:
        ds::SimpleFlight* data_;
        SimpleFlightNode* next_node_;
    };
}  // namespace ds