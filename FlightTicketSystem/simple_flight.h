#ifndef __SIMPLE_FLIGHT_H__
#define __SIMPLE_FLIGHT_H__

#include <sys/types.h>

#include <string>
#include "defs.h"

namespace ds {
    class SimpleFlight {
        std::string flight_number_;
        u_int8_t seat_want_[3];
        u_int8_t seat_booked_[3];

       public:
        SimpleFlight(std::string flight_number, u_int8_t* seat_want = nullptr,
                     u_int8_t* seat_booked = nullptr);
        ~SimpleFlight();
        SimpleFlight(SimpleFlight&& another) noexcept;
        SimpleFlight& operator=(SimpleFlight another);
        SimpleFlight(const SimpleFlight& another);
        void Swap(SimpleFlight& another);
        void Reset();
        std::string GetFlightNumber() const;
        void SetSeatWant(uint8_t* levelset);
        void SetSeatWant(u_int8_t seat_want_level1=0, u_int8_t seat_want_level2=0,
                         u_int8_t seat_want_level3=0);
        void SetSeatBooked(uint8_t* levelset);
        void SetSeatBooked(u_int8_t seat_booked_level1=0,
                           u_int8_t seat_booked_level2=0,
                           u_int8_t seat_booked_level3=0);
        uint8_t* GetSeatWant() const;
        uint8_t* GetSeatBooked() const;
        uint8_t GetSeatWantLevel1() const { return seat_want_[0]; };
        uint8_t GetSeatWantLevel2() const { return seat_want_[1]; };
        uint8_t GetSeatWantLevel3() const { return seat_want_[2]; };
        uint8_t GetSeatBookedLevel1() const { return seat_booked_[0]; };
        uint8_t GetSeatBookedLevel2() const { return seat_booked_[1]; }
        uint8_t GetSeatBookedLevel3() const { return seat_booked_[2]; }
    };
}  // namespace dc

#endif  // __SIMPLE_FLIGHT_H__