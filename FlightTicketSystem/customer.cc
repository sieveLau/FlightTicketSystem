#include "customer.h"

namespace ds {
    Customer::Customer(std::string name) {

        name_ = name;
        sfll_ = new SimpleFlightLinkedList();
    }

    Customer::~Customer() {
        name_ = "";
        delete sfll_;
    }

    Customer::Customer(Customer&& another) noexcept {
        name_ = another.name_;
        sfll_ = another.sfll_;
        another.Reset();
    }

    Customer::Customer(const Customer& another) {
        name_ = another.name_;
        sfll_ = new SimpleFlightLinkedList(*another.sfll_);
    }

    void Customer::Swap(Customer& another) {
        using  std::swap;
        swap(name_, another.name_);
        swap(sfll_, another.sfll_);
    }

    void Customer::Reset()
    { 
        name_ = "";
        delete sfll_;
    }

    Customer& Customer::operator=(Customer another) { 
        Swap(another);
        return *this;
    }

    uint8_t* Customer::GetSeatWant(std::string flight_number)
    {
        auto* sf = sfll_->Get(flight_number);
        if (sf == nullptr)
            return nullptr;
        return sf->GetSeatWant();
    }

    uint8_t* Customer::GetSeatBooked(std::string flight_number)
    {
        auto* sf = sfll_->Get(flight_number);
        if (sf == nullptr)
            return nullptr;
        return sf->GetSeatBooked();
    }

    // 按航班号写入需求的座位数
    // 如果航班号不存在，会新建再插入
    void Customer::SetSeatWant(std::string flight_number, uint8_t level1,
        uint8_t level2, uint8_t level3)
    {
        SimpleFlight* sf1 = sfll_->Get(flight_number);
        if (sf1 == nullptr)
        {
            uint8_t seat_want[3] = {level1, level2, level3};
            sfll_->Insert(
                SimpleFlight(flight_number, seat_want));
        } else {
            sf1->SetSeatWant(level1, level2, level3);
        }
        

    }

    void Customer::SetSeatWant(std::string flight_number, uint8_t* levelset)
    {
        SimpleFlight* sf1 = sfll_->Get(flight_number);
        if (sf1 == nullptr) {
            
            sfll_->Insert(SimpleFlight(flight_number, levelset));
        } else {
            sf1->SetSeatWant(levelset);
        }
    }


    void Customer::SetSeatBooked(std::string flight_number, uint8_t level1,
                                 uint8_t level2, uint8_t level3) {
        SimpleFlight* sf1 = sfll_->Get(flight_number);
        if (sf1 == nullptr) {
            uint8_t seat_booked[3] = {level1, level2, level3};
            sfll_->Insert(SimpleFlight(flight_number, nullptr,seat_booked));
        } else {
            sf1->SetSeatBooked(level1, level2, level3);
        }
    }

    void Customer::SetSeatBooked(std::string flight_number, uint8_t* levelset) {
        SimpleFlight* sf1 = sfll_->Get(flight_number);
        if (sf1 == nullptr) {
            sfll_->Insert(SimpleFlight(flight_number, nullptr,levelset));
        } else {
            sf1->SetSeatBooked(levelset);
        }
    }


} // namespace ds
