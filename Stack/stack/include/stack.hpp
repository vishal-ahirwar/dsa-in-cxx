#ifndef STACK
#define STACK
#include<iostream>
template<typename T>
class Stack_Static
{
    public:
        Stack_Static(const size_t&size):stack{new T[size]},top{0},stack_size{size}{};
    private:
        size_t stack_size{};
        size_t top{};
        T *stack{};
    public:
        size_t getStack_size()const{return this->stack_size;};
        void push(const T&);
        T pop();
        void display()const;
        void resize_Stack();
};
template<typename T>
void Stack_Static<T>::display()const
{
    for(auto index=this->top;index>0;--index)
    {
        std::cout<<this->stack[index]<<" ,";
    };
}

template<typename T>
void Stack_Static<T>::push(const T& data)
{
    if(this->top<this->stack_size)
    {

    this->stack[++this->top]=data;

    }else
    {
        printf("[warning] stack is full!\n");
    };
};

template<typename T>
T Stack_Static<T>::pop()
{
    if(!this->top>0)
    {
        printf("[warning] stack is already empty!\n");
        return 0.0;
    };

    auto temp{this->stack[this->top]};
    this->stack[this->top]=0;
    --this->top;
    return temp;
};

#endif