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
    /**
     * @brief Construct a new Linked List object
     *
     */
    LinkedList();
    /**
     * @brief Destroy the Linked List object
     * 
     */
    ~LinkedList();
    /**
     * @brief Display All the data
     *
     */
    void display(void) const;
    void append(const T &data);
    /**
     * @brief Need operator Overloading if you want use with data instead of key
     * for custom data type or even with string
     *
     */

    /**
     * @brief Remove Partcular data
     *
     */
    void remove(const T &);
    /**
     * @brief append data to front of the linkedlist
     *
     */
    void prepend(const T &);
    /**
     * @brief Remove Node From the front side
     *
     */
    void removeFirstNode();
    /**
     * @brief Remove Node From last
     *
     */
    void removeLastNode();
    /**
     * @brief Remove Node with particular position
     *
     * @param pos
     */
    void removeAt(const size_t &pos);
    /**
     * @brief Get the Size LinkedList
     *
     * @return size_t
     */
    size_t getSize() const { return this->size; };
    void insert(const size_t &, const T &);
};
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* next=nullptr;
    while(head!=nullptr)
    {
      next=head->next;
      delete head;
      head=next;
    }
}
template <typename T>
void LinkedList<T>::insert(const size_t &pos, const T &data)
{
    if (pos > 1 && pos < getSize())
    {
        Node *new_node = new Node(data);
        Node *prev = nullptr;
        Node *cur = this->head;
        for (size_t i = 1; i < pos; ++i)
        {
            prev = cur;
            cur = cur->next;
        };
        prev->next = new_node;
        new_node->next = cur;
        ++this->size;
    }
}
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
    Node *prev{head}, *cur{head};
    if (head != nullptr)
    {
        while (cur->next != nullptr)
        {
            if (cur->data == key)
            {
                prev->next = cur->next;
                free(cur);
                --this->size;
                return;
            };
            prev = cur;
            cur = cur->next;
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
    printf("[object type : %s, Size of Linkedlist : %lu]\n",typeid(T).name(),this->getSize());
    const Node *temp_node = this->head;
    while (temp_node)
    {

        std::cout << temp_node->data << "\n";
        temp_node = temp_node->next;
    };
};

#endif