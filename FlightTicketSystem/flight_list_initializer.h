#ifndef __FLIGHT_LIST_INITIALIZER_H__
#define __FLIGHT_LIST_INITIALIZER_H__

#include "day_name.h"
#include "defs.h"
#include "flight.h"
#include "flight_linked_list.h"
namespace ds {
    /*
输入航班信息
*/
    inline FlightLinkedList* InitFlightList() {
        using std::array;
        auto* fll = new FlightLinkedList();

        uint8_t seats1[3]{ 5,10,20 };
        uint8_t seats2[3]{ 5,5,10 };
        uint8_t seats3[3]{ 5,5,20 };
        uint8_t seats4[3]{ 10,10,100 };

        fll->Insert(Flight("Hangzhou", "FM9158", "B737c", DAYS::TUE,
                               seats1,
                               seats1));
        
        fll->Insert(Flight("Hangzhou", "FM9987", "B737c", DAYS::WES,
                               seats2,
                               seats2));
        fll->Insert(Flight("Hangzhou", "FM9986", "B737b", DAYS::WES,
                               seats4,
                               seats4));

        fll->Insert(Flight("Guangzhou", "CA4319", "B737a", DAYS::SAT,
                               seats2,
                               seats2));

        fll->Insert(Flight("Beijing", "MU2368", "B737b", DAYS::SUN,
                               seats4,
                               seats4));
        return fll;
    }
}  // namespace ds

#endif  // __FLIGHT_LIST_INITIALIZER_H__