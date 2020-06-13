#include <sys/types.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <iostream>

#include "day_name.h"
#include "flight.h"
#include "flight_node.h"
int main() {
    ds::FlightNode fn1(new ds::Flight("uu", "uu1", "uu2", ds::DAYS::FRI,
                                      std::array<uint8_t, 3>{8, 8, 8}
                                      , std::array<uint8_t, 3>{8, 8, 8}
    ));
    ds::FlightNode fn2(fn1);

    int16_t newavail[]{ 0,0,0 };

    fn2.GetData()->SetAvailSeats(newavail);

    printf("%d\n", fn1.GetData()->GetAvailLevel1());
    printf("%d\n", fn2.GetData()->GetAvailLevel1());
    return 0;
}
