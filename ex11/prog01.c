#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

Point rotate1(double,Point,Point);
void rotate2(double,Point *,Point *);

int main()
{
    double rad,deg;
    Point c={1.0,1.0},a={2.0,3.0};//中心と回転対象の点
    Point b1,b2;//結果を入れる構造体

    printf("回転角[度]を入力して下さい\n");
    scanf("%lf",&deg);
    rad=deg*M_PI/180;
    printf("回転角%f[deg](%f[rad]\n)",deg,rad);

    //回転後の点b1を求める
    b1=rotate1(rad,a,c);
    //回転後の点b2を求める
    b2=a;
    rotate2(rad,&b2,&c);

    printf("Center : %f %f\n",c.x,c.y);
    printf("Point A : %f %f\n",a.x,a.y);
    printf("Point B (rotate1) : %f %f\n",b1.x,b1.y);
    printf("Point B (rotate2) : %f %f\n",b2.x,b2.y);
    return 0;
}

Point rotate1(double rad,Point a,Point c)
{
    Point b;
    b.x=cos(rad)*(a.x-c.x)-sin(rad)*(a.y-c.y)+c.x;
    b.y=sin(rad)*(a.x-c.x)+cos(rad)*(a.y-c.y)+c.y;
    return b;
}

void rotate2(double rad,Point *b2,Point *c)
{
    double x,y;
    x=cos(rad)*(b2->x-c->x)-sin(rad)*(b2->y-c->y)+c->x;
    y=sin(rad)*(b2->x-c->x)+cos(rad)*(b2->y-c->y)+c->y;
    b2->x=x;
    b2->y=y;
}