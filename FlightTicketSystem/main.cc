#include <sys/types.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <iostream>

#include "day_name.h"
#include "flight.h"
#include "flight_linked_list.h"
#include "flight_list_initializer.h"
#include "node.h"
int main() {
    auto* flight_list  = ds::InitFlightList();
    auto* flight_list2 = new ds::FlightLinkedList(*flight_list);

    flight_list->Clear();
    auto* temp = flight_list2->GetByDestination("Hangzhou");
    printf("%s\n", temp->ToArray()[0]->GetAirPlaneNumber().c_str());
    return 0;
}