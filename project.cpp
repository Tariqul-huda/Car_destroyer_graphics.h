#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<ctime>
#include"car.h"
using namespace std;
void score_update(int score, char *s)
{
    sprintf(s,"%d",score);
}
int main()
{
    char s[100];
    ofstream fs("score.txt",ios::app);
    int score = 0,page = 0;
    double gun_x,gun_y;
    int delayy=10;
    int color = 0;
    int bullet = 20;

    int x,y;
    x=y=0;
    char ch[100];
    int gd = DETECT,gm;
//    initgraph(&gd,&gm,"");
    int car_position_y;
    int car_position_x;
    //Screen height
    int height = GetSystemMetrics(SM_CYSCREEN);
    int width = GetSystemMetrics(SM_CXSCREEN);
    //setting car position
    car_position_y = height*0.558;
    car_position_x=0;
    initwindow(width,height,"destroyer car");
    setfillstyle(SOLID_FILL,CYAN);
    line(0,height*0.6,width,height*0.6);
    floodfill(3,height*0.5,WHITE);
    setfillstyle(SOLID_FILL,BROWN);
    floodfill(3,height*0.7,WHITE);
    setbkcolor(CYAN);
    settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
    outtextxy(width/2,0,"Score");
    outtextxy(width-500,0,"Laser");
    score_update(score,ch);
    outtextxy(width/2+50,40,ch);
    Car c(car_position_x,car_position_y);
    Car d(car_position_x+width,car_position_y);
    d.setColor();
    d.show();
    c.addGun();
    c.show();
    while(1)
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
        outtextxy(width/2,0,"Score");
          outtextxy(250,0,"Laser");
        score_update(score,ch);
        outtextxy(width/2+50,40,ch);
          score_update(bullet,ch);
        outtextxy(250,40,ch);
        setfillstyle(SOLID_FILL,CYAN);
        line(0,height*0.6,width,height*0.6);
        floodfill(3,height*0.5,WHITE);
        setfillstyle(SOLID_FILL,BROWN);
        floodfill(3,height*0.7,WHITE);
        c.show();
        c.addGun();
        d.show();

        d.setColor(color);

        c.setColor(BLUE);

//            c.set_position(car_position_x+x,car_position_y);
            d.set_position(car_position_x+width-x,car_position_y);
            x+=10;

        if(GetAsyncKeyState(VK_SPACE))
        {
                if(bullet>0)
                {
            c.addBullet();
                gun_x = c.get_gunpoint_x();
                gun_y = c.get_gunpoint_y();
            for(int y=0;y<height*0.3;y++)
            {
                gun_x+=2.4;
                gun_y+=0.4;
                if(gun_x>=d.get_position_x() && gun_x<=d.get_position_front_x())
                {
                    d.set_position(car_position_x+width,car_position_y);
                    score++;
                    x = 0;
                    delay(delayy);
                    delayy = delayy%5+1;
                    color = color%10+rand();
                    bullet+=10;

                }
            }
            bullet--;
            }
        }
        if(c.get_position_front_x()==d.get_position_x())
        {


        break;

                }
        if(GetAsyncKeyState(VK_RETURN))
        {
            break;
        }

        page = 1-page;

    }
    time_t t = time(nullptr);
    strftime(s,sizeof(s),"%A %c",localtime(&t));
    fs<<"------------------------------------------";
    fs<<endl;
    fs<<"Date"<<"\t\t\t\t\t"<<"Score"<<endl;
    fs<<endl;
    fs<<s<<"\t\t"<<score<<endl;
    delay(1000);

    closegraph();
    cout<<"GAME OVER"<<endl;
    cout<<"Press any key to continue......"<<endl;

    _getch();

}
