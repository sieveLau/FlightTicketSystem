#pragma once
#include <memory>

#include "flight.h"
namespace ds {
    class FlightNode {
       public:
        FlightNode() = delete;
        explicit FlightNode(ds::Flight* data, FlightNode* next_node = nullptr);

        FlightNode(const FlightNode& another);

        FlightNode(FlightNode&& another) noexcept;
        void Reset();
        void Swap(FlightNode& another);
        FlightNode& operator=(FlightNode another);

        // 返回指针，可以直接修改数据
        ds::Flight* GetData() const;
        // 把原来的delete，再用复制构造器新建一个
        void SetData(ds::Flight* data);

        FlightNode* GetNextNode();

        void SetNextNode(FlightNode* next_node);

        ~FlightNode();

       private:
        ds::Flight* data_;
        FlightNode* next_node_;
    };
}  // namespace ds