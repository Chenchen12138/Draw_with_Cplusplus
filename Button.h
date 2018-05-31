#pragma once
#include <graphics.h>
class Button   //²Ëµ¥°´Å¥
{
private:
	int left, top, right, bottom;
	PIMAGE pImage;

public:
	Button(int l, int t, int r, int b, const char *file)
	{
		left = l;
		top = t;
		right = r;
		bottom = b;
		pImage = newimage();
		getimage_pngfile(pImage, file);
	}
	void show()
	{
		putimage(left, top, pImage);
		setcolor(BLACK);
		rectangle(left, top, right, bottom);
	}
};