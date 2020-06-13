#pragma once
#include <memory>
template<typename T>
class Node {
   public:
    Node() = delete;
    explicit Node(T data, Node* next_node = nullptr);

    Node(const Node& another);

    Node(Node&& another) noexcept;
    void Reset();
    void Swap(Node& another);
    Node<T>& operator=(Node another);
    // 返回指针，可以直接修改数据
    T* GetData() const;
    // 把原来的delete，再用复制构造器新建一个
    void SetData(T data);

    Node<T>* GetNextNode();

    void SetNextNode(Node<T>* next_node);

    ~Node();

   private:
    T* data_;
    Node<T>* next_node_;
};
template<typename T>
Node<T>::Node(T data, Node* next_node) {
    data_      = new T(data);
    next_node_ = next_node;
}

template<typename T>
void Node<T>::Reset() {
    delete data_;
    next_node_ = nullptr;
}

template<typename T>
void Node<T>::Swap(Node& another) {
    std::swap(data_, another.data_);
    next_node_ = another.next_node_;
}

template<typename T>
Node<T>& Node<T>::operator=(Node another) {
    Swap(another);
    return *this;
}

template<typename T>
T* Node<T>::GetData() const {
    return data_;
}

template<typename T>
void Node<T>::SetData(T data) {
    delete data_;
    data_ = new T(data);
}

template<typename T>
Node<T>* Node<T>::GetNextNode() {
    return next_node_;
}

template<typename T>
void Node<T>::SetNextNode(Node<T>* next_node) {
    next_node_ = next_node;
}
template<typename T>
Node<T>::~Node() {
    Reset();
}
template<typename T>
Node<T>::Node(Node&& another) noexcept {
    data_      = std::move(another.data_);
    next_node_ = another.next_node_;
    another.Reset();
}
template<typename T>
Node<T>::Node(const Node& another) {
    data_      = another.data_;
    next_node_ = another.next_node_;
}