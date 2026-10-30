#include <stdio.h>
#include <stdlib.h>

#define CHUNK (100 * 1024 * 1024) /* 100 MB */

/* 题目：机器到底还有多少内存可以借给进程？
 * 输入：无
 * 输出：成功拿到多少块 100 MB，一共多少 GB
 *
 * 注意：原版作业是 while(p = malloc(...)) 一直要到分配失败为止，
 * 那会把内存吃满、可能让整台机器卡死。这里加了 cnt < 64 的上限
 * （最多 6.4 GB），保留"问到失败为止"的思路，但不至于伤到系统。 */

int main(void)
{
    void *p = NULL;
    int cnt = 0;

    /* malloc 返回 NULL 就说明要不动了；括号不能少，
     * 否则 while (p = malloc(...)) 会因为赋值表达式而告警 */
    while ((p = malloc(CHUNK)) != NULL && cnt < 64) {
        cnt++;
    }

    printf("分配了 %.2f GB（%d 块，每块 100 MB）\n",
           cnt * (double)CHUNK / (1024.0 * 1024.0 * 1024.0), cnt);

    free(p); /* 只 free 到最后一块也没关系，进程退出后系统会全部回收 */

    return 0;
}
