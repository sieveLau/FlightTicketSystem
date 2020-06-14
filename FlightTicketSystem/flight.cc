#include "flight.h"

#include <iostream>

#include "defs.h"
namespace ds {
    Flight::Flight() { Reset(); }

    Flight::Flight(std::string destination, std::string flight_number,
                   std::string air_plane_number, DAYS weekday,
                   u_int8_t* total_seats, u_int8_t* available_seats) {
        destination_      = destination;
        flight_number_    = flight_number;
        air_plane_number_ = air_plane_number;
        weekday_          = weekday;
        if (available_seats == nullptr)
            available_seats = total_seats;
        for (size_t i = 0; i < 3; i++) {
            total_seats_[i]     = total_seats[i];
            available_seats_[i] = available_seats[i];
        }
    }

    Flight::Flight(Flight&& another) noexcept {
        destination_      = std::move(another.destination_);
        air_plane_number_ = std::move(another.air_plane_number_);
        flight_number_    = std::move(another.flight_number_);
        weekday_          = std::move(another.weekday_);
        for (size_t i = 0; i < 3; i++) {
            total_seats_[i]     = another.total_seats_[i];
            available_seats_[i] = another.available_seats_[i];
        }
        another.Reset();
    }
    Flight::~Flight() { Reset(); }

    Flight& Flight::operator=(Flight another) {
        Swap(another);
        return *this;
    }
    void Flight::Swap(Flight& another) {
        std::swap(destination_, another.destination_);
        std::swap(air_plane_number_, another.air_plane_number_);
        std::swap(flight_number_, another.flight_number_);
        std::swap(weekday_, another.weekday_);
        std::swap(total_seats_, another.total_seats_);
        std::swap(available_seats_, another.available_seats_);
    }
    void Flight::Reset() {
        destination_      = "";
        flight_number_    = "";
        air_plane_number_ = "";
        weekday_          = DAYS::SUN;
        for (size_t i = 0; i < 3; i++) {
            total_seats_[i]     = 0;
            available_seats_[i] = 0;
        }
    }

    std::string Flight::GetDestination() const { return destination_; }

    std::string Flight::GetFlightNumber() const { return flight_number_; }

    std::string Flight::GetAirPlaneNumber() const { return air_plane_number_; }

    DAYS Flight::GetDate() const { return weekday_; }

    u_int8_t Flight::GetTotalLevel1() const { return total_seats_[0]; }

    u_int8_t Flight::GetTotalLevel2() const { return total_seats_[1]; }

    u_int8_t Flight::GetTotalLevel3() const { return total_seats_[2]; }

    // 不会影响内部数据
    // 用完务必delete
    uint8_t* Flight::GetAvailAll() const {
        return new u_int8_t[3]{
            available_seats_[0],
            available_seats_[1],
            available_seats_[2],
        };
    }
    u_int8_t Flight::GetAvailLevel1() const { return available_seats_[0]; }

    u_int8_t Flight::GetAvailLevel2() const { return available_seats_[1]; }

    u_int8_t Flight::GetAvailLevel3() const { return available_seats_[2]; }

    void Flight::SetAvailSeats(u_int8_t* available_seats) {
        for (size_t i = 0; i < 3; i++) { available_seats_[i] = available_seats[i]; }
    }
    void Flight::SetAvailSeats(u_int8_t level1, u_int8_t level2,
        u_int8_t level3) {
        available_seats_[0] = level1;
        available_seats_[1] = level2;
        available_seats_[2] = level3;

    }


    int Flight::BookSeat(u_int8_t level1, u_int8_t level2, u_int8_t level3) {


        // 因为可能是负数，所以要用有符号
        int16_t result[3];

        result[0] = available_seats_[0] - level1;
        result[1] = available_seats_[1] - level2;
        result[2] = available_seats_[2] - level3;

        for (size_t i = 0; i < 3; i++) {
            if (result[i] < 0) {
                std::cerr << "Not enough seats. Book failed." << std::endl;
                return -1;
            }
        }

        SetAvailSeats((uint8_t)result[0],(uint8_t)result[1],(uint8_t)result[2]);
        return 0;
    }
    int Flight::BookSeat(uint8_t* levelset) {
        return BookSeat(levelset[0], levelset[1], levelset[2]);
    }

    int Flight::Refund(u_int8_t level1, u_int8_t level2, u_int8_t level3) {
        int16_t result[3];
        result[0] = available_seats_[0] + level1;
        result[1] = available_seats_[1] + level2;
        result[2] = available_seats_[2] + level3;

        for (size_t i = 0; i < 3; i++) {
            if (result[i] > total_seats_[i]) {
#ifdef DEBUG
                std::cerr << "Too much tickets! Fake tickets? My number is "
                          << flight_number_ << " (Flight::Refund)";
#endif  // DEBUG
                return -1;
            }
        }

        SetAvailSeats((uint8_t)result[0],(uint8_t)result[1],(uint8_t)result[2]);
        return 0;
    }
    int Flight::Refund(uint8_t* levelset) {
        return Refund(levelset[0],
            levelset[1],
            levelset[2]
        );
    }

    Flight::Flight(const Flight& another) {
        destination_      = another.destination_;
        flight_number_    = another.flight_number_;
        air_plane_number_ = another.air_plane_number_;
        weekday_          = another.weekday_;
        for (size_t i = 0; i < 3; i++) {
            total_seats_[i]     = another.total_seats_[i];
            available_seats_[i] = another.available_seats_[i];
        }
    }

    
}  // namespace ds