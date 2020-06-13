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
        
        // ֻ�������ͷ�������ṩ��������
        void Insert(SimpleFlight sf);

        // ɾ����һ��ƥ��number����
        void Delete(std::string flight_number);

        size_t GetLength() const { return length_; }

        // ����ֱ���޸��������Get
        // �Ҳ����᷵��nullptr
        ds::SimpleFlight* Get(std::string flight_number) const;

       private:
        Node<ds::SimpleFlight>* head_;
        size_t length_;
    };

}  // namespace sieve
