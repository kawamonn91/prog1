#include<stdio.h>
#include<stdlib.h>
char score2Grade(int);
int main(int argc,char *argv[])
{
    int score;
    char grade;

    for(int i=1;i<argc;i++)
    {
        score=atoi(argv[i]);
        grade=score2Grade(score);
        printf("評点:%3d 評価:%c\n",score,grade);
    }

    return 0;
}

char score2Grade(int score)
{
  if(score>=0&&score<=34) return 'F';
  if(score>=35&&score<=49) return 'D';
  if(score>=50&&score<=64) return 'C';
  if(score>=65&&score<=79) return 'B';
  if(score>=80&&score<=100) return 'A';
  return 'F';
}