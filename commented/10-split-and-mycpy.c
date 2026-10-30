#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 题目：用 strchr 把字符串在某个字符处"断开"，再把前半段复制出去。
 * 输入：无
 * 输出：找到的位置、切出来的前半段、恢复后的原串
 *
 * 技巧：把 *p 临时改成 '\0'，原串就被截断成前半段；
 * 复制完再把 c 写回去，原串完好如初。 */

char *mycpy(char *dst, const char *src);

int main(void)
{
    char s[] = "ckjhglc";
    char *p = strchr(s, 'j');   /* 第一次出现的位置 */
    char *q = strrchr(s, 'c');  /* 最后一次出现的位置 */
    char c;
    char *t;

    printf("p=%s q=%s\n", p, q);

    c = *p;      /* 先把被抹掉的字符存起来 */
    *p = '\0';   /* 就地截断：s 现在等于 "ckjhgl" 的前半段 */

    t = (char *)malloc(strlen(s) + 1); /* +1 是给 '\0' 留位置 */
    if (t == NULL) {
        return 1;
    }
    mycpy(t, s);
    printf("前半段: %s\n", t);
    free(t);

    *p = c;      /* 还原，不留痕迹 */
    printf("原串: %s\n", s);

    return 0;
}

char *mycpy(char *dst, const char *src)
{
    char *ret = dst; /* 记住开头：最后要返回它，不是返回走到底的 dst */

    while (*src != '\0') {
        *dst++ = *src++;
    }
    *dst = '\0';

    return ret;
}
