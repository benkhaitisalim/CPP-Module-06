#include "Base.hpp"

Base * generate(void)
{
    int index = std::rand() % 3;
    if(index == 0)
    {
        return new A();
    }
    else if(index == 1)
    {
        return new B();
    }
    else 
    {
        return new C();
    }
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if(dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if(dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
}
void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(std::bad_cast&)
    {

    }
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(std::bad_cast&)
    {

    }
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(std::bad_cast&)
    {

    }

}

int main()
{
    std::srand(std::time(NULL));

    Base* ptr = generate();

    std::cout << "Identify via pointer: ";
    identify(ptr);

    std::cout << "Identify via reference: ";
    identify(*ptr);

    delete ptr;
    return 0;
}
