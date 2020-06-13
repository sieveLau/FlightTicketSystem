#pragma once
#include "customer_node.h"
namespace ds {
    class CustomerLinkedList
    {
        CustomerNode* head_;
        size_t length_;
        bool sorted_;

        void InsertToTail(Customer customer);
        void InsertToTail(Customer* customer);
    public:
        explicit CustomerLinkedList(bool sorted);
        explicit CustomerLinkedList(Customer* customer,bool sorted=false);
        CustomerLinkedList(const CustomerLinkedList& another);
        CustomerLinkedList(CustomerLinkedList&& another)noexcept;
        ~CustomerLinkedList();
        void Swap(CustomerLinkedList& another);
        void Reset();
        CustomerLinkedList& operator=(CustomerLinkedList another);

        // �����
        // FIFO�����ʺϺ򲹶���
        void Insert(Customer* customer);
        void Insert(Customer customer);

        // ����棬����������
        // �ʺ��Ѿ���Ʊ�Ķ���
        void InsertSorted(Customer* customer);
        void InsertSorted(Customer customer);

        // ����������Ψһ�ģ�����ֻ�᷵��һ��Customer
        Customer* Get(std::string customer_name);

        void Delete(std::string customer_name);

    };
}

