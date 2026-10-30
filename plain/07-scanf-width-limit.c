#include <stdio.h>

int main(void)
{
    char word[8];
    char word2[8];

    printf("输入两个词: ");
    if (scanf("%7s", word) != 1) {
        return 1;
    }
    if (scanf("%7s", word2) != 1) {
        return 1;
    }

    printf("%s##%s##\n", word, word2);

    return 0;
}
