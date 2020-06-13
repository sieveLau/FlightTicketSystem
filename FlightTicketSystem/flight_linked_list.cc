#include "flight_linked_list.h"

#include <utility>

#include "flight.h"
#include "node.h"
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
            Insert(*(current->GetData()));
            current = current->GetNextNode();
        }
    }
    FlightLinkedList::FlightLinkedList(Flight* flight) {
        FlightLinkedList();
        Insert(flight);
    }

    void FlightLinkedList::Insert(Flight* flight) {
        head_ = new Node<Flight*>(flight, head_);
        ++length_;
    }

    void FlightLinkedList::Insert(Flight flight) {
        head_ = new Node<Flight*>(new Flight(std::move(flight)), head_);
        ++length_;
    }
    void FlightLinkedList::Clear() {
        while (head_ != nullptr) {
            auto* current = head_->GetNextNode();
            delete head_;
            head_ = current;
            --length_;
        }
    }
    FlightLinkedList* FlightLinkedList::GetByDestination(
        std::string destination) {
        auto* current = head_;
        auto* result  = new FlightLinkedList;
        while (current != nullptr) {
            auto* data = current->GetData();
            if ((*data).GetDestination() == destination) {
                result->Insert(data);
            }
            current = current->GetNextNode();
        }
        return result;
    }
}  // namespace ds