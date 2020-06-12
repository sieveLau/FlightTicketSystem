#include "simple_flight.h"

namespace dc {
    SimpleFlight::SimpleFlight(std::string flight_number, u_int8_t* seat_want,
                               u_int8_t* seat_booked) {
        Reset();
        flight_number_ = flight_number;
    }

    SimpleFlight& SimpleFlight::operator=(SimpleFlight another) {
        Swap(another);
        return *this;
    }

    SimpleFlight::SimpleFlight(const SimpleFlight& another) {
        flight_number_ = another.flight_number_;
        for (size_t i = 0; i < 3; i++) {
            seat_want_[i]   = another.seat_want_[i];
            seat_booked_[i] = another.seat_booked_[i];
        }
    }
    void SimpleFlight::Swap(SimpleFlight& another) {
        std::swap(flight_number_, another.flight_number_);
        for (size_t i = 0; i < 3; i++) {
            seat_want_[i]   = another.seat_want_[i];
            seat_booked_[i] = another.seat_booked_[i];
        }
    }
    SimpleFlight::~SimpleFlight() { Reset(); }

    SimpleFlight::SimpleFlight(SimpleFlight&& another) noexcept {
        flight_number_ = std::move(another.flight_number_);
        for (size_t i = 0; i < 3; i++) {
            seat_want_[i]   = another.seat_want_[i];
            seat_booked_[i] = another.seat_booked_[i];
        }
        another.Reset();
    }
    void SimpleFlight::Reset() {
        for (size_t i = 0; i < 3; i++) {
            seat_want_[i]   = 0;
            seat_booked_[i] = 0;
        }
        flight_number_ = "";
    }

    std::string SimpleFlight::GetFlightNumber() const { return flight_number_; }
    void SimpleFlight::SetSeatWant(u_int8_t* seat_want) {
        for (size_t i = 0; i < 3; i++) { seat_want_[i] = seat_want[i]; }
    }

    void SimpleFlight::SetSeatBooked(u_int8_t* seat_booked) {
        for (size_t i = 0; i < 3; i++) { seat_booked_[i] = seat_booked[i]; }
    }
}  // namespace dc