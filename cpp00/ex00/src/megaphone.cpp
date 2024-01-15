#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string output;
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		for (int len = 0; arg[len]; len++)
			arg[len] = toupper(arg[len]);
		output += arg;
	}
	if (output.empty()) 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		std::cout << output << std::endl;
	return (0);
}
