#include "../inc/Point.hpp"

int main(){
	Point a(0, 0);
	Point b(1000, 1000);
	Point c(1000, 0);
	Point point(500, 0);
	Point point2(0, 0);
	std::cout << (bsp(a, b, c, point) ? "IN" : "OUT") << std::endl;
	std::cout << (bsp(a, b, c, point2) ? "IN" : "OUT") << std::endl;
}