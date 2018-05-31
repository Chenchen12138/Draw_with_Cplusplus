#pragma once
#include <graphics.h>
#include <cmath>
class Shape
{
public:
	virtual void setxy(int, int) = 0;
	virtual void set(int, int) = 0;
	virtual void draw() const = 0;
	virtual void drawfill() const = 0;	
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual void AdjustPoint(mouse_msg msg) = 0;
	virtual void InitialPoint(mouse_msg msg) = 0;
};