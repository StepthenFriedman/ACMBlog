# LCS

## 题面翻译

题目描述：

给定一个字符串 $s$ 和一个字符串 $t$ ，输出 $s$ 和 $t$ 的最长公共子序列。

输入格式：

两行，第一行输入 $s$ ，第二行输入 $t$ 。

输出格式：

输出 $s$ 和 $t$ 的最长公共子序列。如果有多种答案，输出任何一个都可以。

说明/提示：

数据保证 $s$ 和 $t$ 仅含英文小写字母，并且 $s$ 和 $t$ 的长度小于等于3000。

## 题目描述

[problemUrl]: https://atcoder.jp/contests/dp/tasks/dp_f

文字列 $ s $ および $ t $ が与えられます。 $ s $ の部分列かつ $ t $ の部分列であるような文字列のうち、最長のものをひとつ求めてください。

## 输入格式

入力は以下の形式で標準入力から与えられる。

> $ s $ $ t $

## 输出格式

$ s $ の部分列かつ $ t $ の部分列であるような文字列のうち、最長のものをひとつ出力せよ。 答えが複数ある場合、どれを出力してもよい。

## 样例 #1

### 样例输入 #1

```
axyb
abyxb
```

### 样例输出 #1

```
axb
```

## 样例 #2

### 样例输入 #2

```
aa
xayaz
```

### 样例输出 #2

```
aa
```

## 样例 #3

### 样例输入 #3

```
a
z
```

### 样例输出 #3

```

```

## 样例 #4

### 样例输入 #4

```
abracadabra
avadakedavra
```

### 样例输出 #4

```
aaadara
```

## 提示

### 注釈

文字列 $ x $ の*部分列*とは、$ x $ から $ 0 $ 個以上の文字を取り除いた後、残りの文字を元の順序で連結して得られる文字列のことです。

### 制約

- $ s $ および $ t $ は英小文字からなる文字列である。
- $ 1\ \leq\ |s|,\ |t|\ \leq\ 3000 $

### Sample Explanation 1

答えは `axb` または `ayb` です。 どちらを出力しても正解となります。

### Sample Explanation 3

答えは `` (空文字列) です。