#include "refunder.h"

#include <cstdio>
#include <iostream>

#include "customer.h"
#include "string"

void ds::Refunder(string customer_name, DAYS date, string flight_number,
                  CustomerLinkedList* booked_list,
                  CustomerLinkedList* waiting_list, FlightLinkedList* flights) {
    Customer* customer = booked_list->Get(customer_name);
    Flight* flight     = flights->GetByFlightNumber(flight_number);

    // 如果订了票的没有这个人，直接回家
    if (customer == nullptr) {
#ifdef DEBUG
        std::cerr
            << "Customer hasn't booked any flight, exiting. (ds::Refunder)"
            << std::endl;
#endif
        return;
    }

    // 如果没有这个航班，回家
    if (flight == nullptr) {
#ifdef DEBUG
        std::cerr << "Flight doesn't exist, exiting. (ds::Refunder)"
                  << std::endl;
#endif
        return;
    }

    // 如果当天没有这个航班，回家
    if (flight->GetDate() != date) {
#ifdef DEBUG
        std::cerr << "Date of given flight doesn't match customer's date, "
                     "exiting. (ds::Refunder)"
                  << std::endl;
#endif
        return;
    }

    uint8_t* customer_origin_booked = customer->GetSeatBooked(flight_number);
    // 如果客户booked表里没有这个航班，不干活
    if (customer_origin_booked == nullptr) {
#ifdef DEBUG
        std::cerr
            << "Customer hasn't booked this flight, exiting. (ds::Refunder)"
            << std::endl;
#endif
        return;
    }

    //退票，在航班处登记
#ifdef DEBUG
    int status =
        flight->Refund(customer_origin_booked[0], customer_origin_booked[1],
                       customer_origin_booked[2]);
    if (status != 0) {
        printf("refund fail\n");
    } else
        printf("refund succeed!\n");
#endif  // DEBUG
#ifndef DEBUG
    flight->Refund(customer_origin_booked[0], customer_origin_booked[1],
                   customer_origin_booked[2]);
#endif  // DEBUG

    //退票，在客户处登记
    customer->SetSeatBooked(flight_number, 0, 0, 0);
    if (!customer->HasBooked()) {
        booked_list->Delete(customer->GetName());
    }
    // 转接，查询是否有人候补
    ds::CheckWaiting(flight->GetAvailAll(), booked_list, waiting_list, flight);
}

void ds::CheckWaiting(uint8_t* new_avail_seats, CustomerLinkedList* booked_list,
                      CustomerLinkedList* waiting_list, Flight* flight) {
    auto avail1 = new_avail_seats[0];
    auto avail2 = new_avail_seats[1];
    auto avail3 = new_avail_seats[2];

    Customer** all_waiting = waiting_list->GetAll();

    Customer* current = all_waiting[0];
    for (int i = 0; current != nullptr;) {
        auto* current_seat_want =
            current->GetSeatWant(flight->GetFlightNumber());
        for (int j = 0; j < 3; j++) {
            // 如果有一个需求大于可提供的，就询问下一位
            if (current_seat_want[j] > new_avail_seats[j]) {
                break;
            }
            // j=2，需求都能满足了
            // 开始订票
            if (j == 2) {
                flight->BookSeat(current_seat_want[0], current_seat_want[1],
                                 current_seat_want[2]);
                current->SetSeatBooked(flight->GetFlightNumber(),
                                       current_seat_want);
                current->SetSeatWant(flight->GetFlightNumber(), 0, 0, 0);
                booked_list->InsertSorted(*current);

                goto outer;
            }
        }
        current = all_waiting[++i];
    }
outer:
    delete[] new_avail_seats;
}
