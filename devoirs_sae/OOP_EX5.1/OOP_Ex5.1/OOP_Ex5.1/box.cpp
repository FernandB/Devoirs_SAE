#include "stdafx.h"
#include "box.h"


Box::Box(double x, double y, double size_x, double size_y): x(x), y(y), size_x(size_x), size_y(size_y)
{
}

bool Box::isColliding(Box& box2)
{
	if (x < box2.x + box2.size_x &&
		x + size_x > box2.x &&
		y < box2.y + box2.size_y &&
		size_y + y > box2.y) {
		// collision détectée !
		return true;
	}
	else
		return false;
}

