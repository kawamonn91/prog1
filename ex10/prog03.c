#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"studlist10.h"
int main()
{
    Record r;
    int i;
    char id[6];
    FILE *fpin;
    
    //リストの初期化
    head=make_1node(r,NULL);

    //listprint();
    //ファイルを読み出し指定で開き、エラー処理
    if((fpin=fopen("Student.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open:Student.txt(1)\n");
        exit(1);
    }

    //ファイルの読み込み
    while(fscanf(fpin,"%d %s %s %d",&r.id,r.surname,r.givenname,&r.age)==4)
    {
        insert(r);
    }
    fclose(fpin);
    printf("\n");

    listprint();
    //新しいノードをリストに追加する
    //ctl+dでループを抜ける
    while(1)
    {
        printf("Input match data(ID)->");
        if(scanf("%s",id)!=1) break;
        listprint_sel(id);
    }
    printf("\n");

    NodePointer current = head;
    NodePointer next;
    while (current != NULL) 
    { 
        next = current->next;
        free(current);
        current = next;
    }
    return 0;
}

NodePointer insert(Record r)
{
    NodePointer newnode,tail;

    if(finditem(r.id)==NULL)
    {
        //重複するノードの検索
        newnode=make_1node(r,NULL);//headの下に新しいノードを作成
        if(head->next==NULL)
        {
            head->next=newnode;
        }
        else
        {
            tail=head->next;
            while(tail->next!=NULL)
            {
                tail=tail->next;
            }
            tail->next=newnode;
        }
        return newnode;
    }

    else
    {
        return NULL;
    }
}

void listprint(void)
{
    NodePointer n;
    int count=0;
    printf("Head-\n");
    for(n=head->next;n!=NULL;n=n->next)//headの次のノードから NULLの前まで辿る
    {
        printf("%7d %-12s %-12s %d\n",n->data.id,n->data.surname,n->data.givenname,n->data.age);
        count++;
    }
    printf("\n");
    printf("%d nodes exist in the list\n",count);
}

NodePointer finditem(int sid)
{
    NodePointer n;
    for(n=head;n->next!=NULL;n=n->next)//headからNULLの一つ前までのノードを辿る
    {
        if(n->next->data.id==sid) return n;//sidと同じ値が見つかったら一つ手前のノードを指すポインタを返す
    }
    return NULL;
}

NodePointer make_1node(Record r,NodePointer p)
{
    NodePointer n;
    if((n=(NodePointer)malloc(sizeof(struct node)))==NULL)//メモリ確保
    {
        printf("Error in memory allocation\n");
        exit(8);
    }

    //dataとnextに引数の値をセットする
    n->data=r;
    n->next=p;

    return n;
}

void listprint_sel(char *p)
{
    Record r;
    char str_file[20];
    int l,result;

    l=strlen(p);
    FILE *fpin;
    if((fpin=fopen("Student.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open:Student.txt(2)\n");
    }
    
    while(fscanf(fpin,"%d %s %s %d",&r.id,r.surname,r.givenname,&r.age)==4)
    {

        sprintf(str_file,"%d",r.id);
        result=strncmp(p,str_file,l);
        if(result==0)
        {
            printf("%7d %-12s %-12s %d\n",r.id,r.surname,r.givenname,r.age);
        }
    }
    fclose(fpin);
    printf("\n");
}
