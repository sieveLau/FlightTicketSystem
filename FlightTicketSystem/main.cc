#include <sys/types.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <initializer_list>
#include <iostream>
#include <string>

#include "customer.h"
#include "customer_linked_list.h"
#include "customer_node.h"
#include "day_name.h"
#include "flight.h"
#include "flight_booker.h"
#include "flight_linked_list.h"
#include "flight_list_initializer.h"
#include "flight_node.h"
#include "flight_searcher.h"
#include "refunder.h"
#include "simple_flight.h"
#include "simple_flight_linked_list.h"

void PrintCustomers(ds::CustomerLinkedList* customer_list) {
    ds::Customer** customers = customer_list->GetAll();
    ds::Customer* customer   = customers[0];
    for (int i = 0; customer != nullptr;) {
        std::cout << i << ": " << customer->GetName() << std::endl;
        customer = customers[++i];
    }
    ds::PrintHorizonLine();
    delete[] customers;
}

int main() {
    // 初始化航班表
    auto* fll = ds::InitFlightList();

    // 测试搜索系统（1）：搜索符合目的地的航班，打印最近一天的航班的日期和余票额

    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);

    ds::SearchFlight(fll, std::string("Beijing"), ds::DAYS::WES);

    // 测试搜索系统（2）：跨星期搜索

    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::THU);

    // 测试搜索系统（3）：搜索不存在的目的地的航班

    ds::SearchFlight(fll, std::string("HZ"), ds::DAYS::WES);

    ds::CustomerLinkedList booked(true);
    ds::CustomerLinkedList waiting(false);

    /*
     *=======================================================================

     * 测试订票系统
     * 每次订完票查询一次航班现状

    */

    // 测试订票系统（1）：有足够余票订票，第一位客户
    ds::Check("FM9158", 4, 0, 0, "Freda", fll, &booked, &waiting);
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // // 测试订票系统（2）：有足够余票订票，第二位客户
    ds::Check("FM9158", 0, 0, 5, "Gail", fll, &booked, &waiting);
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // // 测试订票系统（3）：有足够余票订票，第三位客户
    ds::Check("FM9158", 0, 0, 8, "Hazel", fll, &booked, &waiting);
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // // 测试订票系统（4）：没有足够余票订票，第四位客户，拒绝候补
    ds::Check("FM9158", 0, 0, 8, "Hulda", fll, &booked, &waiting);
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // // 测试订票系统（5）：没有足够余票订票，第四位客户，愿意候补
    ds::Check("FM9158", 0, 0, 8, "Hulda", fll, &booked, &waiting);
    ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    printf("Customers waiting:\n");
    PrintCustomers(&waiting);
    
    printf("Customers booked:\n");
    PrintCustomers(&booked);

    /*
     *=======================================================================

     * 测试退票系统
     * 每次退完票查询一次航班现状

    */

    // 测试退票系统（1）：退票，没人候补
    // ds::Refunder("Freda", ds::DAYS::TUE, "FM9158", &booked, &waiting, fll);
    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // printf("Customers waiting:\n");
    // PrintCustomers(&waiting);
    // printf("Customers booked:\n");
    // PrintCustomers(&booked);
    //
    // // 测试退票系统（2）：重复退票
    // ds::Refunder("Freda", ds::DAYS::TUE, "FM9158", &booked, &waiting, fll);
    // ds::Refunder("Freda", ds::DAYS::TUE, "FM9158", &booked, &waiting, fll);
    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // // 测试退票系统（3）：退票，有人候补
    // ds::Refunder("Gail", ds::DAYS::TUE, "FM9158", &booked, &waiting, fll);
    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::TUE);
    //
    // printf("Customers waiting:\n");
    // PrintCustomers(&waiting);
    // printf("Customers booked:\n");
    // PrintCustomers(&booked);





    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);
    // ds::Check("FM9987", 0, 8, 0, "Adam", fll, &booked, &waiting);
    // ds::Check("FM9987", 0, 2, 0, "Abam", fll, &booked, &waiting);
    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);
    // // ds::Check("FM9987", 0, 8, 0, "Adam", fll, &booked, &waiting);

    // auto* booked_adam = booked.Get("Adam")->GetSeatBooked("FM9987");
    // //务必确认get回来的是不是nullptr，这里是不会帮你检查的，下面这条就会暴毙
    // // auto * waiting_adam = waiting.Get("Adam")->GetSeatBooked("FM9987");

    // ds::Refunder("Adam", ds::DAYS::WES, "FM9987", &booked, &waiting, fll);
    // ds::SearchFlight(fll, std::string("Hangzhou"), ds::DAYS::WES);
    return 0;
}
