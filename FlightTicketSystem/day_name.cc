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

    int ToInt(DAYS day) {
        {
            switch (day) {
                case DAYS::MON: return 1; break;
                case DAYS::TUE: return 2; break;
                case DAYS::WES: return 3; break;
                case DAYS::THU: return 4; break;
                case DAYS::FRI: return 5; break;
                case DAYS::SAT: return 6; break;
                case DAYS::SUN: return 7; break;

                default: return 0; break;
            }
        }
    }
}  // namespace ds