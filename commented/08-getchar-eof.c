#include <stdio.h>

/* 题目：怎么把输入原样吐出来，直到输入结束？
 * 输入：任意文本（Windows 下按 Ctrl+Z 再回车表示 EOF）
 * 输出：原样回显，最后打印 EOF
 *
 * 注意 ch 必须是 int 而不是 char：EOF 通常是 -1，
 * 用 char 接会与 0xFF 混淆，循环就停不下来。 */

int main(void)
{
    int ch;

    /* 连写：先赋值再比较，比 while(1){ch = getchar(); if (ch == EOF) break;} 短 */
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    printf("EOF\n");

    return 0;
}
