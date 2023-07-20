#include<graphics.h>

class Car{
    double car_position_x;
    double car_position_y;
    double car_gunpoint_x;
    double car_gunpoint_y;
public:
    Car(double car_position_x, double car_position_y)
    {
        this->car_position_x = car_position_x;
        this->car_position_y = car_position_y;

    }
    void set_position(double car_position_x, double car_position_y)
    {
        this->car_position_x = car_position_x;
        this->car_position_y = car_position_y;
    }
    double get_position_x()
    {
        return this->car_position_x;
    }
    double get_position_y()
    {
        return this->car_position_y;
    }
    double get_position_front_x()
    {
        return  this->car_position_x+230;
    }
    void show()
    {
        line(car_position_x,car_position_y,car_position_x+30,car_position_y);
        line(car_position_x,car_position_y,car_position_x,car_position_y+30);
        line(car_position_x+30,car_position_y,car_position_x+60,car_position_y-25);
        line(car_position_x+60,car_position_y-25,car_position_x+150,car_position_y-25);
        line(car_position_x+150,car_position_y-25,car_position_x+200,car_position_y);
        line(car_position_x+105,car_position_y-25,car_position_x+105,car_position_y+30);

        line(car_position_x+200,car_position_y,car_position_x+30,car_position_y);

        line(car_position_x+200,car_position_y,car_position_x+230,car_position_y);
        line(car_position_x+230,car_position_y,car_position_x+230,car_position_y+30);
        line(car_position_x+230,car_position_y+30,car_position_x+200,car_position_y+30);

        //tire fenderrs
        arc(car_position_x+180,car_position_y+30,0,180,20);
        circle(car_position_x+180,car_position_y+30,15);
        line(car_position_x+160,car_position_y+30,car_position_x+70,car_position_y+30);
        arc(car_position_x+50,car_position_y+30,0,180,20);
        circle(car_position_x+50,car_position_y+30,15);
        line(car_position_x+30,car_position_y+30,car_position_x,car_position_y+30);
    }
    void setColor(int door_color=RED,int window_color=YELLOW,int tire_color=BLACK)
    {
        setfillstyle(XHATCH_FILL,window_color);
        floodfill(car_position_x+70,car_position_y-20,WHITE);
        floodfill(car_position_x+115,car_position_y-20,WHITE);
        setfillstyle(SOLID_FILL,door_color);
        floodfill(car_position_x+3,car_position_y+3,WHITE);
        floodfill(car_position_x+150,car_position_y+25,WHITE);
        setfillstyle(SOLID_FILL,tire_color);
        floodfill(car_position_x+180,car_position_y+30,WHITE);
        floodfill(car_position_x+50,car_position_y+30,WHITE);


    }
    void addGun()
    {

        line(car_position_x+105,car_position_y-25,car_position_x+105,car_position_y-72);
        line(car_position_x+115,car_position_y-25,car_position_x+115,car_position_y-70);
        line(car_position_x+100,car_position_y-72,car_position_x+120,car_position_y-70);
        line(car_position_x+100,car_position_y-72,car_position_x+100,car_position_y-80);
        line(car_position_x+100,car_position_y-80,car_position_x+120,car_position_y-78);
        line(car_position_x+120,car_position_y-78,car_position_x+120,car_position_y-70);
        arc(car_position_x+120,car_position_y-74,90,270,4);
        this->car_gunpoint_x =car_position_x+120;
        this->car_gunpoint_y = car_position_y-74;

        setfillstyle(SOLID_FILL,YELLOW);
        floodfill(car_position_x+120,car_position_y-73,WHITE);

        setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(car_position_x+106,car_position_y-70,WHITE);
        setfillstyle(SOLID_FILL,DARKGRAY);
        floodfill(car_position_x+110,car_position_y-77,WHITE);


    }
    double get_gunpoint_x()
    {
        return this->car_gunpoint_x;
    }
    double get_gunpoint_y()
    {
        return this->car_gunpoint_y;
    }
    void addBullet()
    {
        line(car_gunpoint_x,car_gunpoint_y,car_gunpoint_x+800,car_position_y+43);

    }
    double getBullet_position_x()
    {
        return car_gunpoint_x+800;
    }
    double getBullet_position_y()
    {
        return car_gunpoint_y+43;
    }
    double get_max_y()
    {
        return car_position_y-25;
    }

};

