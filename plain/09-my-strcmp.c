#include <stdio.h>
#include <string.h>

int mycmp(const char *s1, const char *s2);

int main(void)
{
    char s1[] = "abc";
    char s2[] = "abc";
    char s3[] = "bbc";

    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", mycmp(s1, s2));
    printf("%d\n", s1 == s2);
    printf("%d\n", strcmp(s1, s3));
    printf("%d\n", mycmp(s1, s3));

    return 0;
}

int mycmp(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0') {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
