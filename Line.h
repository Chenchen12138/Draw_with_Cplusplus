#pragma once
#include "Point.h"
class Line :public Point
{
public:
	Line(int x1=0, int y1=0, int x2=0, int y2=0);
	virtual void draw() const;
	virtual void set(int, int);
	virtual void drawfill() const{}
	virtual void AdjustPoint(mouse_msg msg);
	virtual void InitialPoint(mouse_msg msg);
protected:
	int x2;
	int y2;
};
