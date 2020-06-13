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
#include "simple_flight.h"
#include "simple_flight_linked_list.h"
#include "customer.h"
#include "customer_node.h"
#include "customer_linked_list.h"
int main() {
    // auto* fll = ds::InitFlightList();
    //
    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);


    ds::Customer c1("adam");
    c1.SetSeatWant("uu1", 1, 2, 0);
    ds::Customer c2("abam");
    c2.SetSeatWant("uu2", 13, 28, 0);

    ds::CustomerLinkedList cll(new ds::Customer(c1));
    cll.Insert(new ds::Customer(c2));
    auto* temp = cll.Get("adam");
    std::cout << temp->GetSeatWant("uu1")[0];

    cll.Delete("adam");

    int16_t newavail[]{0, 0, 0};
    return 0;
}
