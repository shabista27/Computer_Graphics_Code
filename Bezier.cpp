 #include<iostream>

# include<graphics.h>

#include<termios.h>



using namespace std;



int maxx, maxy;



float xxx[1][2] = {0.0, 0.0};

void line1(float, float);

void bezier(float, float, float, float, float, float, int);



int main()

{

int gd= DETECT, gm;

initgraph(&gd, &gm, NULL);

maxx = getmaxx();

maxy = getmaxy();

xxx[0][0] = 0.5;

xxx[0][1] = 0.5;



setcolor(12);



bezier(0.15,0.5,0.25,0.2,0.5,0.5,8);

floodfill(0.45*maxx, 0.45*maxy, 12);

xxx[0][0]= 0.5;

xxx[0][1] = 0.5;

setcolor(12);



bezier(0.35,0.3,0.6,0,0.5,0.5,4);

floodfill(0.5*maxx, 0.45*maxy, 12);

xxx[0][0]= 0.5;

xxx[0][1] = 0.5;

setcolor(12);



bezier(0.90,0.45,0.64,0.2,0.5,0.5,4);

floodfill(0.55*maxx, 0.45*maxy, 12);

xxx[0][0]= 0.5;

xxx[0][1] = 0.5;

setcolor(12);



bezier(0.15,0.6,0.25,0.87,0.5,0.5,4);

floodfill(0.45*maxx, 0.55*maxy, 12);

xxx[0][0]= 0.5;

xxx[0][1] = 0.5;

setcolor(12);



bezier(0.85,0.75,0.57,0.8,0.5,0.5,4);

floodfill(0.55*maxx, 0.45*maxy, 12);

xxx[0][0]= 0.5;

xxx[0][1] = 0.5;

setcolor(12);



bezier(0.5,0.75,0.57,0.8,0.5,1,4);



setcolor(14);

circle(0.5*maxx, 0.5*maxy, 10);

floodfill(0.5*maxx, 0.5*maxy, 14);

xxx[0][0]= 0.534;

xxx[0][1] = 0.9;

setcolor(12);



bezier(0.85,0.75,0.57,0.78,0.534,0.9,4);

floodfill(0.60*maxx, 0.85*maxy, 2);

delay(3000);

getch();

closegraph();

return 0;

}

void line1(float x2, float y2)

{

int d1, d2, d3, d4;

d1 = maxx*xxx[0][0];

d2 = maxy*xxx[0][1];

d3 = maxx*x2;

d4 = maxy*y2;



line(d1, d2, d3,d4);

xxx[0][0] = x2;

xxx[0][1] = y2;



}



void bezier(float xb, float yb, float xc, float yc, float xd, float yd, int n)

{

float xab, yab, xbc, ybc, xcd, ycd;

float xabc, yabc, xbcd, ybcd;

float xabcd, yabcd;



if(n==0)

{

line1(xb, yb);

line1(xc, yc);

line1(xd, yd);

}

else

{

xab = (xxx[0][0]+xb)/2;

yab = (xxx[0][1]+yb)/2;



xbc = (xb+xc)/2;

ybc = (yb+yc)/2;

xcd = (xc+xd)/2;

ycd = (yc+yd)/2;

xabc = (xab+xbc)/2;

yabc = (yab+ybc)/2;

xbcd = (xbc+xcd)/2;

ybcd = (ybc+ycd)/2;

xabcd = (xabc+xbcd)/2;

yabcd = (yabc+ybcd)/2;

n =n-1;

bezier(xab,  yab,  xabc,  yabc,  xbcd,  ybcd, n);

bezier(xbcd,  ybcd,  xcd,  ycd,  xd,  yd, n);

}

}
