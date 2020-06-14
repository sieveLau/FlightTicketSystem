#pragma once
#include <string>

#include "customer.h"
#include "customer_linked_list.h"
#include "flight_linked_list.h"
namespace ds {

    // 查询是否有余票
    void Check(std::string flight_number, uint8_t want_level1,
               uint8_t want_level2, uint8_t want_level3,
               std::string customer_name, FlightLinkedList* flights,
               CustomerLinkedList* customers_booked,
               CustomerLinkedList* customers_waiting);
    // 有足够的票，买
    // void Book(Customer* customer,CustomerLinkedList* customers_booked,Flight*
    // flight);
    // // 没有足够的票，进入等待序列
    // void Wait();
}  // namespace ds
