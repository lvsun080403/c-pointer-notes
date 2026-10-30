#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mycpy(char *dst, const char *src);

int main(void)
{
    char s[] = "ckjhglc";
    char *p = strchr(s, 'j');
    char *q = strrchr(s, 'c');
    char c;
    char *t;

    printf("p=%s q=%s\n", p, q);

    c = *p;
    *p = '\0';

    t = (char *)malloc(strlen(s) + 1);
    if (t == NULL) {
        return 1;
    }
    mycpy(t, s);
    printf("前半段: %s\n", t);
    free(t);

    *p = c;
    printf("原串: %s\n", s);

    return 0;
}

char *mycpy(char *dst, const char *src)
{
    char *ret = dst;

    while (*src != '\0') {
        *dst++ = *src++;
    }
    *dst = '\0';

    return ret;
}
