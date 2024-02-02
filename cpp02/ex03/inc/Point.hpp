#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point{
	public:
		Point();
		Point(const Point & point);
		Point(const float x, const float y);
		Point & operator = (const Point & point);
		~Point();

		float 	getX() const;
		float 	getY() const;
	private:
		Fixed const x;
		Fixed const y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
