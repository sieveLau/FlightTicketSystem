#pragma once
namespace sieve {
    class DoubleLinkedNode {
        int data_;
        DoubleLinkedNode* next_node_;
        DoubleLinkedNode* prev_node_;

       public:
        DoubleLinkedNode() = delete;
        explicit DoubleLinkedNode(int data,
                                  DoubleLinkedNode* prev_node = nullptr,
                                  DoubleLinkedNode* next_node = nullptr);
        DoubleLinkedNode(DoubleLinkedNode&& another) noexcept;
        DoubleLinkedNode(const DoubleLinkedNode& another);
        ~DoubleLinkedNode();

        void SetData(int data);
        void SetNextNode(DoubleLinkedNode* node);
        void SetPrevNode(DoubleLinkedNode* node);

        int GetData() const;
        DoubleLinkedNode* GetNextNode() const;
        DoubleLinkedNode* GetPrevNode() const;

        void Reset();
        DoubleLinkedNode& operator=(DoubleLinkedNode another);
        void swap(DoubleLinkedNode&);
    };
}  // namespace sieve