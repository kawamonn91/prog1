typedef struct
{
    double x;
    double y;
}XY;

typedef struct 
{
    XY center;
    double radius;
    double length;
    double area;
}CIRCLE;

#include<stdio.h>
#include<math.h>
CIRCLE inputCircle(void);
void inputCirclePtr(CIRCLE*);
void printCircleInfo(CIRCLE);

int main()
{
    CIRCLE circle1,circle2;

    printf("構造体を返す関数(inputCircle):\n");
    circle1=inputCircle();
    printCircleInfo(circle1);

    printf("構造体ポインタを返す関数(inputCirclePtr):\n");
    inputCirclePtr(&circle2);
    printCircleInfo(circle2);
    
    return 0;
}

CIRCLE inputCircle(void)
{
    CIRCLE circle;
    XY point;
    printf("円の中心点の座標と円周上の1点の座標を入力:\n");
    scanf("%lf %lf %lf %lf",&circle.center.x,&circle.center.y,&point.x,&point.y);
    circle.radius=sqrt((pow(point.x-circle.center.x,2))+pow(point.y-circle.center.y,2));
    circle.length=2*circle.radius*M_PI;
    circle.area=pow(circle.radius,2)*M_PI;
    return circle;
}

void inputCirclePtr(CIRCLE *circle)
{
    XY point;
    scanf("%lf %lf %lf %lf",&circle->center.x,&circle->center.y,&point.x,&point.y);
    circle->radius=sqrt((pow(circle->center.x-point.x,2))+pow(circle->center.y-point.y,2));
    circle->length=2*circle->radius*M_PI;
    circle->area=pow(circle->radius,2)*M_PI;
}

void printCircleInfo(CIRCLE circle)
{
    printf("Center,Radius:(%.6f,%.6f),%.6f\n",circle.center.x,circle.center.y,circle.radius);
    printf("Length,Area:%.6f,%.6f\n",circle.length,circle.area);
}