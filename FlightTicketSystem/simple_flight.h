#ifndef __SIMPLE_FLIGHT_H__
#define __SIMPLE_FLIGHT_H__

#include <sys/types.h>

#include <string>

#include "defs.h"

namespace ds {
    class SimpleFlight {
        std::string flight_number_;
        u_int8_t seat_[3];

       public:
        SimpleFlight(std::string flight_number, u_int8_t* seat = nullptr);
        ~SimpleFlight();
        SimpleFlight(SimpleFlight&& another) noexcept;
        SimpleFlight& operator=(SimpleFlight another);
        SimpleFlight(const SimpleFlight& another);
        void Swap(SimpleFlight& another);
        void Reset();
        std::string GetFlightNumber() const;
        void SetSeat(uint8_t* levelset);
        void SetSeat(u_int8_t seat_want_level1, u_int8_t seat_want_level2,
                     u_int8_t seat_want_level3);
        uint8_t* GetSeat() const;
        uint8_t GetSeatLevel1() const { return seat_[0]; };
        uint8_t GetSeatLevel2() const { return seat_[1]; };
        uint8_t GetSeatLevel3() const { return seat_[2]; };
    };
}  // namespace ds

#endif  // __SIMPLE_FLIGHT_H__