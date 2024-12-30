#include"prog03header.h"
#include<stdio.h>
int read_planets(Planet *planets)
{
    FILE *fp;
    if((fp=fopen("planet.txt","r"))==NULL)
    {
        return -1;
    }

    int i=0;
    while(fscanf(fp,"%s %lf %lf %lf",planets[i].name,&planets[i].radius,&planets[i].density,&planets[i].semi_major_axis)==4)
    {
        i++;
    }

    if(ferror(fp))
    {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}