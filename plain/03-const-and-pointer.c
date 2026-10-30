#include <stdio.h>

int main(void)
{
    int p = 12;
    int y = 31;
    int const *a = &p;
    int *const b = &p;

    printf("&p=%p\n", (void *)&p);

    a = &y;
    *b = y;

    printf("a=%p *a=%d\n", (void *)a, *a);
    printf("b=%p *b=%d\n", (void *)b, *b);
    printf("p=%d y=%d\n", p, y);

    return 0;
}
