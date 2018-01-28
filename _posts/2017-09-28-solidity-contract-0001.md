---
layout: post
title: "『0001』 - 如何通过 MyEtherWallet 创建钱包以及如何通过 Ethereum Wallet 和 MetaMask 恢复钱包账号"
date: 2017-09-28
description: "本篇文章我们简单介绍了一下以太坊的四种钱包，包括`Ethereum Wallet`，`METAMASK`，`Parity Ethereum`以及`MyEtherWallet`，在本篇文章中，大家只需要掌握如何通过`MyEtherWallet`创建钱包，保存钱包私钥文件，如何通过`Ethereum Wallet`和`METAMASK`恢复钱包账号以及如何获取以太币。"
tag: Solidity系列
keywords: "Ethereum Wallet,METAMASK，Parity Ethereum，MyEtherWallet"
---

>来源： [黎跃春区块链博客](http://liyuechun.org)

### 学习目标

1. 钱包介绍
2. 创建钱包
3. 发送和接收以太币
4. 恢复钱包
5. 如何获取以太币


### 钱包介绍

-  Ethereum Wallet 钱包

开启`Ethereum`智能合约开发(Smart Contract)最快的方式就是`Ethereum Wallet`，它支持`Windows, MacOSX 和 Linux`开发智能合约原生Dapp(去中心化App)，你可以从[github](https://github.com/ethereum/mist/releases) 下载。

![Ethereum Wallet](http://om1c35wrq.bkt.clouddn.com/Ethereum%20Wallet.png)

在做任何操作之前，`Ethereum Wallet`需要连接到区块链并进行同步。

![](http://om1c35wrq.bkt.clouddn.com/Screen-Shot-2017-07-19-at-21.15.57.png)


输入密码，记住，这个密码不要忘记，不要忘记，不要忘记。

![](http://om1c35wrq.bkt.clouddn.com/password.png)

你刚开始同步完区块节点时，你的账户余额应该为`0`。

![](http://om1c35wrq.bkt.clouddn.com/WX20170928-163225@2x.png)

当然你可以按照下图切换到测试网络，然后开启挖矿，对于测试网络而言，很容易挖矿成功。


![](http://om1c35wrq.bkt.clouddn.com/WX20170928-163225@2x.png)
![](http://om1c35wrq.bkt.clouddn.com/WX20170928-163336@2x.png)
![](http://om1c35wrq.bkt.clouddn.com/WX20170928-163400@2x.png)


- METAMASK

[插件地址：https://chrome.google.com/webstore/search/MetaMask?hl=zh-CN](https://chrome.google.com/webstore/search/MetaMask?hl=zh-CN)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_174.png)

- Parity Ethereum

[下载地址：https://parity.io/parity.html](https://parity.io/parity.html)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_178.png)

- MyEtherWallet

[https://www.myetherwallet.com](https://www.myetherwallet.com)



### MyEtherWallet

官方网站：[https://www.myetherwallet.com](https://www.myetherwallet.com)

![](http://om1c35wrq.bkt.clouddn.com/MyEtherWallet.png)


`MyEtherWallet`网页钱包是使用起来最简单的钱包，只需要打开网页就可以使用，`MyEtherWallet`代码开源，供大家审视，还有`MyEtherWallet`钱包是去中心化的钱包，它不会存储用户的钱包信息账号，就算有一天`MyEtherWallet`网站不能使用，你也可以通过钱包的`私钥`和`密码`在其他钱包上找回你的钱包账号，`MyEtherWallet`绝对安全，请放心使用。

### 产生钱包

- 输入密码，点击生成钱包，这个密码一定要记住，这个密码一定要记住，这个密码一定要记住，这个密码一定要记住

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_93.png)

- 保存，保存，保存 `Keystore File(UTC/JSON)`文件

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_94.png)

- 下图是保存的 `Keystore File(UTC/JSON)` 文件的JSON数据

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_96.png)

- 下图是点击`I understand. Continue`后的效果图

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_97.png)

- 点击`打印纸钱包`，将这张图片打印收藏起来

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_100.png)


- 点击保存你的地址

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_105.png)


打开之前下载的``Keystore File(UTC/JSON)``文件，得到下图。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_106.png)

接着输入密码，点击解锁。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_107.png)

`0xF055775eBD516e7419ae486C1d50C682d4170645`就是我的钱包地址，如果别人给你转账，直接把这个地址给对方即可。


### 发送以太币／发送代币

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_111.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_112.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_114.png)

- 输入发送地址
- 输入`ETH`转账数量
- 上面的Gas Limit可以无需理会
- 点击`生成交易`
- 点击发送交易

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_115.png)

点击发送交易按钮后，会弹出一个确定按钮，核对信息无误后，点击`是的，我确定！发送交易`。

成功后会看到网站底部出现一个绿色框，显示发送成功，并产生了一个`TX ID`，如果大家发送ETH或其他代币到交易所，过了一段时间对方还没收到的话，可以直接将这个`TX ID`给对方检查，或者可以直接到交易记录浏览器[etherscan.io](https://etherscan.io/)，查看交易细节。

![](http://om1c35wrq.bkt.clouddn.com/mew_10.png)


### 账号恢复

- 利用METAMASK恢复账号

![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_117.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_118.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_120.png)

- 利用 Ethereum Wallet 钱包恢复账号
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_121.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_122.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_123.png)



### 如何获得以太币

1. 通过`Ethereum Wallet`进行挖矿
2. 通过MetaMask切换到测试网络进行购买
3. 可以向`https://gitter.im/kovan-testnet/faucet`网站索取
4. 得到的以太币可以在一个网络对不同的账号进行相互转换



### 小结

本篇文章我们简单介绍了一下以太坊的四种钱包，包括`Ethereum Wallet`，`METAMASK`，`Parity Ethereum`以及`MyEtherWallet`，在本篇文章中，大家只需要掌握如何通过`MyEtherWallet`创建钱包，保存钱包私钥文件，如何通过`Ethereum Wallet`和`METAMASK`恢复钱包账号以及如何获取以太币。


### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)

