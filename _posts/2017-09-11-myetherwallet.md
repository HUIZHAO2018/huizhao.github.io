---
layout: post
title: "ETH与以太坊代币钱包MyEtherWallet使用教程"
date: 2017-09-11
description: "如何创建MyEtherWallet钱包、如何保存钱包私钥、如何首款、转账，如何恢复钱包账号"
tag: 钱包
keywords: "MyEtherWallet 教程，以太坊钱包，恢复钱包账号"
---

> 作者：黎跃春，资深讲师，全栈工程师；专注于「区块链+内容」产品的开发以及区块链技术培训。
> 
> 公众号：区块链部落
> 
> QQ群：348924182
> 
> 区块链技术部落阁：http://liyuechun.org

### 学习目标

1. 钱包介绍
2. 创建钱包
3. 发送和接收以太币
4. 恢复钱包


### 钱包介绍

- Mist钱包

[下载地址：https://ethereum.org](https://ethereum.org)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_172.png)


- METAMASK

[插件地址：https://chrome.google.com/webstore/search/MetaMask?hl=zh-CN](https://chrome.google.com/webstore/search/MetaMask?hl=zh-CN)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_174.png)

- Parity Ethereum

[下载地址：https://parity.io/parity.html](https://parity.io/parity.html)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_178.png)

- MyEtherWallet

[https://www.myetherwallet.com](https://www.myetherwallet.com)


## MyEtherWallet

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

- 利用Mist钱包恢复账号
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_121.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_122.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170911_123.png)




### 小结

`MyEtherWallet`钱包最基本的功能已经介绍完，其实`MyEtherWallet`还可以让大家参与ICO、竞投ETH域名、与Ledger冷钱包连接等，功能相当强大，我们往后会再介绍这些功能的用法。
后续我会再介绍其他支持ETH的钱包，包括Jaxx、Metamask、Parity和以太坊官方的Mist钱包，而`MyEtherWallet`所能够产生的备份方式，刚好都能在这些钱包中恢复，所以大家不妨先尝试使用MEW，熟悉之后可以更快理解其他钱包的构架和运作。


### 参考文档


- https://www.myetherwallet.com
- http://blockcast.it/2017/05/27/eth-and-eth-token-wallet-series-myetherwallet/


### 打赏地址

**比特币：**1FcbBw62FHBJKTiLGNoguSwkBdVnJQ9NUn
**以太坊：**0xF055775eBD516e7419ae486C1d50C682d4170645


### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://orhm8wuhd.bkt.clouddn.com/qukuailian100.jpg)






