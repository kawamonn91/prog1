#include<stdio.h>
#include<string.h>
#define NWORD 7
int main()
{
    char input[NWORD][20],newstr[120]="",*p=newstr;
    int len=0;
    printf("Input %d words\n",NWORD);
    //単語の入力
    for(int i=0;i<NWORD;i++)
    {
        scanf("%s",input[i]);
    } 
    //newstrの作成
    for(int i=0;i<NWORD;i++)
    {
        strcpy(p,input[i]);
        //ポインタの移動
        p+=strlen(input[i]);
        //スペースの追加
        if(i<NWORD-1) 
        {
            *p=' ';
            p++;
        }
        //null文字の追加
        if(i==NWORD-1) 
        {
            *p='\0';
        }
    }
    //newstrの出力
    printf("%s\n",newstr);
    //文字数の出力
    len=strlen(newstr);
    printf("Total: %d characters\n",len);
    
    return 0;
}