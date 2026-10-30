#include <stdio.h>

/* 题目：const 写在 * 左边和右边，限制的到底是"指针"还是"数据"？
 * 输入：无
 * 输出：几个地址与值，用来肉眼确认谁被锁住
 *
 * int const *a  读法：a 指向一个 const int —— 不能通过 a 改数据，但 a 可以改指向
 * int *const b  读法：b 是一个 const 指针 —— 指向不能改，但 *b 可以改
 * 记忆：const 在 * 右边，锁的是指针本身。 */

int main(void)
{
    int p = 12;
    int y = 31;
    int const *a = &p; /* 不能写 *a = 5; 但可以写 a = &y; */
    int *const b = &p; /* 不能写 b = &y; 但可以写 *b = 5;    */

    printf("&p=%p\n", (void *)&p);

    a = &y;  /* 合法：改的是指向 */
    *b = y;  /* 合法：改的是 p 的值 */

    printf("a=%p *a=%d\n", (void *)a, *a);
    printf("b=%p *b=%d\n", (void *)b, *b);
    printf("p=%d y=%d\n", p, y); /* p 因为 *b = y 被改成了 31 */

    return 0;
}
