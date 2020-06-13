#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include <array>
#include <string>

#include "day_name.h"
#include "defs.h"
namespace ds {
    class Flight {
        std::string destination_;
        std::string flight_number_;
        std::string air_plane_number_;
        DAYS weekday_;
        u_int8_t total_seats_[3];
        u_int8_t available_seats_[3];

       public:
        Flight() = delete;

        Flight(std::string destination, std::string flight_number,
               std::string air_plane_number, DAYS weekday,
               u_int8_t* total_seats, u_int8_t* available_seats = nullptr);
        Flight(std::string destination, std::string flight_number,
               std::string air_plane_number, DAYS weekday,
               std::array<u_int8_t, 3> total_seats,
               std::array<u_int8_t, 3> available_seats);
        Flight(const Flight& another);
        Flight(Flight&&) noexcept;
        ~Flight();
        Flight& operator=(Flight another);
        void Swap(Flight& another);
        void Reset();

        std::string GetDestination() const;
        std::string GetFlightNumber() const;
        std::string GetAirPlaneNumber() const;
        DAYS GetDate() const;

        u_int8_t GetTotalLevel1() const;
        u_int8_t GetTotalLevel2() const;
        u_int8_t GetTotalLevel3() const;
        u_int8_t GetAvailLevel1() const;
        u_int8_t GetAvailLevel2() const;
        u_int8_t GetAvailLevel3() const;

        void SetAvailSeats(int16_t* AvailSeats);

        int BookSeat(u_int8_t level1 = 0, u_int8_t level2 = 0,
                     u_int8_t level3 = 0);
        int Refund(u_int8_t level1 = 0, u_int8_t level2 = 0,
                   u_int8_t level3 = 0);
    };
}  // namespace ds

#endif  // __FLIGHT_H__