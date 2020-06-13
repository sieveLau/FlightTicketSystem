#ifndef __FLIGHT_SEARCHER_H__
#define __FLIGHT_SEARCHER_H__
#include <stdio.h>

#include <iostream>
#include <string>
#include <vector>

#include "day_name.h"
#include "defs.h"
#include "flight_linked_list.h"

namespace ds {
    int DiffDay(DAYS target_day, DAYS today);
    void SearchFlight(ds::FlightLinkedList *flight_list,
                      std::string destination, DAYS today) {
        auto all_flights =
            (*flight_list).GetByDestination(std::move(destination));

        //目的地筛选的时候就没有符合的话，就退出。
        if (all_flights->empty()) {
            std::cout << "No flight matches your requirement!" << std::endl;
            return;
        }

        // 输出符合目的地要求的航班的信息，包括余票量
        std::cout << "All flights: " << std::endl;
        printf("%-18s%-18s%-18s\n", "Flight Number", "Airplane Number",
               "Fly Date");

        int diffday                = 7;
        auto *all_flights_as_array = all_flights->ToArray();
        FlightLinkedList nearest_flights;
        for (size_t i = 0; i < all_flights->GetLength(); ++i) {
            auto *flight = all_flights_as_array[i];
            printf("%-18s%-18s%-18s\n", flight->GetFlightNumber().c_str(),
                   flight->GetAirPlaneNumber().c_str(),
                   ds::DAYSToString(flight->GetDate()).c_str());

            int temp = DiffDay(flight->GetDate(), today);
            if (temp < diffday) {
                diffday = temp;
                nearest_flights.Clear();
                nearest_flights.Insert(flight);
            } else if (temp == diffday) {
                nearest_flights.Insert(flight);
            }
        }
        std::cout << std::endl;

        // 输出符合要求的最近一天的航班的信息，包括余票量
        DAYS nearest_day = static_cast<ds::DAYS>((int)today + diffday);
        std::cout << "Nearest day flights on " << DAYSToString(nearest_day)
                  << ": " << std::endl;
        printf("%-18s%-18s%-18s%-18s%-10s%-10s%-10s\n", "Flight Number",
               "Airplane Number", "Fly Date", "Avail. Seats", "Avail. 1",
               "Avail. 2", "Avail. 3");

        auto *nearest_flights_as_array = nearest_flights.ToArray();

        for (size_t i = 0; i < nearest_flights.GetLength(); ++i) {
            auto *flight = nearest_flights_as_array[i];
            printf("%-18s%-18s%-18s%-18s%-10u%-10u%-10u\n",
                   flight->GetFlightNumber().c_str(),
                   flight->GetAirPlaneNumber().c_str(),
                   ds::DAYSToString(flight->GetDate()).c_str(), "",
                   flight->GetAvailLevel1(), flight->GetAvailLevel2(),
                   flight->GetAvailLevel3());
        }
    }

    int DiffDay(DAYS target_day, DAYS today) {
        int diff = (int)target_day - (int)today;
        return diff < 0 ? 7 - diff : diff;
    }
}  // namespace ds
#endif  // __FLIGHT_SEARCHER_H__