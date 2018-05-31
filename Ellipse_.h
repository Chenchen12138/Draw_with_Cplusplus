#pragma once
#include "Point.h"
class Ellipse_ :public Point
{
public:
	Ellipse_(int a = 0, int b = 0, int xr = 0, int yr = 0);
	virtual void set(int, int);
	virtual void draw() const;
	virtual void drawfill() const;
	virtual void AdjustPoint(mouse_msg msg);
	virtual void InitialPoint(mouse_msg msg);
protected:
	int xradius;
	int yradius;
};