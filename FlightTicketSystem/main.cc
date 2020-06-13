#include <sys/types.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <iostream>

#include "day_name.h"
#include "flight.h"
#include "flight_node.h"
#include "flight_linked_list.h"
#include "flight_list_initializer.h"
int main() {
    auto* fll = ds::InitFlightList();

    auto temp = fll->GetByDestination("Beijing")->ToArray();
    std::cout<<temp[0]->GetAirPlaneNumber();


    int16_t newavail[]{0, 0, 0};
    return 0;
}
