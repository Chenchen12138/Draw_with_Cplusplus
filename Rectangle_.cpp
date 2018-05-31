#include "stdafx.h"
#include "Rectangle_.h"
Rectangle_::Rectangle_(int l, int t, int r, int b) :Point(l, t)
{
	right = r;
	bottom = b;
}
void Rectangle_::set(int r, int b)
{
	right = r;
	bottom = b;
}
void Rectangle_::draw() const
{
	rectangle(x, y, right, bottom);
}
void Rectangle_::drawfill() const
{
	bar3d(x, y, right, bottom, 0, 0);
}
void Rectangle_::AdjustPoint(mouse_msg msg)
{
	set(msg.x, msg.y);
}
void Rectangle_::InitialPoint(mouse_msg msg)
{
	set(msg.x, msg.y);
}