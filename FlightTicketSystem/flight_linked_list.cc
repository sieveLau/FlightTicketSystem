#include "flight_linked_list.h"

#include <utility>

#include "flight.h"
#include "flight_node.h"
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
        while (current!=nullptr) {
            head_ = current->GetNextNode();
            delete current->GetData();
            delete current;
            current = head_;
            --length_;
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
        auto* current = another.head_;
        // 用值传递的Insert来复制FlightNode
        while (current != nullptr) {
            Insert(*current->GetData());
            current = current->GetNextNode();
        }
    }

    void FlightLinkedList::Insert(Flight flight) {
        head_ = new FlightNode(new Flight(std::move(flight)), head_);
        ++length_;
    }
    Flight** FlightLinkedList::ToArray() {
            auto* current   = head_;
            Flight** result = new Flight*[length_]{nullptr};
            for (size_t i = 0; current!=nullptr;++i) {
                result[i] = current->GetData();
                current   = current->GetNextNode();
            }
            return result;
        }
    void FlightLinkedList::Clear() {
        while (head_ != nullptr) {
            auto* current = head_->GetNextNode();
            delete head_->GetData();
            delete head_;
            head_ = current;
            --length_;
        }
    }
    Flight** FlightLinkedList::GetByDestination(std::string destination) {
        auto* current = head_;
        Flight** result  = new Flight*[length_+1]{nullptr};
        size_t i = 0;
        while (current != nullptr) {
            if (current->GetData()->GetDestination() == destination) {
                result[i++] = current->GetData();
            }
            current = current->GetNextNode();
        }
        return result;
    }

    // 如果找不到，返回nullptr
    Flight* FlightLinkedList::GetByFlightNumber(std::string flight_number) {
        auto* current = head_;
        while (current != nullptr) {
            auto* data = current->GetData();
            if ((*data).GetFlightNumber() == flight_number) {
                return data;
            }
            current = current->GetNextNode();
        }
        return nullptr;
    }
}  // namespace ds