#include "stdafx.h"
#include "Line.h"
Line::Line(int x1, int y1, int x, int y) :Point(x1, y1)
{
	x2 = x;
	y2 = y;
}
void Line::draw() const
{
	line(x, y, x2, y2);
}
void Line::set(int xx, int yy)
{
	x2 = xx;
	y2 = yy;
}
void Line::InitialPoint(mouse_msg msg)
{
	set(msg.x, msg.y);
}
void Line::AdjustPoint(mouse_msg msg)
{
	set(msg.x, msg.y);
}