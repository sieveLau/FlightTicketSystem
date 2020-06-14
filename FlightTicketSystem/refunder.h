#pragma once

#include <string>

#include "customer_linked_list.h"
#include "day_name.h"
#include "flight.h"
#include "flight_linked_list.h"
namespace ds {

    using ds::DAYS;
    using std::string;
    void Refunder(string customer_name, DAYS date, string flight_number,
                  CustomerLinkedList* booked_list,
                  CustomerLinkedList* waiting_list, FlightLinkedList* flights);

    void CheckWaiting(uint8_t* new_avail_seats, CustomerLinkedList* booked_list,
                      CustomerLinkedList* waiting_list, Flight* flight);
}  // namespace ds