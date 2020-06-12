#include "simple_flight_linked_list.h"

#include "node.h"
#include "simple_flight.h"

namespace sieve {
    SimpleFlightLinkedList::SimpleFlightLinkedList(dc::SimpleFlight sf) {
        head_   = new Node<dc::SimpleFlight>(sf);
        length_ = 1;
    }

    void SimpleFlightLinkedList::Insert(dc::SimpleFlight sf) {
        head_ = new Node<dc::SimpleFlight>(sf, head_);
        ++length_;
    }

    void SimpleFlightLinkedList::Delete(std::string flight_number) {
        auto* current = head_;
        auto* next    = current;
        while (next != nullptr) {
            if (next->GetData()->GetFlightNumber() == flight_number) {
                if (next == head_) {
                    head_ = head_->GetNextNode();
                }
                current->SetNextNode(next->GetNextNode());

                delete next;
                --length_;
                return;
            };
            next = next->GetNextNode();
            if (next != current)
                current = current->GetNextNode();
        }
    }

    dc::SimpleFlight* SimpleFlightLinkedList::Get(
        std::string flight_number) const {
        auto* current = head_;
        while (current != nullptr) {
            if (current->GetData()->GetFlightNumber() == flight_number) {
                return current->GetData();
            }
            current = current->GetNextNode();
        }
        return nullptr;
    }
}  // namespace sieve