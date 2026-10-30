#include <stdio.h>
#include <stdlib.h>

#define CHUNK (100 * 1024 * 1024)

int main(void)
{
    void *p = NULL;
    int cnt = 0;

    while ((p = malloc(CHUNK)) != NULL && cnt < 64) {
        cnt++;
    }

    printf("分配了 %.2f GB（%d 块，每块 100 MB）\n",
           cnt * (double)CHUNK / (1024.0 * 1024.0 * 1024.0), cnt);

    free(p);

    return 0;
}
