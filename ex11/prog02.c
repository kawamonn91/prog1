#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

Point rotate3(double,Point *);
void rotate4(double,Point *);

int main()
{
    double rad,deg;
    Point point1[2]={{1.0,1.0},{2.0,3.0}};//中心と回転対象の点
    Point point2[3]={{1.0,1.0},{2.0,3.0},{0,0}};//中心と回転対象の点と結果
    Point b3;//結果を入れる構造体

    printf("回転角[度]を入力して下さい\n");
    scanf("%lf",&deg);
    rad=deg*M_PI/180;
    printf("回転角%f[deg](%f[rad]\n)",deg,rad);

    b3=rotate3(rad,point1);
    rotate4(rad,point2);

    printf("Center : %f %f\n",point1[0].x,point1[0].y);
    printf("Point A : %f %f\n",point1[1].x,point1[1].y);
    printf("Point B (rotate3) : %f %f\n",b3.x,b3.y);
    printf("Point B (rotate4) : %f %f\n",point2[2].x,point2[2].y);
    return 0;
}

Point rotate3(double rad,Point *point)
{
    Point b;
    b.x=cos(rad)*(point[1].x-point[0].x)-sin(rad)*(point[1].y-point[0].y)+point[0].x;
    b.y=sin(rad)*(point[1].x-point[0].x)+cos(rad)*(point[1].y-point[0].y)+point[0].y;
    return b;
}

void rotate4(double rad,Point *point)
{
    point[2].x=cos(rad)*(point[1].x-point[0].x)-sin(rad)*(point[1].y-point[0].y)+point[0].x;
    point[2].y=sin(rad)*(point[1].x-point[0].x)+cos(rad)*(point[1].y-point[0].y)+point[0].y;
}