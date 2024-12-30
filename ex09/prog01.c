#include<stdio.h>
#include<stdlib.h>
#include"studlist.h"
int main()
{
    Record r;
    int i;
    
    //リストの初期化
    head=make_1node(r,NULL);

    listprint();

    //新しいノードをリストに追加する
    //ctl+dでループを抜ける
    while(1)
    {
        printf("Insert new student data:(ID Surname Givenname Age)->");

        if(scanf("%d %s %s %d",&r.id,r.surname,r.givenname,&r.age)!=4)
        {
            printf("\n");
            break;
        }
    

        if(insert(r)==NULL)
        {
            printf("ID %d is already on the list!\n",r.id);
        }
        listprint();
    }
    printf("\n");
    return 0;
}

NodePointer insert(Record r)
{
    NodePointer newnode;

    if(finditem(r.id)==NULL)
    {
        //重複するノードの検索
        newnode=make_1node(r,head->next);//headの下に新しいノードを作成
        head->next=newnode;
        return newnode;
    }

    else return NULL;
}

void listprint(void)
{
    NodePointer n;
    printf("Head-\n");
    for(n=head->next;n!=NULL;n=n->next)//headの次のノードから NULLの前まで辿る
    {
        printf("%7d %-12s %-12s %d\n",n->data.id,n->data.surname,n->data.givenname,n->data.age);
    }
    printf("\n");
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