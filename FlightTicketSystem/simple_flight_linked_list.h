#pragma once
#include <stdexcept>
#include <string>

#include "node.h"
#include "simple_flight.h"
#include "simple_flight_node.h"

namespace ds {
    // LinkedList���������ĸ�����ԭ���Ķ�����������
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

        // ֻ�������ͷ�������ṩ��������
        // �Ǹ���Ʒ
        void Insert(SimpleFlight sf);

        // ɾ����һ��ƥ��number����
        void Delete(std::string flight_number);

        size_t GetLength() const { return length_; }

        // ����ֱ���޸��������Get
        // �Ҳ����᷵��nullptr
        // ����delete
        ds::SimpleFlight* Get(std::string flight_number) const;

        //�����µ�array
        // �����delete
        ds::SimpleFlight** ToArray() const;

        void Clear();

       private:
        SimpleFlightNode* head_;
        size_t length_;
    };

}  // namespace ds
