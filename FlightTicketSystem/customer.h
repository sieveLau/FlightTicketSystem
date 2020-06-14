#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <string>

#include "defs.h"
#include "simple_flight_linked_list.h"
namespace ds {
    class Customer {
        std::string name_;
        SimpleFlightLinkedList* sfll_;

       public:
        Customer() = delete;
        explicit Customer(std::string name);
        ~Customer();
        Customer(Customer&& another) noexcept;
        Customer(const Customer& another);
        void Swap(Customer& another);
        void Reset();
        Customer& operator=(Customer another);

        std::string GetName() const { return name_; }

        uint8_t* GetSeatWant(std::string flight_number);
        uint8_t* GetSeatBooked(std::string flight_number);

        bool HasWant();
        bool HasBooked();

        void SetSeatWant(std::string flight_number, uint8_t level1,
                         uint8_t level2, uint8_t level3);

        void SetSeatWant(std::string flight_number, uint8_t* levelset);

        void SetSeatBooked(std::string flight_number, uint8_t level1,
                           uint8_t level2, uint8_t level3);

        void SetSeatBooked(std::string flight_number, uint8_t* levelset);
    };
}  // namespace ds
#endif  // __CUSTOMER_H__