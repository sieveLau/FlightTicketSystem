#ifndef __FLIGHT_LINKED_LIST_H__
#define __FLIGHT_LINKED_LIST_H__

#include <vector>

#include "flight.h"
#include "node.h"
namespace ds {
    class FlightLinkedList {
        Node<Flight>* head_;
        size_t length_;

       public:
        FlightLinkedList();
        FlightLinkedList(Flight flight);
        FlightLinkedList(const FlightLinkedList& another);
        FlightLinkedList(FlightLinkedList&& another) noexcept;
        FlightLinkedList& operator=(FlightLinkedList another);
        ~FlightLinkedList();
        void Reset();
        void Swap(FlightLinkedList& anohter);

        // 把flight插入到头部
        void Insert(Flight flight);

        // 根据目的地找飞机，输出所有飞机
        std::vector<Flight*> GetByDestination(std::string destination);
    };
}  // namespace ds

#endif  // __FLIGHT_LINKED_LIST_H__