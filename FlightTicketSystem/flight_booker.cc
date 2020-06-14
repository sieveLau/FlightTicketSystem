#include "flight_booker.h"
#include <string>
#include <iostream>
void ds::Check(std::string flight_number, uint8_t want_level1,
               uint8_t want_level2, uint8_t want_level3,
               std::string customer_name, FlightLinkedList* flights,
               CustomerLinkedList* customers_booked,
               CustomerLinkedList* customers_waiting) {
    auto* flight = flights->GetByFlightNumber(flight_number);
    auto avail1  = flight->GetAvailLevel1();
    auto avail2  = flight->GetAvailLevel2();
    auto avail3  = flight->GetAvailLevel3();

    //�����Ʊ���͸�����
    if (avail1 >= want_level1 && avail2 >= want_level2 &&
        avail3 >= want_level3) {
        // �ȿ���������ǲ����Ѿ�����Ʊ
        Customer* customer = customers_booked->Get(customer_name);

        // û�������½�һ��
        if (customer == nullptr) {
            Customer customer(customer_name);
            customer.SetSeatBooked(flight_number, want_level1, want_level2,
                                   want_level3);

            customers_booked->InsertSorted(customer);
        } else {
            //�����ˣ����Ѿ�������ԭ������������Ҫ�ģ����û�ȥ
            uint8_t* current_booked = customer->GetSeatBooked(flight_number);
            customer->SetSeatBooked(flight_number,
                                    current_booked[0] + want_level1,
                                    current_booked[1] + want_level2,
                                    current_booked[2] + want_level3);
            delete[] current_booked;
        }
        //�������Ҳ����һ��
        flight->BookSeat(want_level1, want_level2, want_level3);
    }

        // ����Ʊ�������������ȴ�����
    else {
        printf(
            "tickets are not enough, do you want to wait a little more for "
            "your tickets? [y or n]: ");
        std::string option;
        std::cin >> option;

        switch (option.c_str()[0]) {
            case 'y': {
                //�ȿ����ڲ��ں��б���
                Customer* customer = customers_waiting->Get(customer_name);

                //���ڣ��½�һ��
                if (customer == nullptr) {
                    Customer customer(customer_name);
                    customer.SetSeatWant(flight_number, want_level1,
                                         want_level2, want_level3);
                    customers_waiting->Insert(customer);
                }
                    //�ڣ��ó�������һ��
                else {
                    uint8_t* current_waiting =
                        customer->GetSeatWant(flight_number);
                    
                        customer->SetSeatWant(flight_number,
                                              current_waiting[0] + want_level1,
                                              current_waiting[1] + want_level2,
                                              current_waiting[2] + want_level3);
                        delete[] current_waiting;
                }
            }
            break;
            case 'n': break;
            default: break;
        }
    }
}
