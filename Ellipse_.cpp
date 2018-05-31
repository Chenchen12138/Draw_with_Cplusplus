#include "stdafx.h"
#include "Ellipse_.h"
Ellipse_::Ellipse_(int a, int b, int xr, int yr) :Point(a, b)
{
	xradius = xr;
	yradius = yr;
}
void Ellipse_::set(int xr, int yr)
{
	xradius = xr;
	yradius = yr;
}
void Ellipse_::draw() const
{
	ellipse(x, y, 0 , 360 ,xradius, yradius);
}
void Ellipse_::drawfill() const
{
	fillellipse(x, y, xradius, yradius);
}
void Ellipse_::InitialPoint(mouse_msg msg)
{
	set(abs(msg.x - getX()), abs(msg.y - getY()));
}
void Ellipse_::AdjustPoint(mouse_msg msg)
{
	set(abs(msg.x - getX()), abs(msg.y - getY()));
}