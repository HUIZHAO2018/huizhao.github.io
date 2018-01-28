---
layout: post
title: "『0009』 - Solidity Types - 布尔(Booleans)"
date: 2017-10-02
description: "本节主要介绍布尔(Booleans)类型，以及它支持的运算符，包括，! 逻辑非，&& 逻辑与，|| 逻辑或，等于，不等于"
tag: Solidity系列
keywords: "soldity 布尔(Booleans)   或 与 非"
---

>来源： [黎跃春区块链博客](http://liyuechun.org)

### 布尔(Booleans)

`bool:` 可能的取值为常量值`true`和`false`。

支持的运算符：

- `!` 逻辑非

- `&&` 逻辑与

- `||` 逻辑或

- `==` 等于

- `!=` 不等于

**备注：**运算符`&&`和`||`是短路运算符，如`f(x)||g(y)`，当`f(x)`为真时，则不会继续执行`g(y)`在`f(x)&&g(y)`表达式中，当`f(x)`为`false`时，则不会执行`g(y)`。


```
bool a = true;
bool b = !a;

// a == b -> false
// a != b -> true
// a || b -> true
// a && b -> false
```

### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


