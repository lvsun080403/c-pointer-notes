#include <stdio.h>

void minmax(const int *a, int len, int *min, int *max);

int main(void)
{
    int a[] = {1, 2, 5, 8, 12, 21, 33, 43, 45, 56};
    int min;
    int max;

    printf("main   sizeof(a)=%lu\n", (unsigned long)sizeof(a));
    printf("main   a=%p\n", (void *)a);

    minmax(a, (int)(sizeof(a) / sizeof(a[0])), &min, &max);
    printf("min=%d max=%d\n", min, max);

    return 0;
}

void minmax(const int *a, int len, int *min, int *max)
{
    int i;
    printf("minmax sizeof(a)=%lu\n", (unsigned long)sizeof(a));
    printf("minmax a=%p\n", (void *)a);

    *min = *max = a[0];
    for (i = 1; i < len; i++) {
        if (a[i] < *min) { *min = a[i]; }
        if (a[i] > *max) { *max = a[i]; }
    }
}
