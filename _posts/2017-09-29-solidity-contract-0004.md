---
layout: post
title: "『0004』- 基于Ethereum Wallet的Solidity HelloWorld智能合约(Smart Contract)"
date: 2017-09-29
description: "相信大家都有学习各种开发语言的经历，一般学习任何一门语言都会先从最简单的HelloWorld开始，所以本篇文章，我们将编写一个最基本的合约代码，并且一步步讲解如何通过`Ethereum Wallet`将合约部署到区块链，同时我们将通过本demo的演示如何通过发送数据和接收数据和合约进行交互。"
tag: Solidity系列
keywords: "Ethereum Wallet, Ethereum Wallet Smart Contract, Ethereum Wallet 部署智能合约"
---


>来源： [黎跃春区块链博客](http://liyuechun.org)

相信大家都有学习各种开发语言的经历，一般学习任何一门语言都会先从最简单的HelloWorld开始，所以本篇文章，我们将编写一个最基本的合约代码，并且一步步讲解如何通过`Ethereum Wallet`将合约部署到区块链，同时我们将通过本demo的演示如何通过发送数据和接收数据和合约进行交互。

Solidity合约的语法和面向对象编程语言非常相似，一个合约有我们能够调用的`方法（函数）`和能够存储数据和读取数据的`属性（状态变量）`。

### Counter合约源码

我们的`Counter`合约将`increment`方法被调用的次数存储到`count`属性中。并且每个人都可以通过`getCount`方法获取区块链上`count`的值。

```
pragma solidity ^0.4.4;

contract Counter {

    /* 定义一个uint类型的count变量 */
    uint count = 0;

    /* 当这个方法被调用时count的值会加1 */
    function increment() public {
       count = count + 1;
    }

    /* 读取count数据 */
    function getCount() constant returns (uint) {
       return count;
    }

}
```

### Counter合约部署

- 要想发布我们的合约到区块链，打开`Ethereum Wallet`然后点击`Contracts`。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-103529@2x.png)

- 点击部署一个新合约。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-103911@2x.png)

- 将我们的`Counter`合约代码拷贝到`Ethereum Wallet`代码区域。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-104135@2x.png)

- 选择`Counter`合约，然后点击`DEPLOY`按钮。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-104401@2x.png)

- 输入当前部署的钱包的密码，然后点击`SEND TRANSACTION`按钮。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-104603@2x.png)

- 查看最新交易。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-105351@2x.png)

- 查看交易信息。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-105526@2x.png)


### 和Counter合约互动

- 因为我们部署的合约是部署在`Account 2`上的，所以我们可以点击`Account 2`查看最新的交易记录。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-110122@2x.png)

- 点击`Counter`按钮，进入交互界面。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-110313@2x.png)

- 选择`Increment`和`Account 2`，然后点击`EXECUTE`按钮。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-110529@2x.png)

- 输入密码，点击`SEND TRANSACTION`按钮。

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-110714@2x.png)

- 交易执行完成后，count会自动加1

![](http://om1c35wrq.bkt.clouddn.com/WX20170929-111005@2x.png)
![](http://om1c35wrq.bkt.clouddn.com/WX20170929-111217@2x.png)

### 小结

部署合约时，因为要往区块链写入数据，需要矿工进行验证，所以需要花费一些gas奖励给矿工，还有当我们每次调用`increment`方法时，也属于写入数据，同样需要花费gas，但是调用`getCount`方法时只是从区块链读取数据，无需验证，读取数据无须花费gas。



### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)






