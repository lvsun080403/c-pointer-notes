# c-pointer-notes · 10 个指针实验，把「\*」和「&」看穿

<p>
  <img alt="C" src="https://img.shields.io/badge/C-C89%20%2F%20C99-2b6cb0?style=flat-square">
  <img alt="Platform" src="https://img.shields.io/badge/Windows-10%20%2F%2011-0078d4?style=flat-square">
  <img alt="Experiments" src="https://img.shields.io/badge/10%20experiments-2%20versions-38a169?style=flat-square">
  <img alt="License" src="https://img.shields.io/badge/license-MIT-brightgreen?style=flat-square">
</p>

> 指针不是难点，「它在内存里到底指向哪」才是。这份仓库把 C 指针课上最容易被一句「你记住就行」带过去的 10 个实验，每个都做成两个版本：**plain/** 只有代码，**commented/** 逐行讲清为什么。

---

## 这不是教程，是一份「对照组」

指针的困惑几乎总是同一批：

- `sizeof(a)` 在 `main` 里是 40，进了函数变成 8，为什么？
- `int const *a` 和 `int *const b`，到底谁不能改？
- `*p++` 到底先加还是先取值？
- `char *s = "abc"` 和 `char s[] = "abc"`，看起来一样，为什么一个能改一个会崩？

这些问题的答案都不长，但**光看文字记不住**。所以这里每个实验都能编译、能跑、能打印出地址和 `sizeof`——你亲眼看到 `40` 和 `8` 并排出现，比读十遍解释都管用。

10 个实验覆盖：指针出参、数组退化、const 与指针的组合、哨兵遍历、堆分配失败、字符串字面量与数组、`scanf` 宽度、`getchar` 与 EOF、`strcmp` 实现、`strchr` 就地截断与 `strcpy` 实现。

---

## 两个版本，怎么读

|  | `plain/` | `commented/` |
| --- | --- | --- |
| 内容 | 纯代码，一行注释都没有 | 文件头有题目/输入/输出/思路，行内有讲解 |
| 行数 | 15–60 行 | 多 30%–80% |
| 适合 | 已经懂了，想拿一份干净骨架 | 第一次学，或者想对着看「为什么这么写」 |

**推荐读法**：先读 `plain/`，猜每一行在做什么；卡住了再看 `commented/` 把那一行讲透。两份代码逻辑完全一致，唯一区别是注释。

---

## 10 个实验一览

| # | 文件 | 一句话 | 跑起来你会看到 |
| --- | --- | --- | --- |
| 01 | `01-swap-minmax-divide.c` | 指针做「出参」：一个函数带回多个结果 | `a=7 b=5`、`min=1 max=56`、`10/4=2.500000` |
| 02 | `02-array-decays-to-pointer.c` | 数组传参为什么会退化成指针 | 同一个 `a`：`sizeof` 从 **40** 变 **8**，地址不变 |
| 03 | `03-const-and-pointer.c` | `const` 在 `*` 左边和右边锁的不是同一个东西 | 改指向合法、改数据合法，但两者不能同时 |
| 04 | `04-pointer-walk-sentinel.c` | 不给长度，靠哨兵值走到头 | `0` 到 `9`，`-1` 不打印 |
| 05 | `05-malloc-exhaustion.c` | 一直 `malloc` 到失败，看堆的边界 | `分配了 6.25 GB（64 块，每块 100 MB）` |
| 06 | `06-string-literal-vs-array.c` | 字面量在只读段，数组在栈上 | `s3[0]` 改成 `B` 成功；`s[0]` 只读 |
| 07 | `07-scanf-width-limit.c` | `%7s` 的 7 是什么 | 输入 `abcdefghij klm` → `abcdefg##hij##` |
| 08 | `08-getchar-eof.c` | `getchar` 为什么必须用 `int` 接 | 原样回显，最后打印 `EOF` |
| 09 | `09-my-strcmp.c` | 自己实现 `strcmp` | `0 0 0 -1 -1`（注意第三个是 `s1==s2` 的地址比较） |
| 10 | `10-split-and-mycpy.c` | `strchr` + 临时 `'\0'` 把串就地断开再还原 | `前半段: ck`、`原串: ckjhglc` |

---

## 三个「看一眼就懂」的瞬间

**① 数组一进函数就瘦了**

```text
main   sizeof(a)=40
main   a=000000000015FEC8
minmax sizeof(a)=8
minmax a=000000000015FEC8
```

地址一样，`sizeof` 差了 5 倍。函数里拿到的不是数组，是首元素地址。所以 `minmax(const int *a, int len, ...)` 的 `len` 不是多余参数，是**必须**传——函数里算不出来。

**② const 写在 `*` 的哪一边，锁的东西不一样**

```c
int const *a = &p;   /* 锁数据：*a 不能改，a 可以改指向 */
int *const b = &p;   /* 锁指针：b 不能改指向，*b 可以改数据 */
```

记忆口诀：`const` 紧挨着谁，谁就不能动。

**③ 只读段 vs 栈**

`char *s = "Hello Word";` 里 `s` 指向只读段，`s[0] = 'B';` 直接段错误。
`char s3[] = "Hello Word";` 是在栈上抄了一份，`s3[0] = 'B';` 随便改。

同一个字符串字面量，一个能改一个不能，差别只在**它是被指向，还是被拷贝**。

---

## 怎么编译

### 方式一：`build.bat`（Windows 一键）

```bat
build.bat            :: 编译 plain/ 到 build/
build.bat commented  :: 编译 commented/ 到 build/
build.bat plain gcc  :: 指定编译器
```

脚本会依次探测 `gcc`、`clang`、`tcc`，找到哪个用哪个，最后报告成功/失败数量，全成功返回 0。输出是英文（避免 cmd 代码页把中文打成乱码）。

### 方式二：MSVC（Visual Studio 开发者命令提示符）

```bat
cl /W4 /Fe:sort.exe plain\01-swap-minmax-divide.c
```

### 方式三：MinGW / TCC

```bash
gcc -Wall -Wextra -o sort plain/01-swap-minmax-divide.c
tcc -o sort plain/01-swap-minmax-divide.c
```

> 代码是 C89 风格：变量在块首声明、不用 `//` 注释、`scanf` 返回值都做了检查——老编译器（VC6、Turbo C）和现代 gcc/clang 都能过。

---

## 当年写错的 5 个地方

这 10 个文件来自一个学期的课堂实验。原始版本里有几处典型错误，我**保留在注释里、修正在工作代码里**，因为踩过才知道为什么：

| 错误 | 原版写法 | 问题 | 修正 |
| --- | --- | --- | --- |
| 字符串比较大小时多了一句空语句 | `*s1 == *s2;` | 这行什么都不做，循环条件才是关键 | 删掉，改成 `while (*s1 == *s2 && *s1 != '\0')` |
| `mycpy` 返回值写错 | `return dst;` | `dst` 已经被移动到串尾，调用者拿到的是"\0"的位置 | 开头存 `char *ret = dst;`，最后 `return ret;` |
| 用了 `malloc` 却没包含头 | 只 `#include <string.h>` | C89 下隐式声明返回 `int`，64 位截断指针 | 补 `#include <stdlib.h>` |
| 一直 `malloc` 到吃满内存 | `while (p = malloc(100MB))` | 真的会把机器内存吃光，可能卡死整台机 | 加 `cnt < 64` 上限（6.4 GB），思路不变 |
| `scanf("%s")` 不设宽度 | `scanf("%s", word)` | 输入一长就越界写坏栈 | `scanf("%7s", word)`，留 1 位给 `'\0'` |

完整对照见 `commented/` 每个文件的头部说明。

---

## 目录结构

```text
c-pointer-notes/
├── plain/                  # 只有代码
│   ├── 01-swap-minmax-divide.c
│   ├── ...
│   └── 10-split-and-mycpy.c
├── commented/              # 带讲解，逻辑与 plain/ 完全一致
│   ├── 01-swap-minmax-divide.c
│   ├── ...
│   └── 10-split-and-mycpy.c
├── build.bat               # Windows 一键编译
├── LICENSE
└── README.md
```

---

## 建议的阅读顺序

按概念分四组，一组一组来：

1. **让函数带回结果**：`01` → `09`（都是"多返回值/返回值"的思路）
2. **指针和数组到底差在哪**：`02` → `04` → `06`（退化、遍历、字面量）
3. **const 与内存边界**：`03` → `05`（谁不能改、堆能借多少）
4. **字符串处理的经典套路**：`07` → `08` → `10`（宽度、EOF、就地截断）

---

## FAQ

**Q：为什么我跑出来 `sizeof(a)` 是 8 而不是 4？**
A：64 位程序里指针是 8 字节。32 位编译（VC6 默认）下会是 4。这不是代码问题，是平台问题。

**Q：06 里 `s` 和 `s2` 的地址一样吗？**
A：不一定。两个内容相同的字面量**可能**被编译器合并成一份，也可能各自占一份——C 标准不承诺。所以别依赖这个规律，也别通过 `s` 去改字面量。

**Q：`05` 会不会把我电脑内存吃满？**
A：不会。代码里有 `cnt < 64` 上限（6.4 GB），跑完立刻退出，进程结束时系统全部回收。想看真实边界可以把上限调大，但**不建议**在没有保存工作的情况下试。

**Q：为什么代码不用 `//` 注释？**
A：为了兼容 VC6 / Turbo C 这类老编译器（C89 没有 `//`），也为了让这份代码能直接丢进课程作业环境。

**Q：能直接拿去交作业吗？**
A：能跑，但更建议你读完 `commented/` 再自己重写一遍——这个仓库的目的不是给你一份可提交的文件，是让你知道**每一行为什么这么写**。

---

## License

MIT © 2026 lvsun080403
