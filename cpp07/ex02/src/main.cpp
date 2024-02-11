#include "../inc/Array.hpp"
#include <exception>

int main()
{
    Array <std::string> arrA;
    Array <std::string> arrB(3);
    Array <std::string> arrC(5);
    Array <std::string> arrD(arrC);
    
    arrC[0] = "Hello World";
	for (size_t i = 0; i < arrD.size(); i++)
	{
		arrD[i] = "";
		for (size_t j = i; j > 0; j--)
			arrD[i] += "Word";
	}
    arrC = arrB;
    arrB[2] = "dlroW olleH";
    try
    {
        arrB[3] = "Jar Jar Binks";
    }
    catch (const std::exception &index)
    {
        std::cerr << index.what() << std::endl;
    }
    std::cout << "arrA:\n" << arrA << std::endl;
    std::cout << "arrB:\n" << arrB << std::endl;
    std::cout << "arrC:\n" << arrC << std::endl;
	std::cout << "arrD:\n" << arrD << std::endl;

	Array <int> arr1(10);

	for (size_t i = 0; i < arr1.size(); i++)
		arr1[i] = i * 123;

	Array <int> arr2(arr1);

	std::cout << "arr1:\n" << arr1 << std::endl;
	std::cout << "arr2:\n" << arr2 << std::endl;
}