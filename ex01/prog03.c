#include<stdio.h>
char score2Grade(int score);
int grade2Point(char grade);
int main()
{
  int point,score,credit,totalgpa=0,totalcredit=0;
  double gpa;
  char grade;
  while(1)
    {
      printf("Input score and credit(Ctr+D to stop):");
      if(scanf("%d %d",&score,&credit)!=2) break;
      grade=score2Grade(score);
      point=grade2Point(grade);
      printf("Grade for %d is %c, Grade Point(GP) is %d.(%d credits)\n",score,grade,point,credit);
      totalgpa=totalgpa+point*credit;
      totalcredit=totalcredit+credit;
    }

  gpa=(double)totalgpa/totalcredit;
  printf("Grade Point Average (GPA) is %.4f,(Total credit: %d)\n",gpa,totalcredit);

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

int grade2Point(char grade)
{
  if(grade=='A') return 4;
  if(grade=='B') return 3;
  if(grade=='C') return 2;
  if(grade=='D'||grade=='F') return 0;
  return 0;
}
      
	     
     
