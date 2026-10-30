#include <stdio.h>

void swap(int *pa, int *pb);
void minmax(const int *a, int len, int *min, int *max);
int divide(int a, int b, double *result);

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

    swap(&a, &b);
    printf("a=%d b=%d\n", a, b);

    minmax(arr, (int)(sizeof(arr) / sizeof(arr[0])), &min, &max);
    printf("min=%d max=%d\n", min, max);

    printf("输入两个整数: ");
    if (scanf("%d %d", &x, &y) == 2) {
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
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

void minmax(const int *a, int len, int *min, int *max)
{
    int i;
    *min = *max = a[0];
    for (i = 1; i < len; i++) {
        if (a[i] < *min) { *min = a[i]; }
        if (a[i] > *max) { *max = a[i]; }
    }
}

int divide(int a, int b, double *result)
{
    if (b == 0) { return 0; }
    *result = (double)a / b;
    return 1;
}
