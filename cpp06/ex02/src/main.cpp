#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstddef>

int main()
{
	Base	*arr[5];

	for (size_t i = 0; i < 5; i++)
	{
		arr[i] = generate();
		std::cout << "--- arr[" << i << "] ---" << std::endl;
		identify(arr[i]);
		identify(*arr[i]);
		delete arr[i];
	}
}