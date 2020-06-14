#pragma once

#include "string"
#include "day_name.h"
#include "customer_linked_list.h"
#include "flight_linked_list.h"
namespace ds
{

    using std::string; using ds::DAYS;
    void Refunder(string customer_name, DAYS date, string flight_number, CustomerLinkedList* booked_list, FlightLinkedList* flights);
}