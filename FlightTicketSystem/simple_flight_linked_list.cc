#include "simple_flight_linked_list.h"

#include "node.h"
#include "simple_flight.h"

namespace ds {
    SimpleFlightLinkedList::SimpleFlightLinkedList() { head_ = nullptr;
        length_ = 0;
    }

    SimpleFlightLinkedList::SimpleFlightLinkedList(ds::SimpleFlight sf) {
        head_   = new Node<ds::SimpleFlight>(sf);
        length_ = 1;
    }

    SimpleFlightLinkedList::SimpleFlightLinkedList(
        const SimpleFlightLinkedList& another) {
        length_       = 0;
        head_         = nullptr;
        auto* current = another.head_;
        while (current!=nullptr) { Insert(*(current->GetData()));
            current = current->GetNextNode();
        }
    }

    SimpleFlightLinkedList::~SimpleFlightLinkedList() {
        auto* current = head_;
        while (current != nullptr) {
            head_ = current->GetNextNode();
            delete current;
            current = head_;
        }
        length_ = 0;
    }

    void SimpleFlightLinkedList::Insert(ds::SimpleFlight sf) {
        head_ = new Node<ds::SimpleFlight>(sf, head_);
        ++length_;
    }

    void SimpleFlightLinkedList::Delete(std::string flight_number) {
        auto* current = head_;
        auto* next    = current;
        while (next != nullptr) {
            if (next->GetData()->GetFlightNumber() == flight_number) {
                if (next == head_) { head_ = head_->GetNextNode(); }
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

    ds::SimpleFlight* SimpleFlightLinkedList::Get(
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
} // namespace sieve
