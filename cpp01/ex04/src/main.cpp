#include "../inc/main.hpp"
#include <cstdlib>
#include <fstream>

void replace(std::string *line, std::string to_replace, std::string new_str){
    size_t start_pos;
    while ((start_pos = (*line).find(to_replace)) != std::string::npos){
        (*line).erase(start_pos, to_replace.length());
        (*line).insert(start_pos, new_str);
    }
}

int main(int argc, char **argv){
    if (argc != 4 || !argv[2][0] || !argv[3][0]){
        std::cout << "arguments error" << std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream   input(argv[1]);
    if (!input.is_open()){
        std::cout << "could not open input file" << std::endl;
        return EXIT_FAILURE;
    }
    std::string name = (std::string)argv[1] + ".replace";
	std::ofstream	output(name.c_str());
    if (!output.is_open()){
        std::cout << "could not open output file" << std::endl;
        return EXIT_FAILURE;
    }
    std::string line;
    std::string to_replace = argv[2];
    std::string new_str = argv[3];
    while (std::getline(input, line)){
        replace(&line, to_replace, new_str);
        if (!std::cin.eof())
            output << line << std::endl;
    }
    output.close();
    input.close();
    return EXIT_SUCCESS;
}