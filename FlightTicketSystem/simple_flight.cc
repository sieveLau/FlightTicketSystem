#include "simple_flight.h"

#include "defs.h"

namespace ds {
    SimpleFlight::SimpleFlight(std::string flight_number, u_int8_t* seat_want,
                               u_int8_t* seat_booked) {
        Reset();
        flight_number_ = flight_number;
        if (seat_want != nullptr) {
            for (size_t i = 0; i < 3; ++i) { seat_want_[i] = seat_want[i]; }
        }
        if (seat_booked != nullptr) {
            for (size_t i = 0; i < 3; ++i) { seat_booked_[i] = seat_booked[i]; }
        }
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
        SetSeatBooked(0, 0, 0);
        SetSeatWant(0, 0, 0);
        flight_number_ = "";
    }

    std::string SimpleFlight::GetFlightNumber() const { return flight_number_; }
    void SimpleFlight::SetSeatWant(uint8_t* levelset) {
        for (int i = 0; i < 3; ++i) { seat_want_[i] = levelset[i]; }
    }

    void SimpleFlight::SetSeatWant(u_int8_t seat_want_level1,
                                   u_int8_t seat_want_level2,
                                   u_int8_t seat_want_level3) {
        seat_want_[0] = seat_want_level1;
        seat_want_[1] = seat_want_level2;
        seat_want_[2] = seat_want_level3;
    }

    void SimpleFlight::SetSeatBooked(uint8_t* levelset) {
        for (int i = 0; i < 3; ++i) { seat_booked_[i] = levelset[i]; }
    }

    void SimpleFlight::SetSeatBooked(u_int8_t seat_booked_level1,
                                     u_int8_t seat_booked_level2,
                                     u_int8_t seat_booked_level3) {
        seat_booked_[0] = seat_booked_level1;
        seat_booked_[1] = seat_booked_level2;
        seat_booked_[2] = seat_booked_level3;
    }

    uint8_t* SimpleFlight::GetSeatWant() const {
        uint8_t* result =
            new uint8_t[3]{seat_want_[0], seat_want_[1], seat_want_[2]};
        return result;
    }

    // 返回new出来的uint8_t数组
    // 无法修改内部数据
    uint8_t* SimpleFlight::GetSeatBooked() const {
        uint8_t* result =
            new uint8_t[3]{seat_booked_[0], seat_booked_[1], seat_booked_[2]};
        return result;
    }

}  // namespace ds
