#pragma once
#include <memory>

#include "customer.h"
namespace ds {
    class CustomerNode {
       public:
        CustomerNode() = delete;
        explicit CustomerNode(ds::Customer* data, CustomerNode* next_node = nullptr);

        CustomerNode(const CustomerNode& another);

        CustomerNode(CustomerNode&& another) noexcept;
        void Reset();
        void Swap(CustomerNode& another);
        CustomerNode& operator=(CustomerNode another);
        ~CustomerNode();

        // 返回指针，可以直接修改数据
        ds::Customer* GetData() const;
        // 把原来的delete，再用复制构造器新建一个
        void SetData(ds::Customer* data);

        CustomerNode* GetNextNode();

        void SetNextNode(CustomerNode* next_node);

        

       private:
        ds::Customer* data_;
        CustomerNode* next_node_;
    };
}  // namespace ds