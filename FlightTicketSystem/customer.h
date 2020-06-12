#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include <sys/types.h>

#include <string>
namespace ds {
    class Customer {
        std::string name_;
        u_int8_t ticket_want_[3];
        u_int8_t ticket_booked_[3];
        std::string flight_number_;

       public:
        enum CANCEL_OPTION { BOOKED, WANT };
        Customer() = delete;
        explicit Customer(std::string name);
        ~Customer();
        Customer(Customer&& another) noexcept;
        Customer(const Customer& another);
        void Swap(Customer& another);
        void Reset();
        Customer& operator=(Customer another);

        std::string GetName();
        u_int8_t GetTicketWantLevel1() const;
        u_int8_t GetTicketWantLevel2() const;
        u_int8_t GetTicketWantLevel3() const;

        void SetTicketWant(u_int8_t level1 = 0, u_int8_t level2 = 0,
                           u_int8_t level3 = 0);
        void SetTicketWant(u_int8_t* level_set);
        void SetTicketBooked(u_int8_t level1 = 0, u_int8_t level2 = 0,
                             u_int8_t level3 = 0);
        void SetTicketBooked(u_int8_t* level_set);
        int CancelTicket(CANCEL_OPTION option, u_int8_t level1 = 0,
                         u_int8_t level2 = 0, u_int8_t level3 = 0);
    };
}  // namespace ds
#endif  // __CUSTOMER_H__