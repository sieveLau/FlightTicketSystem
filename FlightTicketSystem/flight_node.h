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
        ~FlightNode();

        // 返回指针，可以直接修改数据
        ds::Flight* GetData() const;

        FlightNode* GetNextNode();

        void SetNextNode(FlightNode* next_node);

       private:
        ds::Flight* data_;
        FlightNode* next_node_;
    };
}  // namespace ds