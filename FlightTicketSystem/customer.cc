#include "customer.h"

#include "simple_flight.h"

namespace ds {
    Customer::Customer(std::string name) { name_ = name; }

    Customer::~Customer() { name_ = ""; }

    Customer::Customer(Customer&& another) noexcept {
        name_       = another.name_;
        want_list   = std::move(another.want_list);
        booked_list = std::move(another.booked_list);
        another.Reset();
    }

    Customer::Customer(const Customer& another) {
        name_       = another.name_;
        want_list   = another.want_list;
        booked_list = another.booked_list;
    }

    void Customer::Swap(Customer& another) {
        using std::swap;
        swap(name_, another.name_);
        swap(booked_list, another.booked_list);
        swap(want_list, another.want_list);
    }

    void Customer::Reset() {
        name_ = "";
        want_list.Clear();
        booked_list.Clear();
    }

    Customer& Customer::operator=(Customer another) {
        Swap(another);
        return *this;
    }

    //务必delete
    uint8_t* Customer::GetSeatWant(std::string flight_number) {
        auto* sf = want_list.Get(flight_number);
        if (sf == nullptr)
            return new uint8_t[3]{0,0,0};
        return sf->GetSeat();
    }

    // 返回的数组无法用于修改已订票数量，且务必delete
    // 如果要修改，请使用Customer::SetSeatBooked
    uint8_t* Customer::GetSeatBooked(std::string flight_number) {
        auto* sf = booked_list.Get(flight_number);
        if (sf == nullptr)
            return new uint8_t[3]{0,0,0};
        return sf->GetSeat();
    }

    bool Customer::HasWant() {
        if (want_list.GetLength() == 0)
            return false;
        return true;
    }

    bool Customer::HasBooked() {
        if (booked_list.GetLength() == 0)
            return false;
        return true;
    }


    void Customer::SetSeatWant(std::string flight_number, uint8_t level1,
                               uint8_t level2, uint8_t level3) {
        SimpleFlight* sf1 = want_list.Get(flight_number);
        uint8_t seat_want[3] = {level1, level2, level3};
        if (sf1 == nullptr) {
            
            want_list.Insert(SimpleFlight(flight_number, seat_want));
        } else { sf1->SetSeat(seat_want); }
    }

    void Customer::SetSeatWant(std::string flight_number, uint8_t* levelset) {
        SimpleFlight* sf1 = want_list.Get(flight_number);
        if (sf1 == nullptr) {
            want_list.Insert(SimpleFlight(flight_number, levelset));
        } else { sf1->SetSeat(levelset); }
    }

    void Customer::SetSeatBooked(std::string flight_number, uint8_t level1,
                                 uint8_t level2, uint8_t level3) {
        SimpleFlight* sf1 = booked_list.Get(flight_number);
        uint8_t seat_booked[3] = {level1, level2, level3};
        if (sf1 == nullptr) {
            
            booked_list.Insert(SimpleFlight(flight_number, seat_booked));
        } else { sf1->SetSeat(level1, level2, level3); }
    }

    void Customer::SetSeatBooked(std::string flight_number, uint8_t* levelset) {
        SimpleFlight* sf1 = booked_list.Get(flight_number);
        if (sf1 == nullptr) {
            booked_list.Insert(SimpleFlight(flight_number, levelset));
        } else { sf1->SetSeat(levelset); }
    }

} // namespace ds
