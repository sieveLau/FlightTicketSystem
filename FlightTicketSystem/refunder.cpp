#include "refunder.h"
#include "customer.h"
void ds::Refunder(string customer_name, DAYS date, string flight_number,
    CustomerLinkedList* booked_list, FlightLinkedList* flights) {

    Customer* customer = booked_list->Get(customer_name);
    Flight* flight = flights->GetByFlightNumber(flight_number);

    // �������Ʊ��û������ˣ�ֱ�ӻؼ�
    if (customer == nullptr) {
#ifdef DEBUG
        std::cerr << "Customer hasn't booked any flight, exiting. (ds::Refunder)"<<std::endl;
#endif
        return;
    }

    // ���û��������࣬�ؼ�
    if(flight==nullptr) {
#ifdef DEBUG
        std::cerr << "Flight doesn't exist, exiting. (ds::Refunder)"<<std::endl;
#endif 
        return;
    }

    // �������û��������࣬�ؼ�
    if(flight->GetDate()!=date) {
#ifdef DEBUG
        std::cerr << "Date of given flight doesn't match customer's date, exiting. (ds::Refunder)"<<std::endl;
#endif 
        return;
    }

    // ����ͻ�booked����û��������࣬���ɻ�
    uint8_t* customer_origin_booked = customer->GetSeatBooked(flight_number);
    if(customer_origin_booked==nullptr) {
#ifdef DEBUG
        std::cerr << "Customer hasn't booked this flight, exiting. (ds::Refunder)"<<std::endl;
#endif 
            return;
    }

}
