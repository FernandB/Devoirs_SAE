#include "stdafx.h"
#include "shapes.h"
#include <cmath>
//Les constructeurs
Shape::Shape(double x, double y):x(x),y(y)
{
}

Rectangle::Rectangle(double x, double y,double width, double height) : Shape(x,y), width(width),height(height)
{
}

Circle::Circle(double x, double y,double radius) : Shape(x, y), radius(radius)
{
}


//Methode de la class Shape-----------------------------------------------------
bool Shape::isColliding(Shape*)
{
	return true;
}

//Methodes de la class Circle----------------------------------------------------


double Circle::getX()
{
	return x;
}

double Circle::getY()
{
	return y;
}
double Circle::getRadius()
{
	return radius;
}
bool Circle::isColliding(Circle* circle2)
{
	double dx = getX() - circle2->getX();
	double dy = getY() - circle2->getY();
	double distance = sqrt(dx * dx + dy * dy);

	if (distance < getRadius() + circle2->getRadius()) {
		// collision détectée !
		return true;
	}
	else
		return false;
}

bool Circle::isColliding(Rectangle* rectangle)
{


	double dx = abs(getX() - rectangle->getX());
	double dy = abs(getY() - rectangle->getY());

	if (dx > (rectangle->getWidth() / 2 + getRadius())) { return false; }
	if (dy > (rectangle->getHeight() / 2 + getRadius())) { return false; }

	if (dx <= (rectangle->getWidth() / 2)) { return true; }
	if (dy <= (rectangle->getHeight() / 2)) { return true; }

	double cornerDistance = (dx - rectangle->getWidth() / 2)*(dx - rectangle->getWidth() / 2) +
		(dy - rectangle->getHeight() / 2) *(dy - rectangle->getHeight() / 2);

	return (cornerDistance <= (radius*radius));
}

bool Circle::isColliding(Shape* shape)
{
	if ((Circle*)shape == dynamic_cast<Circle*>(shape)) {
		return isColliding(shape);
	}
	else
	{
		if ((Rectangle*)shape == dynamic_cast<Rectangle*>(shape)) {
			return isColliding(shape);
		}
	}
	return isColliding(shape);
}

//Methodes de la class Rectangle----------------------------------------------------
double Rectangle::getX()
{
	return x;
}

double Rectangle::getY()
{
	return y;
}

double Rectangle::getWidth()
{
	return width;
}

 double Rectangle::getHeight()
{
	return height;
}


bool Rectangle::isColliding(Shape* shape)
{
	if ((Circle*)shape == dynamic_cast<Circle*>(shape)) {
		return isColliding(shape);
	}
	else
	{
		if ((Rectangle*)shape == dynamic_cast<Rectangle*>(shape)) {
			return isColliding(shape);
		}
	}
	return isColliding(shape);
}

bool Rectangle::isColliding(Circle* circle)
{
	double dx = abs(circle->getX() - getX());
	double dy = abs(circle->getY() - getY());

	if (dx > (getWidth() / 2 + circle->getRadius())) { return false; }
	if (dy > (getHeight() / 2 + circle->getRadius())) { return false; }

	if (dx <= (getWidth() / 2)) { return true; }
	if (dy <= (getHeight() / 2)) { return true; }

	double cornerDistance = (dx - getWidth() / 2)*(dx - getWidth() / 2) +
		(dy - getHeight() / 2) * (dy - getHeight() / 2);

	return (cornerDistance <= (circle->getRadius()*circle->getRadius()));
}
bool Rectangle::isColliding(Rectangle* rectangle)
{
	if (getX() < rectangle->getX() + rectangle->getWidth() &&
		getX() + getWidth() > rectangle->getX() &&
		getY() < rectangle->getY() + rectangle->getHeight() &&
		getHeight() + y > rectangle->getY()) {
		// collision détectée !
		return true;
	}
	else
		return false;
}
