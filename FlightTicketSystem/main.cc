#include <sys/types.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <iostream>
#include <string>
#include "day_name.h"
#include "flight.h"
#include "flight_node.h"
#include "flight_linked_list.h"
#include "flight_list_initializer.h"
#include "flight_searcher.h"
#include "flight_booker.h"
#include "simple_flight.h"
#include "simple_flight_linked_list.h"
#include "customer.h"
#include "customer_node.h"
#include "customer_linked_list.h"
int main() {
    auto* fll = ds::InitFlightList();
    
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);

    ds::CustomerLinkedList booked(true);
    ds::CustomerLinkedList waiting(false);

    ds::Check("FM9987", 4, 0, 0, "Adam", fll, &booked, &waiting);
    
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);
    ds::Check("FM9987", 0, 8, 0, "Adam", fll, &booked, &waiting);
    ds::Check("FM9987", 0, 2, 0, "Abam", fll, &booked, &waiting);
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);
    // ds::Check("FM9987", 0, 8, 0, "Adam", fll, &booked, &waiting);
    

    
    auto * booked_adam = booked.Get("Adam")->GetSeatBooked("FM9987");
    //���ȷ��get�������ǲ���nullptr�������ǲ��������ģ����������ͻᱩ��
    // auto * waiting_adam = waiting.Get("Adam")->GetSeatBooked("FM9987");
    int16_t newavail[]{0, 0, 0};
    return 0;
}
