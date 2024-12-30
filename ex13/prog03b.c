#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'

char **img_alloc(int, int);
void img_free(char **, int, int);
char **img_read(int *x, int *y);
void img_write(char **, int, int);
void img_square(char **, int, int, int, int, int);
void img_xdot(char **, int, int, int, int);

int main(int argc, char *argv[]) {
    char **pbm;
    int x, y;      /* 画像の幅と高さ */
    int i;
    int cx, cy, d; /* 正方形の中心座標と辺の長さ */

    /* 正方形の中心座標と辺の長さをコマンドライン引数から取得 */
    if (argc < 4) {
        fprintf(stderr, "usage: ./a.out cx cy d <pbmfile\n");
        exit(4);
    }
    cx = atoi(argv[1]);
    cy = atoi(argv[2]);
    d = atoi(argv[3]);

    /* 画像データを標準入力から読み込む */
    pbm = img_read(&x, &y);

    /* 正方形を書き込む */
    img_square(pbm, x, y, cx, cy, d);

    /* 画像データを書き出す */
    img_write(pbm, x, y);
    /* 画像データを解放する */
    img_free(pbm, x, y);
    return 0;
}

/********************************************/
/* 画像データを動的に確保する               */
/* x, y: 画像の幅と高さ                     */
/********************************************/
char **img_alloc(int x, int y) {
    char **data;
    /* メモリ確保のコードをここに記述 */
    data=(char **)malloc(y * sizeof(int *));
    for(int i=0;i<y;i++)
    {
        data[i]=(char *)malloc(x * sizeof(int *));
    }

    return data;
}

/********************************************/
/* 画像データを解放する                     */
/* pbm: 画像データのポインタ                */
/* x, y: 画像の幅と高さ                     */
/********************************************/
void img_free(char **pbm, int x, int y) {
    int i;
    for (i = 0; i < y; i++) free(pbm[i]);
    free(pbm);
}

/********************************************/
/* 画像データを出力する                     */
/* pbm, x, y: 画像データのポインタと幅、高さ */
/********************************************/
void img_write(char **pbm, int x, int y) {
    int i, j;
    /* 画像のヘッダを出力 */
    printf("P1\n");
    printf("%d %d\n", x, y);
    /* 画像データを出力 */
    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            printf("%c ", pbm[i][j]);
        }
        printf("\n");
    }
}

/********************************************/
/* 画像データを読み込む                     */
/* x, y: 画像の幅と高さ                     */
/********************************************/
char **img_read(int *x, int *y) {
    char **data;
    /* データ読み込みのコードをここに記述 */
    if (getchar() != 'P' || getchar() != '1')
    {
         fprintf(stderr, "ファイルフォーマットが違います。\n");
    }
    scanf("%d %d",x,y);
    data=img_alloc(*x,*y);
    for(int i=0;i<*y;i++)
    {
        for(int j=0;j<*x;j++)
        {
            if(scanf(" %c",&data[i][j])!=1)
            {
                img_free(data,*x,*y);
                return NULL;
            }
            if(data[i][j]!=WHITE&&data[i][j]!=BLACK)
            {
                img_free(data,*x,*y);
                return NULL;
            }
        }
    }


    return data;
}

/********************************************/
/* 画像に正方形を描く                       */
/* pbm, x, y: 画像データのポインタと幅、高さ */
/* cx, cy: 正方形の中心座標                 */
/* d: 正方形の辺の長さ                      */
/********************************************/
void img_square(char **pbm, int x, int y, int cx, int cy, int d) {
    /* 正方形を描画するコードをここに記述 */
    /* 点を描画する際には img_xdot を呼び出す */
    for(int  i=cy-d;i<=cy+d;i++)
    {
        for(int j=cx-d;j<=cx+d;j++)
        {
            img_xdot(pbm,x,y,j,i);
        }
    }
}

/********************************************/
/* 画像に点を描く                           */
/* pbm, x, y: 画像データのポインタと幅、高さ */
/* px, py: 描画する点の座標                 */
/********************************************/
void img_xdot(char **pbm, int x, int y, int px, int py) {
    /* 点を描画するコードをここに記述 */
    if(px>=0&&px<x&&py>=0&&py<y)
    {
        if(pbm[py][px]==WHITE) pbm[py][px]=BLACK;
        else if(pbm[py][px]==BLACK) pbm[py][px]=WHITE;
    }

}