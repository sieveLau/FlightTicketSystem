#pragma once
#include <stdexcept>
#include <string>

#include "node.h"
#include "simple_flight.h"
namespace sieve {

    class SimpleFlightLinkedList {
       public:
        SimpleFlightLinkedList() = delete;
        explicit SimpleFlightLinkedList(dc::SimpleFlight sf);
        // SimpleFlightLinkedList(const SimpleFlightLinkedList& another);
        ~SimpleFlightLinkedList();
        void Insert(dc::SimpleFlight sf);
        void Delete(std::string flight_number);
        size_t GetLength() const { return length_; };
        dc::SimpleFlight* Get(std::string flight_number) const;

       private:
        Node<dc::SimpleFlight>* head_;
        size_t length_;
    };

}  // namespace sieve
