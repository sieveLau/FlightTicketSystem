#ifndef __FLIGHT_SEARCHER_H__
#define __FLIGHT_SEARCHER_H__
#include <stdio.h>

#include <iostream>
#include <string>

#include "day_name.h"
#include "defs.h"
#include "flight_linked_list.h"

namespace ds {
    int DiffDay(DAYS target_day, DAYS today);
    void PrintHorizonLine();


    inline void ResetFlightArray(Flight** array,int length) {
        for (int i = 0; i < length; ++i) {
            array[i] = nullptr;
        }
    }

    inline void SearchFlight(FlightLinkedList* flight_list,
                             std::string destination, DAYS today) {
     
        auto** all_flights = flight_list->GetByDestination(destination);

        //目的地筛选的时候就没有符合的话，就退出。
        if (all_flights[0]==nullptr) {
            std::cout << "No flight matches your requirement!" << std::endl;
            PrintHorizonLine();
            delete[] all_flights;
            return;
        }

        // 输出符合目的地要求的航班的信息，包括余票量
        std::cout << "All flights to "
            << destination
            << ": " << std::endl;
        printf("%-18s%-18s%-18s\n", "Flight Number", "Airplane Number",
               "Fly Date");

        int diffday = 7;


        Flight** nearest_flights = new Flight*[flight_list->GetLength()+1]{nullptr};

        size_t j = 0;
        for (size_t i = 0; ; ++i) {
            Flight* flight = all_flights[i];
            
            if (flight == nullptr)break;

            printf("%-18s%-18s%-18s\n", flight->GetFlightNumber().c_str(),
                   flight->GetAirPlaneNumber().c_str(),
                   ds::DAYSToString(flight->GetDate()).c_str());

            int temp = DiffDay(flight->GetDate(), today);
            if (temp < diffday) {
                diffday = temp;
                ResetFlightArray(nearest_flights, flight_list->GetLength() + 1);
                j = 0;
                nearest_flights[j++]=flight;
            } else if (temp == diffday) { nearest_flights[j++]=flight; }
        }
        std::cout << std::endl;

        // 输出符合要求的最近一天的航班的信息，包括余票量
        
        std::cout << "Nearest day flights"
            << ": " << std::endl;
        printf("%-18s%-18s%-18s%-18s%-10s%-10s%-10s\n", "Flight Number",
               "Airplane Number", "Fly Date", "Avail. Seats", "Avail. 1",
               "Avail. 2", "Avail. 3");

        for (size_t i = 0; i < j; ++i) {
            auto* flight = nearest_flights[i];
            printf("%-18s%-18s%-18s%-18s%-10u%-10u%-10u\n",
                   flight->GetFlightNumber().c_str(),
                   flight->GetAirPlaneNumber().c_str(),
                   ds::DAYSToString(flight->GetDate()).c_str(), "",
                   flight->GetAvailLevel1(), flight->GetAvailLevel2(),
                   flight->GetAvailLevel3());
        }
        // 打印分割线
        PrintHorizonLine();

        delete[] all_flights;
        delete[] nearest_flights;
    }

    int DiffDay(DAYS target_day, DAYS today) {
        int td  = ToInt(target_day);
        int td2 = ToInt(today);

        int diff = td - td2;

        return diff < 0 ? 7 + diff : diff;
    }

    void PrintHorizonLine() {
        printf("%s\n", std::string(30 + 4 * 18, '-').c_str());
    }
} // namespace ds
#endif  // __FLIGHT_SEARCHER_H__
