#ifndef __FLIGHT_LIST_INITIALIZER_H__
#define __FLIGHT_LIST_INITIALIZER_H__

#include "day_name.h"
#include "defs.h"
#include "flight.h"
#include "flight_linked_list.h"
namespace ds {
    FlightLinkedList* InitFlightList() {
        using std::array;
        auto* fll = new FlightLinkedList();

        fll->Insert(Flight("Hangzhou", "FM9158", "B737c", DAYS::TUE,
                           std::array<uint8_t, 3>{5, 10, 20},
                           std::array<uint8_t, 3>{5, 10, 20}));
        fll->Insert(Flight("Hangzhou", "FM9987", "B737c", DAYS::WES,
                           std::array<uint8_t, 3>{5, 10, 20},
                           std::array<uint8_t, 3>{5, 10, 20}));

        fll->Insert(Flight("Guangzhou", "CA4319", "B737a", DAYS::SAT,
                           std::array<uint8_t, 3>{5, 5, 10},
                           std::array<uint8_t, 3>{5, 5, 20}));

        fll->Insert(Flight("Beijing", "MU2368", "B737b", DAYS::SUN,
                           std::array<uint8_t, 3>{10, 10, 100},
                           std::array<uint8_t, 3>{10, 10, 100}));
        return fll;
    }
}  // namespace ds

#endif  // __FLIGHT_LIST_INITIALIZER_H__