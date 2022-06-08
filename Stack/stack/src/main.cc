

// Auto Genrated C++ file by newton CLI
#include "../include/stack.hpp"

int main(int argc, char *argv[])
{
    Stack_Static<double> *rates;
    rates = new Stack_Static<double>(10);
    for (int i = 0; i < rates->getStack_size(); ++i)
        rates->push(44.5);
    rates->display();
    printf("\npoped element: %lf\n",rates->pop());
    return 0;
};
