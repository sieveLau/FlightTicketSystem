#ifndef __FLIGHT_LINKED_LIST_H__
#define __FLIGHT_LINKED_LIST_H__

#include <vector>

#include "flight.h"
#include "flight_node.h"
namespace ds {
    class FlightLinkedList {
        FlightNode* head_;
        size_t length_;

        Flight* Get(size_t position) {
            auto* current = head_;
            for (size_t i = 0; i < position; i++) {
                if (current != nullptr) {
                    current = current->GetNextNode();
                }
                if (i >= length_) {
                    return nullptr;
                }
            }
            return current->GetData();
        };

       public:
        FlightLinkedList();
        explicit FlightLinkedList(Flight* flight);
        FlightLinkedList(const FlightLinkedList& another);
        FlightLinkedList(FlightLinkedList&& another) noexcept;
        FlightLinkedList& operator=(FlightLinkedList another);
        ~FlightLinkedList();
        void Reset();
        void Swap(FlightLinkedList& anohter);

        // 把flight插入到头部
        void Insert(Flight* flight);
        void Insert(Flight flight);

        bool empty() const { return !(length_); }
        size_t GetLength() const { return length_; }
        Flight** ToArray() {
            auto* current   = head_;
            Flight** result = new Flight*[length_];
            for (size_t i = 0; i < length_; i++) {
                result[i] = current->GetData();
                current   = current->GetNextNode();
            }
            return result;
        }

        void Clear();

        // 根据目的地找飞机，输出所有飞机
        FlightLinkedList* GetByDestination(std::string destination);
    };
}  // namespace ds

#endif  // __FLIGHT_LINKED_LIST_H__