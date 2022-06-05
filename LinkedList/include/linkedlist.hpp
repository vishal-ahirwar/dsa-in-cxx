#ifndef __LINKED__LIST__
#define __LINKED__LIST__
#include <iostream>
#include <iomanip>
template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &data)
        {
            this->data = data;
        };
    };

private:
    Node *head, *tail;
    size_t size;

public:
    LinkedList();
    void display(void) const;
    void append(const T &data);
    void remove(const T &);
    void prepend(const T &);
    void removeFirstNode();
    void removeLastNode();
    void removeAt(const size_t &pos);
    size_t getSize() const { return this->size; };
};
template <typename T>
void LinkedList<T>::removeAt(const size_t &pos)
{
    if (pos > this->size || pos < 1)
    {
        return;
    }
    else if (pos == 1)
    {
        this->removeFirstNode();
    }
    else if (pos == this->size)
    {
        this->removeLastNode();
    }
    else if (this->head != nullptr)
    {
        Node *prev{head}, *cur{head};
        for (size_t i = 0; i < pos; ++i)
        {
            prev = cur;
            cur = cur->next;
        };
        prev->next = cur->next;
        free(cur);
        --this->size;
    };
}
template <typename T>
void LinkedList<T>::removeLastNode()
{
    Node *prev{head}, *cur{head};
    if (head->next == nullptr)
    {
        this->removeFirstNode();
    }
    else if (head != nullptr)
    {
        while (cur->next != nullptr)
        {
            prev = cur;
            cur = cur->next;
        };
        tail = prev;
        prev->next = nullptr;
        free(cur);
        --this->size;
    };
}
template <typename T>
void LinkedList<T>::removeFirstNode()
{
    if (head != nullptr)
    {

        Node *temp = head;
        head = head->next;
        free(temp);
        --this->size;
    };
};

template <typename T>
void LinkedList<T>::prepend(const T &data)
{
    Node *node = new Node(data);

    if (this->head == nullptr)
    {
        head = node;
        tail = node;
    }
    else
    {

        node->next = head->next;
        head->next = node;
    };
}

template <typename T>
void LinkedList<T>::remove(const T &key)
{
    Node *temp_head = head;
    Node *temp_node = this->head;
    Node *step_back = nullptr;
    while (temp_node)
    {
        if (temp_node->data == key)
        {
            step_back = temp_node->next;
            free(temp_node);
            --this->size;
            return;
        }
        else
        {
            step_back = temp_node;
            temp_node = temp_node->next;
        };
    }
}
template <typename T>
void LinkedList<T>::append(const T &data)
{
    Node *temp_node = new Node(data);
    // temp_node->next=nullptr;

    if (head == nullptr)
    {
        head = temp_node;
        tail = temp_node;
    }
    else
    {
        tail->next = temp_node;
        tail = temp_node;
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
    const Node *temp_node = this->head;
    while (temp_node)
    {

        std::cout << temp_node->data << "\n";
        temp_node = temp_node->next;
    };
};

#endif