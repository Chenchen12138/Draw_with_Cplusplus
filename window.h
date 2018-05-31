#pragma once
#include <graphics.h>
#include <string>
class window
{
private:
	int left, top, right, bottom;
	std::string title;

public:
	window(int l, int t, int r, int b, const char *titl)
	{
		left = l;
		top = t;
		right = r;
		bottom = b;
		title = titl;
	}
	void show()
	{
		setfillcolor(WHITE);
		bar(left, top, right, bottom);
		setfillcolor(GREEN);
		setbkcolor_f(GREEN);
		bar(left, 0, right, 24);
		setcolor(WHITE);
		outtextxy(0, 0, title.c_str());
		setfillcolor(LIGHTGRAY);
		bar(left, 24, 36, bottom);
	}
};