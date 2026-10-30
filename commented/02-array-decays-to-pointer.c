#include <stdio.h>

/* 题目：同一个 a，为什么在 main 里 sizeof 是 40，进了函数就变成 8？
 * 输入：无
 * 输出：两处的 sizeof 与地址，以及数组的最值
 *
 * 结论：数组做参数会"退化"成指向首元素的指针，函数里拿到的只是一个
 * 地址（64 位下 8 字节），长度因此必须另外传进去——这就是 minmax
 * 为什么要多一个 len 参数。 */

void minmax(const int *a, int len, int *min, int *max);

int main(void)
{
    int a[] = {1, 2, 5, 8, 12, 21, 33, 43, 45, 56};
    int min;
    int max;

    /* 这里是真正的数组，sizeof 得到 10 * 4 = 40 */
    printf("main   sizeof(a)=%lu\n", (unsigned long)sizeof(a));
    printf("main   a=%p\n", (void *)a);

    minmax(a, (int)(sizeof(a) / sizeof(a[0])), &min, &max);
    printf("min=%d max=%d\n", min, max);

    return 0;
}

void minmax(const int *a, int len, int *min, int *max)
{
    int i;
    /* 这里 a 是指针，sizeof 只有 8；所以 len 绝不能靠 sizeof 算 */
    printf("minmax sizeof(a)=%lu\n", (unsigned long)sizeof(a));
    printf("minmax a=%p\n", (void *)a); /* 地址和 main 里打印的一样 */

    *min = *max = a[0];
    for (i = 1; i < len; i++) {
        if (a[i] < *min) { *min = a[i]; }
        if (a[i] > *max) { *max = a[i]; }
    }
}
