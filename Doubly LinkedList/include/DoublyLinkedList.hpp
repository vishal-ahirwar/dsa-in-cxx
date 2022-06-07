#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include<iostream>

template <typename T>
class DoublyLinkedList
{
private:
    class Node
    {
        public:
        Node *prev=nullptr;
        T data;
        Node *next=nullptr;
        Node(const T& data):data{data}{};
    } * header, *tail;

private:
    size_t size;

public:
    DoublyLinkedList() : header{nullptr}, tail{nullptr}, size{0} {};
    size_t getSize() const { return this->size; };
    void display() const;
    void prepend(const T &);
    void append(const T&);
    void removeAt(const size_t&);
    void insertAt(const size_t&);
};
template <typename T>
void DoublyLinkedList<T>::display() const
{
    if(this->getSize()<1)
    {
        printf("\nNaN\n");
        return;
    };
    Node *temp = this->header;
    printf("\n[");
    while (temp != nullptr)
    {
        std::cout << temp->data << ", ";
        temp=temp->next;
    };
    printf("]\n");
};

template <typename T>
void DoublyLinkedList<T>::prepend(const T &data){
   Node* new_node=new Node(data);
    if(this->header==nullptr)
    {
        header=new_node;
        tail=new_node;
    }else
    {
        header->prev=new_node;
        new_node->next=header;
        header=new_node;
    };
    ++this->size;
};

#endif