#include "flight_booker.h"
#include <iostream>
void ds::Check(std::string flight_number, uint8_t want_level1,
               uint8_t want_level2, uint8_t want_level3,
               std::string customer_name,
               FlightLinkedList* flights, CustomerLinkedList* customers_booked,
               CustomerLinkedList* customers_waiting) {

    auto* flight = flights->GetByFlightNumber(flight_number);

    auto avail1    = flight->GetAvailLevel1();
    auto avail2    = flight->GetAvailLevel2();
    auto avail3    = flight->GetAvailLevel3();
    auto* customer = new Customer(customer_name);

    if (avail1 >= want_level1
        &&
        avail2 >= want_level2
        &&
        avail3 >= want_level3
    ) {
        customer->SetSeatBooked(flight_number, want_level1, want_level2,
                                want_level3);
        customers_booked->InsertSorted(customer);
        flight->BookSeat(want_level1, want_level2, want_level3);
    } else {
        printf("tickets are not enough, do you want to wait a little more for your tickets? [y or n]: ");
        std::string option;
        std::cin >> option;
        switch (option.c_str()[0]) {
        case 'y':
            customer->SetSeatWant(flight_number, want_level1, want_level2,
                              want_level3);
        customers_waiting->Insert(customer);
        break;
        case 'n':
            delete customer;
            break;
        }
        
    }

}
