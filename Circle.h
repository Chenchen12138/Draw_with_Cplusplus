#pragma once
#include "Point.h"
class Circle :public Point
{
public:
	Circle(int xx = 0, int yy = 0, int rr = 0);
	virtual void set(int, int);
	virtual void draw() const;
	virtual void drawfill() const;
	virtual void AdjustPoint(mouse_msg msg);
	virtual void InitialPoint(mouse_msg msg);
private:
	int radius;
};