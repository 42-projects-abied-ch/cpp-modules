#include "../inc/Point.hpp"

Point::Point() : x(0), y(0){
}

Point::Point(const Point & point) : x(point.x), y(point.y){
}

Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)){
}

Point::~Point(){
}

Point & Point::operator = (const Point &point){
	this->~Point();
	new(this) Point(point.x.toFloat(), point.y.toFloat());
	return *this;
}

float Point::getX() const{
	return this->x.toFloat();
}

float Point::getY() const{
	return this->y.toFloat();
}
