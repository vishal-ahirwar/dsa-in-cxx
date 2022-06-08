#ifndef QUEUE
#define QUEUE
#include <iostream>
template <typename T>
class Queue
{
private:
    size_t front{}, rear{};
    size_t size{};
    size_t nelements{};
    T *queue{};

public:
    Queue(const size_t &size) : size{size}, front{0}, rear{0}, nelements{0}, queue{new T[size]} {};
    size_t getQueueSize() const { return this->size; };
    size_t getnelement() const { return this->nelements; };
    void enqueue(const T &);
    T dequeue();
    void resize_queue();
    void display() const;
};

template <typename T>
void Queue<T>::enqueue(const T &data)
{
    if (this->nelements == 0)
    {
        front = rear = 0;
        this->queue[rear] = data;
        ++rear;
        ++this->nelements;
    }
    else if (this->nelements >= this->size)
    {
        printf("[warning] queue is full!\n");
        return;
    }
    else
    {
        rear = (rear + 1) % size;
        printf("[message] enqueue data at index : %lu\n", rear);
        this->queue[rear] = data;
        ++this->nelements;
    };
};

template <typename T>
T Queue<T>::dequeue(){

};
template <typename T>
void Queue<T>::display() const
{
    for (size_t i = front; i <= rear; ++i)
    {
        std::cout << this->queue[i] << ", ";
    };
};

#endif