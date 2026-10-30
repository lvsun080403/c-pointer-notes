#include <stdio.h>

/* 题目：为什么 scanf 里要写 "%7s" 而不是 "%s"？
 * 输入：两个用空白分隔的词
 * 输出：词 + ##，两个拼在一起看边界
 *
 * 因为 "%s" 不知道缓冲区多大，输入一长就越界写坏栈。
 * "%7s" 表示最多读 7 个字符，留 1 个位置给 '\0'，
 * 这样 char word[8] 才刚好装得下。 */

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

    printf("%s##%s##\n", word, word2); /* 两个 ## 是边界标记，便于看清读到哪 */

    return 0;
}
