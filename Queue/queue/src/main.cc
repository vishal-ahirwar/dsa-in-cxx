

//Auto Genrated C++ file by newton CLI
#include"../include/queue.hpp"

static inline void say_hello()
{
    std::cerr<<"Hello, World\n";
};
int main(int argc,char*argv[])
{
    Queue<double>* rates{};
    rates=new Queue<double>(10);
    for(size_t i=0;i<rates->getQueueSize();++i)
    {
        rates->enqueue(44.3);
    };
    rates->display();
    say_hello();
    return 0;
};

