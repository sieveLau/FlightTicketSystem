#ifndef __SIMPLE_FLIGHT_H__
#define __SIMPLE_FLIGHT_H__

#include <sys/types.h>

#include <string>
namespace dc {
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
        void SetSeatWant(u_int8_t* seat_want);
        void SetSeatBooked(u_int8_t* seat_booked);
    };
}  // namespace dc

#endif  // __SIMPLE_FLIGHT_H__