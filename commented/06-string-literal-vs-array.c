#include <stdio.h>

/* 题目：char *s = "abc" 和 char s[] = "abc" 差在哪？
 * 输入：无
 * 输出：几个地址，以及改第一个字符后两者的不同下场
 *
 * 关键：
 *   char *s     只是把字面量的地址存下来，字面量在只读段 —— 改它崩
 *   char s[]    是把字符一个个抄到栈上的数组 —— 可以随便改
 * 另外两个内容相同的字面量可能指向同一块内存（编译器合并），也可能各自
 * 占一份——C 标准不做承诺，所以 s 与 s2 的地址不该被当成可以依赖的规律。 */

int main(void)
{
    int i = 0;
    char *s = "Hello Word";
    char *s2 = "Hello Word";
    char s3[] = "Hello Word";

    printf("&i=%p\n", (void *)&i);
    printf("s =%p\n", (void *)s);   /* 只读段 */
    printf("s2=%p\n", (void *)s2);  /* 可能与 s 相同，也可能相邻：合不合并随编译器 */
    printf("s3=%p\n", (void *)s3);  /* 栈上，和 &i 很近 */

    s3[0] = 'B'; /* 合法：那是你自己的数组 */
    /* s[0] = 'B'; 这一行千万别写，写就是段错误 */

    printf("s3=%p s3[0]=%c\n", (void *)s3, s3[0]);
    printf("s[0]=%c\n", s[0]);

    return 0;
}
