# GSS1 - Can you answer these queries I

## 题面翻译

给定长度为 $n$ 的序列 $a_1, a_2,\cdots,a_n$。现在有 $m$ 次询问操作，每次给定 $l_i,r_i$，查询 $[l_i,r_i]$ 区间内的最大子权和。

区间 $[l,r]$ 的最大子权和被定义为 $\max\{a_i+a_{i+1}+\cdots+a_{j-1}+a_j\mid l\le i\le j\le r\}$。

$|a_i|\le 15007$，$1\le n\le 5\times 10^4$。

## 题目描述

You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:   
 Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.   
 Given M queries, your program must output the results of these queries.

## 输入格式

- The first line of the input file contains the integer N.
- In the second line, N numbers follow.
- The third line contains the integer M.
- M lines follow, where line i contains 2 numbers xi and yi.

## 输出格式

Your program should output the results of the M queries, one query per line.

## 样例 #1

### 样例输入 #1

```
3 
-1 2 3
1
1 2
```

### 样例输出 #1

```
2
```