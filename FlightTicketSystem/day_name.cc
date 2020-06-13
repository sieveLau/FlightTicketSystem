#include "day_name.h"

namespace ds {
    std::string DAYSToString(DAYS day) {
        {
            switch (day) {
                case DAYS::MON: return std::string("MON"); break;
                case DAYS::TUE: return std::string("TUE"); break;
                case DAYS::WES: return std::string("WES"); break;
                case DAYS::THU: return std::string("THU"); break;
                case DAYS::FRI: return std::string("FRI"); break;
                case DAYS::SAT: return std::string("SAT"); break;
                case DAYS::SUN: return std::string("SUN"); break;

                default: return std::string(""); break;
            }
        }
    }
}  // namespace ds