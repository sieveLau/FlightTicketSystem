#include "simple_flight.h"

#include <cstring>

#include "defs.h"
namespace ds {
    SimpleFlight::SimpleFlight(std::string flight_number, u_int8_t* seat) {
        flight_number_ = std::move(flight_number);
        if (seat != nullptr) {
            for (size_t i = 0; i < 3; ++i) { seat_[i] = seat[i]; }
        }
    }

    SimpleFlight& SimpleFlight::operator=(SimpleFlight another) {
        Swap(another);
        return *this;
    }

    SimpleFlight::SimpleFlight(const SimpleFlight& another) {
        flight_number_ = another.flight_number_;
        for (size_t i = 0; i < 3; i++) { seat_[i] = another.seat_[i]; }
    }

    void SimpleFlight::Swap(SimpleFlight& another) {
        std::swap(flight_number_, another.flight_number_);
        for (size_t i = 0; i < 3; i++) { seat_[i] = another.seat_[i]; }
    }

    SimpleFlight::~SimpleFlight() { Reset(); }

    SimpleFlight::SimpleFlight(SimpleFlight&& another) noexcept {
        flight_number_ = std::move(another.flight_number_);
        memmove(seat_, another.seat_, sizeof(seat_[0]) * 3);
        another.Reset();
    }

    void SimpleFlight::Reset() {
        memset(seat_, 0, sizeof(seat_[0]) * 3);
        flight_number_ = "";
    }

    std::string SimpleFlight::GetFlightNumber() const { return flight_number_; }

    void SimpleFlight::SetSeat(uint8_t* levelset) {
        for (int i = 0; i < 3; ++i) { seat_[i] = levelset[i]; }
    }

    void SimpleFlight::SetSeat(u_int8_t seat_want_level1,
                               u_int8_t seat_want_level2,
                               u_int8_t seat_want_level3) {
        seat_[0] = seat_want_level1;
        seat_[1] = seat_want_level2;
        seat_[2] = seat_want_level3;
    }

    // 返回new出来的uint8_t数组
    // 无法修改内部数据
    // 务必delete
    uint8_t* SimpleFlight::GetSeat() const {
        uint8_t* result = new uint8_t[3]{seat_[0], seat_[1], seat_[2]};
        return result;
    }

}  // namespace ds
