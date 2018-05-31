#include <graphics.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

class window
{
private:
    int left, top, right, bottom;
    string title;

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
        setfillcolor(BLUE);
        setbkcolor_f(BLUE);
        bar(left, 0, right, 24);
        setcolor(WHITE);
        outtextxy(0, 0, title.c_str());
        setfillcolor(LIGHTGRAY);
        bar(left, 24, 36, bottom);
    }
};

class Button
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

class MyCircle
{
private:
    int x;
    int y;
    int r;

public:
    MyCircle()
    {
        x = 0;
        y = 0;
        r = 0;
    }

    void set(int xx, int yy, int rr)
    {
        x = xx;
        y = yy;
        r = rr;
    }

    void set(int rr)
    {
        r = rr;
    }

    int getx() const
    {
        return x;
    }

    int gety() const
    {
        return y;
    }

    void draw()
    {
        circle(x, y, r);
    }
};

int main()
{
	MyCircle r;
	bool bDraw = false;	// 绘图标志，按下鼠标左键设置为true，抬起鼠标左键或在绘图过程中按鼠标右键设置为false

	initgraph(800, 600, INIT_RENDERMANUAL);

    window w(0, 0, 800, 600, "mywindows");
    w.show();

	setbkcolor_f(WHITE);

	//setfillcolor(WHITE);
	//bar(0, 0, 800, 600);

	int x = 2, y = 32;
	Button b1(x, y, x + 32, y + 32, "1.png");
	b1.show();

	y += 33;
	Button b2(x, y, x + 32, y + 32, "2.png");
	b2.show();

	y += 33;
	Button b3(x, y, x + 32, y + 32, "3.png");
	b3.show();

	setfont(16, 0, "宋体");
	setcolor(0x00FF0000);
    mouse_msg msg = {0};
	for ( ; is_run(); delay_fps(60))	// 消息循环
	{
		//获取鼠标消息，这个函数会等待，等待到有消息为止
		//类似地，有和kbhit功能相近的函数MouseHit，用于检测有没有鼠标消息
   		while (mousemsg())
		{
			msg = getmouse();
		}

		if (msg.is_down())						// 有鼠标键按下
        {
            if (msg.is_left())					// 是鼠标左键
            {
                setwritemode(R2_XORPEN);		// 设置XOR模式
                r.set(msg.x, msg.y, 0);
                r.draw();
                bDraw = true;					// 开始跟踪鼠标画图
            }
            else if (msg.is_right())			// 是鼠标右键
            {
                if (bDraw)
                {
                    r.draw();					// 清除图形
                    setwritemode(R2_COPYPEN);	// 设置copy模式
                    bDraw = false;
                }
            }
        }
        else if (msg.is_move())					// 移动鼠标
        {
            if (bDraw)
            {
                r.draw();						// 清除之前绘制的图形
                int dx = r.getx() - msg.x;
                int dy = r.gety() - msg.y;
                int rr = (int)sqrt(dx * dx + dy * dy);	// 计算半径
                r.set(rr);
                r.draw();						// 修改坐标后绘制新图形
            }
        }
        else if (msg.is_up())					// 抬起鼠标按键
        {
            if (bDraw)
            {
                setwritemode(R2_COPYPEN);		// 用copy模式重新绘制图形
                int dx = r.getx() - msg.x;
                int dy = r.gety() - msg.y;
                int rr = (int)sqrt(dx * dx + dy * dy);
                r.set(rr);
                r.draw();						// 最后绘制固定图形
                bDraw = false;
            }
        }

		//xyprintf(0, 0, "x=%4d y=%4d", msg.x, msg.y);	// 实时显示鼠标坐标

	}
	closegraph();
	return 0;
}
