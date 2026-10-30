#include <stdio.h>
#include <string.h>

/* 题目：不调 strcmp，自己比较两个字符串的"大小"。
 * 输入：无
 * 输出：5 个整数，前两个应为 0，后两个为负数
 *
 * 三个要点：
 *   1. 比较的是第一个不同的字符之差，不是长度
 *   2. 遇到 '\0' 要停，否则读越界
 *   3. s1 == s2 比较的是地址，两个不同数组永远是 0（假） */

int mycmp(const char *s1, const char *s2);

int main(void)
{
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "bbc";

    printf("%d\n", strcmp(s1, s2)); /* 0：完全一样 */
    printf("%d\n", mycmp(s1, s2));  /* 0：自己写的也一样 */
    printf("%d\n", s1 == s2);       /* 0：两个数组地址不同，别拿 == 比内容 */
    printf("%d\n", strcmp(s1, s3)); /* 负数：'a' - 'b' */
    printf("%d\n", mycmp(s1, s3));  /* 负数：同上 */

    return 0;
}

int mycmp(const char *s1, const char *s2)
{
    /* 两个指针同步往前走，直到不相等或遇到结尾 */
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    }

    return *s1 - *s2; /* 相同字符时差 0；不同则返回差值 */
}
