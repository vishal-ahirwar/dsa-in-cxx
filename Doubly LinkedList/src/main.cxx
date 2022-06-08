#include "../include/DoublyLinkedList.hpp"

int main(void)
{
    printf("hello, world!\n");
    DoublyLinkedList<double> *rates = (DoublyLinkedList<double> *)malloc(sizeof(DoublyLinkedList<double>));
    // rates = nullptr;
    rates->prepend(23.4);
    rates->prepend(55.45);
    rates->prepend(889.45);
    printf("after prepending ...");
    rates->display();

    printf("endof the program ...\n");
    return 0;
}