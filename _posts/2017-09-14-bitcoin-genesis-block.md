---
layout: post
title: "来来来，看看Bitcoin创世区块长什么样"
date: 2017-09-14
description: "Bitcoin-Qt钱包介绍，Bitcoin创世区块信息展示"
tag: Bitcoin创世区块
keywords: "Bitcoin创世区块，比特币创世区块，挖矿原理，hash散列原理"
---

### 钱包下载

[下载Bitcoin Core钱包：https://bitcoin.org/zh_CN/choose-your-wallet](https://bitcoin.org/zh_CN/choose-your-wallet)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_180.png)


### 安装到一个自定义的文件夹

```js
liyuechun:blockchain yuechunli$ pwd
/Users/liyuechun/Documents/blockchain
liyuechun:blockchain yuechunli$ ls
banlist.dat		db.log			mempool.dat
blocks			debug.log		peers.dat
chainstate		fee_estimates.dat	wallet.dat
liyuechun:blockchain yuechunli$
```

`blocks`存储的是区块数据，`wallet.dat`存储的是钱包数据。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170914_181.png)

上图中的`blk00000.dat`是比特币中的创世区块。

### 查看创世区块数据


```js
localhost:blocks yuechunli$ pwd
/Users/liyuechun/Documents/blockchain/blocks
localhost:blocks yuechunli$ hexdump -n 10000 -C blk00000.dat 
```


![](http://om1c35wrq.bkt.clouddn.com/%E5%88%9B%E4%B8%96%E5%8C%BA%E5%9D%97.gif)

`EThe T imes 03/Jan/2009 Chancellor on b rink of second b ailout for banks` 这一串数据就是`中本聪`在`2009年1月3`号写入的。


### 打赏地址

**比特币：**1FcbBw62FHBJKTiLGNoguSwkBdVnJQ9NUn
**以太坊：**0xF055775eBD516e7419ae486C1d50C682d4170645


### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://orhm8wuhd.bkt.clouddn.com/qukuailian100.jpg)







