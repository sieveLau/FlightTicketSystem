#pragma once

class Node
{
public:
    explicit Node(int data);

    explicit Node(int data, Node* nextnode);

    Node(const Node& another);

    int GetData() const;

    void SetData(int data);

    Node* GetNextNode();

    void SetNextNode(Node* next_node);

    ~Node();

    Node& operator=(const Node& another);

private:
    int data_;
    Node* next_node_;
};
