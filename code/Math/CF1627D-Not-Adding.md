# Not Adding

## 题面翻译

你有一个长度为 $n$ 的数组 $a_1,a_2,\dots,a_n$，每次操作你可以选择数组中的两个元素 $a_i,a_j$（**需要保证 $\gcd\{a_i,a_j\}$ 不在原数组内**），然后将 $\gcd\{a_i,a_j\}$ 放到数组末尾。求你最多能够对这个数组进行多少次操作。

数据范围：

- $2\leqslant n\leqslant 10^6$。
- $1\leqslant a_i\leqslant 10^6$。

Translated by Eason_AC  
2022.1.19

## 题目描述

You have an array $ a_1, a_2, \dots, a_n $ consisting of $ n $ distinct integers. You are allowed to perform the following operation on it: 

- Choose two elements from the array $ a_i $ and $ a_j $ ( $ i \ne j $ ) such that $ \gcd(a_i, a_j) $ is not present in the array, and add $ \gcd(a_i, a_j) $ to the end of the array. Here $ \gcd(x, y) $ denotes [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers $ x $ and $ y $ .

Note that the array changes after each operation, and the subsequent operations are performed on the new array.

What is the maximum number of times you can perform the operation on the array?

## 输入格式

The first line consists of a single integer $ n $ ( $ 2 \le n \le 10^6 $ ).

The second line consists of $ n $ integers $ a_1, a_2, \dots, a_n $ ( $ 1 \leq a_i \leq 10^6 $ ). All $ a_i $ are distinct.

## 输出格式

Output a single line containing one integer — the maximum number of times the operation can be performed on the given array.

## 样例 #1

### 样例输入 #1

```
5
4 20 1 25 30
```

### 样例输出 #1

```
3
```

## 样例 #2

### 样例输入 #2

```
3
6 10 15
```

### 样例输出 #2

```
4
```

## 提示

In the first example, one of the ways to perform maximum number of operations on the array is:

- Pick $ i = 1, j= 5 $ and add $ \gcd(a_1, a_5) = \gcd(4, 30) = 2 $ to the array.
- Pick $ i = 2, j= 4 $ and add $ \gcd(a_2, a_4) = \gcd(20, 25) = 5 $ to the array.
- Pick $ i = 2, j= 5 $ and add $ \gcd(a_2, a_5) = \gcd(20, 30) = 10 $ to the array.

It can be proved that there is no way to perform more than $ 3 $ operations on the original array.

In the second example one can add $ 3 $ , then $ 1 $ , then $ 5 $ , and $ 2 $ .