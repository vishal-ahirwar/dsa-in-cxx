

//Auto Genrated C++ file by newton CLI
#include"../include/BST.hpp"

static inline void say_hello()
{
    std::cerr<<"\nHello, World\n";
};
int main(int argc,char*argv[])
{
    BST<double>* rates{};
    rates=new BST<double>();
    rates->insert(44.4);
    rates->insert(23.4);
    rates->insert(56.43);
    
    say_hello();
    return 0;
};

