#include <sys/types.h>

#include <cstddef>
#include <cstdio>

#include "customer.h"
#include "day_name.h"
#include "flight.h"
int main() {
    u_int8_t total_seats[]{15, 18, 88};
    u_int8_t avail_seats[]{15, 18, 88};
    ds::Customer customer("Adam");
    customer.SetTicketWant(5);
    printf("%u\n", customer.GetTicketWantLevel1());
    customer.CancelTicket(6);
    printf("%u\n", customer.GetTicketWantLevel1());

    return 0;
}