#include <stdio.h>

int main(void)
{
    int i = 0;
    char *s = "Hello Word";
    char *s2 = "Hello Word";
    char s3[] = "Hello Word";

    printf("&i=%p\n", (void *)&i);
    printf("s =%p\n", (void *)s);
    printf("s2=%p\n", (void *)s2);
    printf("s3=%p\n", (void *)s3);

    s3[0] = 'B';
    printf("s3=%p s3[0]=%c\n", (void *)s3, s3[0]);
    printf("s[0]=%c\n", s[0]);

    return 0;
}
