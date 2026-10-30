#include <stdio.h>

/* 题目：用一个函数同时带回两个结果，或者带回"成功/失败 + 结果"。
 * 输入：无（a、b 与数组写死在代码里），之后从键盘读两个整数做除法
 * 输出：交换后的 a b、数组的最值、除法结果
 *
 * 思路：C 的函数只能 return 一个值，所以"多返回"只能靠指针把
 * 调用者的变量地址传进来，函数里用 *pa 直接改它。 */

void swap(int *pa, int *pb);              /* 声明里参数名可省略，这里留着方便读 */
void minmax(const int *a, int len, int *min, int *max);
int divide(int a, int b, double *result); /* 返回 1 成功 / 0 失败 */

int main(void)
{
    int a = 5;
    int b = 7;
    int arr[] = {1, 2, 5, 8, 12, 21, 33, 43, 45, 56};
    int min;
    int max;
    int x;
    int y;
    double q;

    /* 传地址进去，函数改的就是这里的 a、b */
    swap(&a, &b);
    printf("a=%d b=%d\n", a, b);

    /* sizeof(arr)/sizeof(arr[0]) 之所以能算出 10，是因为 arr 这里是数组
     * 而不是指针——这一点在第 02 题里专门验证 */
    minmax(arr, (int)(sizeof(arr) / sizeof(arr[0])), &min, &max);
    printf("min=%d max=%d\n", min, max);

    printf("输入两个整数: ");
    if (scanf("%d %d", &x, &y) == 2) {
        /* 结果用指针带回，返回值只表示"成没成功" */
        if (divide(x, y, &q)) {
            printf("%d/%d=%lf\n", x, y, q);
        } else {
            printf("除数不能为 0\n");
        }
    }

    return 0;
}

void swap(int *pa, int *pb)
{
    int t = *pa;   /* 先把 a 的值存下来，否则第二步就被覆盖了 */
    *pa = *pb;
    *pb = t;
}

/* a 只读，所以参数写成 const int *，能防止函数内部误改调用者的数组 */
void minmax(const int *a, int len, int *min, int *max)
{
    int i;
    *min = *max = a[0]; /* 连写赋值：两个指针指向的变量都拿到 a[0] */
    for (i = 1; i < len; i++) {
        if (a[i] < *min) { *min = a[i]; }
        if (a[i] > *max) { *max = a[i]; }
    }
}

int divide(int a, int b, double *result)
{
    if (b == 0) { return 0; }      /* 失败就干脆不碰 *result */
    *result = (double)a / b;       /* 必须强转，否则 5/2 会先做整数除法 */
    return 1;
}
