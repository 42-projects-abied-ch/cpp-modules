#include "../inc/Harl.hpp"

int main(){
    Harl _Harl;
    _Harl.complain("debug");
    _Harl.complain("not a message");
    _Harl.complain("info");
    _Harl.complain("warning");
    _Harl.complain("error");
    return 0;
}