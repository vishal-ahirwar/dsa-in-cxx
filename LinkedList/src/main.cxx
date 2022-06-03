#include"../include/linkedlist.hpp"
int main(void)
{
    LinkedList<double> *rates;
    // rates.display();

for(auto i=0;i<12000;++i)
{
    rates->append(i*0.04);
}
    rates->display();

    return 0;
};