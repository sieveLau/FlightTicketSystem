#include "flight.h"
#include "defs.h"
namespace ds {
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

    u_int8_t Flight::GetAvailLevel1() const { return available_seats_[0]; }

    u_int8_t Flight::GetAvailLevel2() const { return available_seats_[1]; }

    u_int8_t Flight::GetAvailLevel3() const { return available_seats_[2]; }

    void Flight::SetAvailSeats(int16_t* AvailSeats) {
        for (size_t i = 0; i < 3; i++) { available_seats_[i] = AvailSeats[i]; }
    }
    int Flight::BookSeat(u_int8_t level1, u_int8_t level2, u_int8_t level3) {
        int16_t result[3];

        result[0] = available_seats_[0] - level1;
        result[1] = available_seats_[1] - level2;
        result[2] = available_seats_[2] - level3;

        for (size_t i = 0; i < 3; i++) {
            if (result[i] < 0)
                return -1;
        }

        SetAvailSeats(result);
        return 0;
    }

    int Flight::Refund(u_int8_t level1, u_int8_t level2, u_int8_t level3) {
        int16_t result[3];
        result[0] = available_seats_[0] + level1;
        result[1] = available_seats_[1] + level2;
        result[2] = available_seats_[2] + level3;

        for (size_t i = 0; i < 3; i++) {
            if (result[i] > total_seats_[i]) {
                return -1;
            }
        }

        SetAvailSeats(result);

        return 0;
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