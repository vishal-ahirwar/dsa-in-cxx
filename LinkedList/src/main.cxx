#include "../include/linkedlist.hpp"

int main(void)
{
    LinkedList<double> *rates{};
    rates = (LinkedList<double> *)malloc(sizeof(LinkedList<double>));
    LinkedList<char> *Alpha = (LinkedList<char> *)malloc(sizeof(LinkedList<char>));
    for (char alpha = 'a'; alpha <= 'c'; ++alpha)
    {
        Alpha->append(alpha);
    };
    Alpha->display();
    Alpha->remove('x');
    printf("\nAfter inserting done!\n");
    Alpha->display();
    /**
        for (short i = 0; i < 10; ++i)
        {
            rates->append((double)(i * 0.04));
        }
        if (rates)
        {

            rates->display();
            printf("\nsize of rates list: %lu\nafter removing 3 ...\n", rates->getSize());
            rates->remove(0.2);
            rates->display();
            printf("\nsize of rates list: %lu\n",rates->getSize());
        }
        else
        {
            printf("rates is nullptr!\n");
        };
    **/
    Alpha->~LinkedList();
    free(Alpha);
    free(rates);
    return 0;
};