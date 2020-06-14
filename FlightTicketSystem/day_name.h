#ifndef __DAY_NAME_H__
#define __DAY_NAME_H__
#include <string>
namespace ds {

    /*星期几
     *星期1对应1
     */
    enum class DAYS { MON = 1, TUE, WES, THU, FRI, SAT, SUN };

    std::string DAYSToString(DAYS);
    int ToInt(DAYS);
}  // namespace ds
#endif  // __DAY_NAME_H__