#include "../inc/Harl.hpp"

int main(int argc, char **argv){
    Harl _Harl;
    if (argc != 2){
        std::cout << "arguments error" << std::endl;
        return EXIT_FAILURE;
    }
    _Harl.complain(argv[1]);
    return EXIT_SUCCESS;
}