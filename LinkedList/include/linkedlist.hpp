#ifndef __LINKED__LIST__
#define __LINKED__LIST__
#include <iostream>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T& data)
        {
            this->data=data;
        };
    };

public:
    Node *head, *tail;
    size_t size;

public:
    LinkedList();
    void display(void) const;
    void append(const T &data);
};

template <typename T>
void LinkedList<T>::append(const T &data)
{
    Node *temp_node = new Node(data);

    if (head == nullptr)
    {
        head = temp_node;
        tail = temp_node;
    }
    else
    {
        tail->next = temp_node;
        tail=temp_node;
    }
    ++size;
}

template <typename T>
LinkedList<T>::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
};

template <typename T>
void LinkedList<T>::display(void) const
{
    printf("sizeof obj type : %lu byte\n", sizeof(T));
    Node* temp_node=head;
    for(size_t i=0;i<size;++i)
    {
        printf("Node[%lu]->",i);
        std::cout<<temp_node->data<<"\n";
        temp_node=temp_node->next;
    };
};

#endif