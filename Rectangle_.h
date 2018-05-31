#pragma once
#include "Point.h"
class Rectangle_ :public Point
{
public:
	Rectangle_(int l = 0, int t = 0, int r = 0, int b = 0);
	virtual void set(int, int);
	virtual void draw() const;
	virtual void drawfill() const;
	virtual void AdjustPoint(mouse_msg msg);
	virtual void InitialPoint(mouse_msg msg);
protected:
	int right;
	int bottom;
};