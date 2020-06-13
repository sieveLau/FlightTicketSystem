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

        // ����ָ�룬����ֱ���޸�����
        ds::SimpleFlight* GetData() const;
        // ��ԭ����delete�����ø��ƹ������½�һ��
        void SetData(ds::SimpleFlight* data);

        SimpleFlightNode* GetNextNode();

        void SetNextNode(SimpleFlightNode* next_node);

        

       private:
        ds::SimpleFlight* data_;
        SimpleFlightNode* next_node_;
    };
}  // namespace ds