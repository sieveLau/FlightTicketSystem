#include "refunder.h"
#include "customer.h"
void ds::Refunder(string customer_name, DAYS date, string flight_number,
    CustomerLinkedList* booked_list, FlightLinkedList* flights) {

    Customer* customer = booked_list->Get(customer_name);
    Flight* flight = flights->GetByFlightNumber(flight_number);

    // 如果订了票的没有这个人，直接回家
    if (customer == nullptr) {
#ifdef DEBUG
        std::cerr << "Customer hasn't booked any flight, exiting. (ds::Refunder)"<<std::endl;
#endif
        return;
    }

    // 如果没有这个航班，回家
    if(flight==nullptr) {
#ifdef DEBUG
        std::cerr << "Flight doesn't exist, exiting. (ds::Refunder)"<<std::endl;
#endif 
        return;
    }

    // 如果当天没有这个航班，回家
    if(flight->GetDate()!=date) {
#ifdef DEBUG
        std::cerr << "Date of given flight doesn't match customer's date, exiting. (ds::Refunder)"<<std::endl;
#endif 
        return;
    }

    // 如果客户booked表里没有这个航班，不干活
    uint8_t* customer_origin_booked = customer->GetSeatBooked(flight_number);
    if(customer_origin_booked==nullptr) {
#ifdef DEBUG
        std::cerr << "Customer hasn't booked this flight, exiting. (ds::Refunder)"<<std::endl;
#endif 
            return;
    }

}
