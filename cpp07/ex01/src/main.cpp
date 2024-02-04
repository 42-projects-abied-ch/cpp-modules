#include "../inc/iter.hpp"
#include <string>

template <typename S>
void    printThis(const S &thing)
{
    std::cout << thing << std::endl;
}

int main()
{
    std::string arr[3] =
    {
        "This",
        "Is",
        "Fun"
    };
    const int   tab[4] = { 1, 2, 3, 4 };
    iter(tab, 4, printThis);
    iter(arr, arr->length(), printThis);
}