#include "Serialization.hpp"

int main(void)
{
    Data data;
    data.value = 42;
    Data *serial = &data;
    uintptr_t i = Serializer::serialize(&data);
    Data *original = Serializer::deserialize(i);
    std::cout << "Original : " << serial << std::endl;
    std::cout << "i : " << i << std::endl;
    std::cout << "serialize : " << original << std::endl;
    return 0;
}