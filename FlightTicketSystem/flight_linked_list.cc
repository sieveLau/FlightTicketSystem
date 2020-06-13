#include "flight_linked_list.h"

#include "flight.h"
namespace ds {
    FlightLinkedList::FlightLinkedList() {
        head_   = nullptr;
        length_ = 0;
    }

    FlightLinkedList& FlightLinkedList::operator=(FlightLinkedList another) {
        Swap(another);
        return *this;
    }

    FlightLinkedList::~FlightLinkedList() {
        auto* current = head_;
        while (current != nullptr) {
            head_ = current->GetNextNode();
            delete current;
            current = head_;
        }
        length_ = 0;
    }
    void FlightLinkedList::Reset() {
        length_ = 0;
        head_   = nullptr;
    }

    void FlightLinkedList::Swap(FlightLinkedList& another) {
        std::swap(head_, another.head_);
        length_ = another.length_;
    }
    FlightLinkedList::FlightLinkedList(FlightLinkedList&& another) noexcept {
        length_ = another.length_;
        head_   = another.head_;
        another.Reset();
    }
    FlightLinkedList::FlightLinkedList(const FlightLinkedList& another) {
        FlightLinkedList();
        auto* current = another.head_;
        while (current != nullptr) {
            Insert(*current->GetData());
            current = current->GetNextNode();
        }
    }
    FlightLinkedList::FlightLinkedList(Flight flight) {
        FlightLinkedList();
        Insert(std::move(flight));
    }

    void FlightLinkedList::Insert(Flight flight) {
        head_ = new Node<Flight>(std::move(flight), head_);
        ++length_;
    }

    std::vector<Flight*> FlightLinkedList::GetByDestination(
        std::string destination) {
        auto* current = head_;
        std::vector<Flight*> result;
        while (current != nullptr) {
            auto* data = current->GetData();
            if (data->GetDestination() == destination) {
                result.push_back(data);
            }
            current = current->GetNextNode();
        }
        return result;
    }
}  // namespace ds