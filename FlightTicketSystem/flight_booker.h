#pragma once
#include <string>
#include "customer.h"
#include "flight_linked_list.h"
#include "customer_linked_list.h"
namespace ds
{
    
    // ��ѯ�Ƿ�����Ʊ
    void Check(std::string flight_number, uint8_t want_level1,
    uint8_t want_level2, uint8_t want_level3, std::string customer_name,
    FlightLinkedList* flights, CustomerLinkedList* customers_booked,CustomerLinkedList* customers_waiting);
    // ���㹻��Ʊ����
    // void Book(Customer* customer,CustomerLinkedList* customers_booked,Flight* flight);
    // // û���㹻��Ʊ������ȴ�����
    // void Wait();
}

