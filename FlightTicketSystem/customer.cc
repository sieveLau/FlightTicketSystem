#include "customer.h"
namespace ds {
    Customer::Customer(std::string name) {
        Reset();
        name_ = name;
    }

    void Customer::Swap(Customer& another) {
        using std::swap;
        swap(name_, another.name_);
        swap(flight_number_, another.flight_number_);
        swap(ticket_want_, another.ticket_want_);
        swap(ticket_booked_, another.ticket_booked_);
    }
    Customer::Customer(const Customer& another) {
        name_ = another.name_;
        for (size_t i = 0; i < 3; i++) {
            ticket_want_[i]   = another.ticket_want_[i];
            ticket_booked_[i] = another.ticket_booked_[i];
        }
        flight_number_ = another.flight_number_;
    }
    Customer::~Customer() { Reset(); }

    Customer::Customer(Customer&& another) noexcept {
        using std::move;
        name_ = move(another.name_);
        for (size_t i = 0; i < 3; i++) {
            ticket_want_[i]   = another.ticket_want_[i];
            ticket_booked_[i] = another.ticket_booked_[i];
        }
        flight_number_ = move(another.flight_number_);
        another.Reset();
    }
    void Customer::Reset() {
        name_ = "";
        for (size_t i = 0; i < 3; i++) {
            ticket_want_[i]   = 0;
            ticket_booked_[i] = 0;
        }
        flight_number_ = "";
    }

    Customer& Customer::operator=(Customer another) {
        Swap(another);
        return *this;
    }

    std::string Customer::GetName() { return name_; }

    u_int8_t Customer::GetTicketWantLevel1() const { return ticket_want_[0]; }
    u_int8_t Customer::GetTicketWantLevel2() const { return ticket_want_[1]; }
    u_int8_t Customer::GetTicketWantLevel3() const { return ticket_want_[2]; }

    void Customer::SetTicketWant(u_int8_t level1, u_int8_t level2,
                                 u_int8_t level3) {
        ticket_want_[0] = level1;
        ticket_want_[1] = level2;
        ticket_want_[2] = level3;
    }

    void Customer::SetTicketWant(u_int8_t* level_set) {
        for (size_t i = 0; i < 3; i++) { ticket_want_[i] = level_set[i]; }
    }
    int Customer::CancelTicket(CANCEL_OPTION option, u_int8_t level1,
                               u_int8_t level2, u_int8_t level3) {
        int16_t result[3];
        result[0] = ticket_want_[0] - level1;
        result[1] = ticket_want_[1] - level2;
        result[2] = ticket_want_[2] - level3;

        for (size_t i = 0; i < 3; i++) {
            if (result[i] < 0) {
                SetTicketWant();
                return -1;
            }
        }

        SetTicketWant((u_int8_t*)result);
        return 0;
    }
}  // namespace ds