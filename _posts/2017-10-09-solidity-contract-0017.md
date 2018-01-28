---
layout: post
title: "『0017』 - Solidity Types - Solidity 枚举（Enums）"
date: 2017-10-09
description: "本篇文章主要介绍Solidity 枚举（Enums）类型的创建以及使用。"
tag: Solidity系列
keywords: "Solidity 枚举（Enums）"
---


> [孔壹学院：国内区块链职业教育领先品牌](http://www.kongyixueyuan.com)
> 
> 作者：黎跃春，区块链、高可用架构工程师
> 微信：liyc1215  QQ群：348924182  博客：http://liyuechun.org


## 案例

下面的代码是我对官方案例作了简单的修改而成。`ActionChoices`就是一个自定义的整型，当枚举数不够多时，它默认的类型为`uint8`，当枚举数足够多时，它会自动变成`uint16`，下面的`GoLeft == 0`,`GoRight == 1`, `GoStraight == 2`, `SitStill == 3`。在`setGoStraight`方法中，我们传入的参数的值可以是`0 - 3`当传入的值超出这个范围时，就会中断报错。

```
pragma solidity ^0.4.4;

contract test {
    enum ActionChoices { GoLeft, GoRight, GoStraight, SitStill }
    ActionChoices _choice;
    ActionChoices constant defaultChoice = ActionChoices.GoStraight;

    function setGoStraight(ActionChoices choice) public {
        _choice = choice;
    }

    function getChoice() constant public returns (ActionChoices) {
        return _choice;
    }

    function getDefaultChoice() pure public returns (uint) {
        return uint(defaultChoice);
    }
}

```

## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)



