# Moamen and XOR

## 题面翻译

你需要构造出一个长度为 $n$ 的数组，其中每一个元素都小于 $2^k$，并且满足：

$$a_1\operatorname{and}a_2\operatorname{and}\dots\operatorname{and}a_n\geqslant a_1\operatorname{xor}a_2\operatorname{xor}\dots\operatorname{xor}a_n$$

求有多少种满足条件的构造数组的方案，**答案对 $10^9+7$ 取模**。

$t$ 组数据，$1\leqslant t\leqslant 5$，$1\leqslant n\leqslant 2\times 10^5$，$0\leqslant k\leqslant 2\times 10^5$。

Translated by Eason_AC  
2021.8.11

## 题目描述

Moamen and Ezzat are playing a game. They create an array $ a $ of $ n $ non-negative integers where every element is less than $ 2^k $ .

Moamen wins if $ a_1 \,\&\, a_2 \,\&\, a_3 \,\&\, \ldots \,\&\, a_n \ge a_1 \oplus a_2 \oplus a_3 \oplus \ldots \oplus a_n $ .

Here $ \& $ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND), and $ \oplus $ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Please calculate the number of winning for Moamen arrays $ a $ .

As the result may be very large, print the value modulo $ 1\,000\,000\,007 $ ( $ 10^9 + 7 $ ).

## 输入格式

The first line contains a single integer $ t $ ( $ 1 \le t \le 5 $ )— the number of test cases.

Each test case consists of one line containing two integers $ n $ and $ k $ ( $ 1 \le n\le 2\cdot 10^5 $ , $ 0 \le k \le 2\cdot 10^5 $ ).

## 输出格式

For each test case, print a single value — the number of different arrays that Moamen wins with.

Print the result modulo $ 1\,000\,000\,007 $ ( $ 10^9 + 7 $ ).

## 样例 #1

### 样例输入 #1

```
3
3 1
2 1
4 0
```

### 样例输出 #1

```
5
2
1
```

## 提示

In the first example, $ n = 3 $ , $ k = 1 $ . As a result, all the possible arrays are $ [0,0,0] $ , $ [0,0,1] $ , $ [0,1,0] $ , $ [1,0,0] $ , $ [1,1,0] $ , $ [0,1,1] $ , $ [1,0,1] $ , and $ [1,1,1] $ .

Moamen wins in only $ 5 $ of them: $ [0,0,0] $ , $ [1,1,0] $ , $ [0,1,1] $ , $ [1,0,1] $ , and $ [1,1,1] $ .