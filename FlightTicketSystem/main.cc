#include <sys/types.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <iostream>

#include "customer.h"
#include "day_name.h"
#include "defs.h"
#include "flight.h"
#include "flight_linked_list.h"
#include "flight_list_initializer.h"
#include "flight_searcher.h"
#include "simple_flight.h"
#include "simple_flight_linked_list.h"
int main() {
    auto* flight_list = ds::InitFlightList();

    ds::SearchFlight(flight_list, "Beijing", ds::DAYS::WES);
    delete flight_list;
    return 0;
}