#include <sys/types.h>

#include <cstddef>
#include <cstdio>
#include <stdint.h>
#include "customer.h"
#include "day_name.h"
#include "flight.h"
#include "simple_flight_linked_list.h"
#include "simple_flight.h"
#include "defs.h"
#include <initializer_list>

int main() {
    
    u_int8_t total_seats[]{15, 18, 88};
    u_int8_t avail_seats[]{15, 18, 88};

    ds::Customer c1("Adam");
    c1.SetSeatWant("dd", 0, 0, 3);
    
    auto* temp = c1.GetSeatWant("dd");
    c1.SetSeatBooked("dd", temp);
    temp[2] = 1;
    c1.SetSeatWant("dd",temp);
    printf("%u\n", c1.GetSeatWant("dd")[2]);
    return 0;
}