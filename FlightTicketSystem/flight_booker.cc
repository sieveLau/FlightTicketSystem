#include "flight_booker.h"
#include <string>
#include <iostream>
void ds::Check(std::string flight_number, uint8_t want_level1,
               uint8_t want_level2, uint8_t want_level3,
               std::string customer_name, FlightLinkedList* flights,
               CustomerLinkedList* customers_booked,
               CustomerLinkedList* customers_waiting) {
    auto* flight = flights->GetByFlightNumber(flight_number);
    auto avail1  = flight->GetAvailLevel1();
    auto avail2  = flight->GetAvailLevel2();
    auto avail3  = flight->GetAvailLevel3();

    //如果够票，就给他订
    if (avail1 >= want_level1 && avail2 >= want_level2 &&
        avail3 >= want_level3) {
        // 先看看这个人是不是已经订了票
        Customer* customer = customers_booked->Get(customer_name);

        // 没订过，新建一个
        if (customer == nullptr) {
            Customer customer(customer_name);
            customer.SetSeatBooked(flight_number, want_level1, want_level2,
                                   want_level3);

            customers_booked->InsertSorted(customer);
        } else {
            //订过了，拿已经订过的原数加上现在新要的，设置回去
            uint8_t* current_booked = customer->GetSeatBooked(flight_number);
            customer->SetSeatBooked(flight_number,
                                    current_booked[0] + want_level1,
                                    current_booked[1] + want_level2,
                                    current_booked[2] + want_level3);
            delete[] current_booked;
        }
        //航班这边也设置一下
        flight->BookSeat(want_level1, want_level2, want_level3);
    }

        // 不够票，看看进不进等待序列
    else {
        printf(
            "tickets are not enough, do you want to wait a little more for "
            "your tickets? [y or n]: ");
        std::string option;
        std::cin >> option;

        switch (option.c_str()[0]) {
            case 'y': {
                //先看看在不在候补列表里
                Customer* customer = customers_waiting->Get(customer_name);

                //不在，新建一个
                if (customer == nullptr) {
                    Customer customer(customer_name);
                    customer.SetSeatWant(flight_number, want_level1,
                                         want_level2, want_level3);
                    customers_waiting->Insert(customer);
                }
                    //在，拿出来设置一下
                else {
                    uint8_t* current_waiting =
                        customer->GetSeatWant(flight_number);
                    
                        customer->SetSeatWant(flight_number,
                                              current_waiting[0] + want_level1,
                                              current_waiting[1] + want_level2,
                                              current_waiting[2] + want_level3);
                        delete[] current_waiting;
                }
            }
            break;
            case 'n': break;
            default: break;
        }
    }
}
