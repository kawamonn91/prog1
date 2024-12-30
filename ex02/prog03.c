#define MAX_ST_NUM 50                   /* 学生数の最大値 */
#define MAX_SCORE 120                   /* 120点満点 */
int student_id[MAX_ST_NUM];             /* 学籍番号  */
int abs_score[MAX_ST_NUM];              /* 点数 (補正前) */
char abs_grade[MAX_ST_NUM];             /* 補正前の評価 (A - F) */
int rel_score[MAX_ST_NUM];              /* 点数 (補正後) */
char rel_grade[MAX_ST_NUM];             /* 補正後の評価 (A - F) */
int grade_dist[2][5];                   /* 評価の分布 [0]:補正前, [1] 補正後 */
                                        /* 例 grade_dist[0][0] 補正前の Fの人数 */
char cgrade[5]={'F','D','C','B','A'};   /* 評価（A - F） */
int num_student;                        /* 実際に成績を読み込んだ学生の数 */
double abs_ave=0.0;                     /* 平均点（補正前） */
double rel_ave=0.0;                     /* 平均点（補正後） */

int calib(int); /* 満点の補正を行う。内部では実数で計算し、小数点第１位で四捨五入した整数を返す */
int grade(int);//成績を計算する関数


#include<stdio.h>
int main()
{
    //二次元配列の初期化
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<5;j++)
        {
            grade_dist[i][j]=0;
        }
    }


    //成績の計算と補正
    for(int i=0;i<MAX_ST_NUM;i++)
    {
        //データの読み込み
        scanf("%d %d",&student_id[i],&abs_score[i]);
        if(student_id[i]==0) break;

        //補正前の成績の計算
        abs_grade[i]=cgrade[grade(abs_score[i])];

        //点数の補正
        rel_score[i]=calib(abs_score[i]);
        //補正後の成績の計算
        rel_grade[i]=cgrade[grade(rel_score[i])];

        //二次元配列に補正前の成績の分布を格納
        switch(grade(abs_score[i]))
        {
            case 4:
            grade_dist[0][0]=grade_dist[0][0]+1;
            break;

            case 3:
            grade_dist[0][1]=grade_dist[0][1]+1;
            break;

            case 2:
            grade_dist[0][2]=grade_dist[0][2]+1;
            break;

            case 1:
            grade_dist[0][3]=grade_dist[0][3]+1;
            break;

            case 0:
            grade_dist[0][4]=grade_dist[0][4]+1;
            break;

            default:
            printf("error\n");

        }

        //二次元配列に補正後の正世辞を格納
        switch(grade(rel_score[i]))
        {
            case 4:
            grade_dist[1][0]=grade_dist[1][0]+1;
            break;

            case 3:
            grade_dist[1][1]=grade_dist[1][1]+1;
            break;

            case 2:
            grade_dist[1][2]=grade_dist[1][2]+1;
            break;

            case 1:
            grade_dist[1][3]=grade_dist[1][3]+1;
            break;

            case 0:
            grade_dist[1][4]=grade_dist[1][4]+1;
            break;

            default:
            printf("error\n");

        }
        //生徒数を加算
        num_student=i+1;
    }

    //平均点の計算
    for(int i=0;i<num_student;i++)
    {
        abs_ave=abs_ave+abs_score[i];
        rel_ave=rel_ave+rel_score[i];
    }
    abs_ave=(100*abs_ave/num_student+5)/100;
    rel_ave=(100*rel_ave/num_student+5)/100;

    //補正前と補正後の成績を表示
    printf("ID 点数 評価 点数 評価\n");
    printf("   (補正前)(補正後)\n");
    printf("----------------------\n");

    for(int i=0;i<num_student;i++)
    {
        printf("%d  \t%d \t%c  \t%d \t%c\n",student_id[i],abs_score[i],abs_grade[i],rel_score[i],rel_grade[i]);
    }
    printf("----------------------\n");

    //統計の表示
    printf("統計\n学生数 %d人 補正前平均点%.1f点 補正後平均点 %.1f点\n",num_student,abs_ave,rel_ave);

    //評価分布の表示
    printf("補正前 ");
    for(int i=0;i<5;i++)
    {
        printf("%c %d",cgrade[4-i],grade_dist[0][i]);
        if(i!=4) printf(" ");
    }
    printf("\n");
    printf("補正後 ");
    for(int i=0;i<5;i++)
    {
        printf("%c %d",cgrade[4-i],grade_dist[1][i]);
        if(i!=4) printf(" ");
    }
    printf("\n");

    return 0;
}

//補正処理を行う関数
int calib(int before)
{
    int after;
    after=0;
    after=100*(before*10)/120+5;
    after=after/10;
    return after;
}

//成績評価を行う関数
int grade(int score)
{
    if(score>=80) return 4;
    if(score>=65&&score<=79) return 3;
    if(score>=50&&score<=64) return 2;
    if(score>=35&&score<=49) return 1;
    if(score>=0&&score<=34) return 0;
}
