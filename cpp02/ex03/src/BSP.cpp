#include "../inc/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point){
	float d1;
	float d2;
	float d3;

	d1 = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX());
	d2 = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (point.getY() - b.getY()) * (c.getX() - b.getX());
	d3 = (point.getX() - a.getX()) * (c.getY() - a.getY()) - (point.getY() - a.getY()) * (c.getX() - a.getX());
	bool neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return !(neg && pos);
}