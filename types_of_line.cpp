#include<graphics.h>

#include<iostream>

#include<stdlib.h>

#include<math.h>

using namespace std;



class dline   //base class

{

    private: int x1,y1,x2,y2,xo,yo,style;



    public:

    dline()

    {

        x1=0;

        y1=0;

        x2=0;

        y2=0;

        xo=0;

        yo=0;



    }

    void setoff(int x,int y)

    {

        xo=x;

        yo=y;

    }

    void setstyle(int s)

    {

        style=s;

    }

 

    void drawl(int x1, int y1, int x2, int y2)

{    



float x, y, dx, dy,length;

int i, flag=0;

    dx=abs(x2-x1);

        dy=abs(y2-y1);

     

        if(dx >= dy)

        {

            length=dx;

        }

        else

        {

            length=dy;

        }



        dx=(x2-x1)/length;

        dy=(y2-y1)/length;



        x = x1 + 0.5;

        y = y1 + 0.5;     



        i=1;

        while(i<=length)

        {

            

switch(style)

{

case 1: putpixel(x+xo,yo-y,15);



         break;

case 2:

if (flag==0)

{

putpixel(x+xo, yo-y, 15);

}



if(i%2==0)

{

if(flag==1)

{

flag=0;

}

else

{

flag=1;

}

}

break;

case 3 : if (flag==0)

{

putpixel(x+xo, yo-y, 15);

}

if(i%5==0)

{

if(flag==1)

{

flag=0;

}

else

{

flag=1;

}

}

break;

case 4:



 if (flag==0)

{

putpixel(x+xo, yo-y, 15);

}



if(i%3==0)

{

putpixel(x+xo, yo-y, 15);

}

if(i%5==0)

{

if(flag==1)

{

flag=0;

}

else

{

flag=1;

}

}

break;

case 5 :

putpixel(x+xo, yo-y, 15);

break;

}

x=x+dx;

y=y+dy;

i=i+1;

}

putpixel(x+xo,yo-y,15);

}

};



 int main()

{

    int gd=DETECT,gm;

    int i,st,x1,y1,x2,y2,xmax,ymax,xmid,ymid

,wx,wy,thickness;

    dline l;

   cout<<"\n enter the two endpoints of line:";



   cout<<"\n Enter x1: "; cin>>x1;

    cout<<"\n Enter y1: "; cin>>y1;

    cout<<"\n Enter x2: "; cin>>x2;

    cout<<"\n Enter y2: "; cin>>y2;      



    cout<<"\nEnter Line Styles";

 cout<<"\n1.SIMPLE..";

 cout<<"\n2.DOTTED..";

cout<<"\n3.DASH..";

cout<<"\n4.DASH DOT..";

 cout<<"\n5.THICK..";

  cout<<"\nEnter your choice: ";

   cin>>st;



if(st==5)

     

    cout<<"\nEnter Thickness: ";

    cin>>thickness;



initgraph(&gd,&gm,NULL);

xmax=getmaxx();

ymax=getmaxy();

xmid=xmax/2;

ymid=ymax/2;

setcolor(15);

l.setoff(xmid,ymid);

l.setstyle(st);

line(xmid,0,xmid,ymax);

line(0,ymid,xmax,ymid);



if(st<=4)

{

l.drawl(x1,y1,x2,y2);

}

else

{

l.drawl(x1,y1,x2,y2);

if((y2-y1)/(x2-x1)<1)

{



        wy=(thickness-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(x2-x1));

            for(i=0;i<wy;i++)

            {

                l.drawl(x1,y1-i,x2,y2-i);

                l.drawl(x1,y1+i,x2,y2+i);

            }

        }

        else

        {

            wx=(thickness-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(y2-y1));

            for(i=0;i<wx;i++)

            {

                l.drawl(x1-i,y1,x2-i,y2);

                l.drawl(x1+i,y1,x2+i,y2);

            }

 }

}



    getch();

    closegraph();

    return 0;

   }
