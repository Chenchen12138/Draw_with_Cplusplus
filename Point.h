#pragma once
#include "Shape.h"
class Point:public Shape
{
public:
	Point(int a= 0, int b= 0)
	{
		x = a;
		y = b;

	}
	virtual int getX() const { return x; }
	virtual int getY() const { return y; }
	virtual void setxy(int a, int b) { x = a; y = b; }
protected:
	int x;
	int y;
};