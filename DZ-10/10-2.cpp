#include <iostream>
#include <new>

template<typename OT, typename ... Types>
OT* func(Types... args)
{
    OT* ptr = new OT(args...);
    return ptr;
}

int main()
{
    std::cout << "Hello World!\n";
}
