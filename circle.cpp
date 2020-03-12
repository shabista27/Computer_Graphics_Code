#include<iostream>

#include<stdio.h>

# include <graphics.h>

# include <stdlib.h>

#include<math.h>


using namespace std;

class pixel

{

protected : int x, y;

int x1;

int y1;

int r;

public:

void accept();

};

void pixel::accept()

{

cout<<"Enter the starting coordinates or centre coordinates "<<endl;

cin>>x;

cin>>y;

cout<<"enter the radius of the circle"<<endl;

cin>>r;

}

class draw : public pixel

{

private :

void bresen();

void display (int x1, int y1, int x, int y);

public:

void normal_call();
};

void draw::bresen()
{
int d;
x1=0;
y1=r;
putpixel(x1, y1, 3);
d= 3- (2*r);
while( x1<=y1)
{


if ( d<=0)
{
d= d+ ( 4*x1)+6;
}
else
{
d = d+4*(x1-y1) +10;
y1--;
}
x1 ++;
display( x1,y1,x,y);
}
}
void draw :: display( int x1, int y1, int x, int y)
{

putpixel(x1+x, y1+y, 3);

putpixel(x-x1, y1+y, 3);

putpixel(x1+x, y-y1,15);

putpixel(x-x1,y-y1,3);

putpixel(x+y1,y+x1,15);

putpixel(x-y1, y+x1,3);

putpixel(x+y1, y-x1, 3);

putpixel(x-y1, y-x1, 3);
}
void draw :: normal_call()
{
char ch;
accept();
int gd= DETECT, gm;
initgraph(&gd,&gm,NULL);
bresen();
getch();
closegraph();
restorecrtmode();
cout<<"want to draw another(y/n)"<<endl;
cin>>ch;

if(ch=='y')
normal_call();
else
exit(0);
}
int main()
{
draw d;
d.normal_call();
return 0;
}
