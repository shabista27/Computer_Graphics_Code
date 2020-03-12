#include<iostream>
# include <graphics.h>
# include <stdlib.h>

using namespace std;


class pt
{
protected: int xco, yco,color;
public:
pt()
{
xco=0,yco=0,color=15;
}

void setco(int x, int y)
{
xco=x;
yco=y;
}
void setcolor(int c)
{
color=c;
}
void draw()
{
putpixel(xco,yco,color);
}
};

class dline:public pt
{
private: int x2, y2;
public:
dline():pt()
{
x2=0;
y2=0;
}
void setline(int x, int y, int xx, int yy)
{
pt::setco(x,y);
x2=xx;
y2=yy;
}
void drawl( int colour)
{
float x,y,dx,dy,length;
int i;
pt::setcolor(colour);

dx=  abs(x2-xco);
dy=abs(y2-yco);
if(dx>=dy)
{
length= dx;
}
else
{
length= dy;
}

dx=(x2-xco)/length;
dy=(y2-yco)/length;
x=xco+0.5;
y=yco+0.5;

i=1;
while(i<=length)
{
pt::setco(x,y);
pt::draw();
x=x+dx;
y=y+dy;
i=i+1;
}
pt::setco(x,y);
pt::draw();

}
};


int main()
{
int gd= DETECT, gm;
int x1, x2, y1, y2, xmax, ymax, xmid, ymid, n, i;

pt p1;
p1.setco(100,100);
p1.setcolor(14);

dline l;



initgraph(&gd, &gm, NULL);

xmax= getmaxx();
ymax=getmaxy();
xmid=xmax/2;
ymid=ymax/2;
line(xmid,0,xmid,ymax);
line(0,ymid,xmax,ymid);

l.setline(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
cout<<"enter the total number of lines";
cin>>n;
for(i=0;i<n;i++)
{

cout<<"Enter co-ordinates of point x1:";
cin>>x1;
cout<<"enter coordinates of point y1";
cin>>y1;
cout<<"Enter co-ordinates of point x2: ";
cin>>x2;
cout<<"enter coordinates of point y2";
cin>>y2;
l.setline(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
l.drawl(15);
}

getch();
delay(500);
closegraph();
return 0;
}
