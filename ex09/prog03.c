#include<stdio.h>
#include<stdlib.h>
#include"studlist03.h"
int main()
{
    Record r;
    int i,ID;
    FILE *fpin;
    
    //リストの初期化
    head=make_1node(r,NULL);

    //listprint();
    //ファイルを読み出し指定で開き、エラー処理
    if((fpin=fopen("Student.txt","r"))==NULL)
    {
        fprintf(stderr,"Failed to open:Student.txt\n");
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
        printf("Choose operation (1:Insert,0:Delate,^D:Finish)->\n");
        if(scanf("%d",&i)!=1) break;
        if(i==1)
        {
            printf("Insert new student data:(ID Surname Givenname Age)->");
            if(scanf("%d %s %s %d",&r.id,r.surname,r.givenname,&r.age)!=4);
            {
                printf("\n");
                break;
                if(insert(r)==NULL)
                    {
                        printf("ID %d is already on the list!\n",r.id);
                    }
                else listprint();
            }
        }

        else if(i==0)
        {
            printf("Delate ID->");
            scanf("%d",&ID);
            if(delate(ID)==NULL)
            {
                printf("ID %dis not found\n",ID);
            }
            listprint();
        
        }
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

NodePointer delate(int ID)
{
    NodePointer n,delnode;
    if((n=finditem(ID))==NULL) return NULL;
    else
    {
        delnode=n->next;
        n->next=delnode->next;
        return n;
    }

}