#include "stdafx.h"
#include "Circle.h"
Circle::Circle(int x, int y, int r) :Point(x, y)
{
	radius = r;
}
void Circle::set(int r, int m)
{
	radius = r;
}
void Circle::draw() const
{
	circle(x, y, radius);
}
void Circle::drawfill() const
{
	fillellipse(x, y, radius, radius);
}
void Circle::AdjustPoint(mouse_msg msg)
{
	int dx = getX() - msg.x;
	int dy = getY() - msg.y;
	int dr = (int)sqrt(dx * dx + dy * dy);
	set(dr, 0);
}
void Circle::InitialPoint(mouse_msg msg)
{
	set(0, 0);
}