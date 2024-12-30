#include <stdio.h>

#define JAPANESE 1

int main()
{
    int i, n, sum = 0;

#if JAPANESE
    printf("奇数を入力してください: ");
#else
    printf("Please input an odd number: ");
#endif

    scanf("%d", &n); /* 入力を受け取る */

    for (i = 1; i <= n; i += 2) { /* 奇数の合計を計算 */
        sum += i;

#ifdef DEBUG
        printf("i = %d, sum = %d\n", i, sum);
#endif
    }

    /* 結果の表示 */
#if JAPANESE
    printf("1 から %d までの奇数の合計 = %d\n", n, sum);
#else
    printf("Sum of odd numbers from 1 to %d = %d\n", n, sum);
#endif

    return 0;
}
