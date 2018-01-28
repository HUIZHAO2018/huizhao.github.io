---
layout: post
title: "3分钟通过一个App的演示深入理解区块链运行原理"
date: 2017-09-13
description: "通过一个App的演示快速理解区块链创始区块、hash、挖矿、区块、区块链的运行原理"
tag: 区块链
keywords: "区块链原理，区块链运行原理，挖矿原理，hash散列原理"
---

> 作者：黎跃春，资深讲师，全栈工程师；专注于「区块链+内容」产品的开发以及区块链技术培训。
> 
> 公众号：区块链部落
> 
> QQ群：348924182
> 
> 微信：liyc1215
> 
> 区块链技术部落阁：[http://liyuechun.org](http://liyuechun.org)

### 安装命令行工具

![](http://om1c35wrq.bkt.clouddn.com/Snip20170913_167.png)

- 打开终端，输入`npm install blockchain-cli -g`

```js
Last login: Wed Sep 13 15:48:00 on ttys000
liyuechun:~ yuechunli$ npm install blockchain-cli -g
/usr/local/bin/blockchain -> /usr/local/lib/node_modules/blockchain-cli/main.js

> wrtc@0.0.62 install /usr/local/lib/node_modules/blockchain-cli/node_modules/wrtc
> node-pre-gyp install --fallback-to-build

[wrtc] Success: "/usr/local/lib/node_modules/blockchain-cli/node_modules/wrtc/build/wrtc/v0.0.62/Release/node-v57-darwin-x64/wrtc.node" is installed via remote
+ blockchain-cli@1.0.5
added 263 packages in 89.506s
liyuechun:~ yuechunli$ 
```

- 终端输入`blockchain`

```js
liyuechun:~ yuechunli$ blockchain
👋  Welcome to Blockchain CLI!

  Commands:

    help [command...]      Provides help for a given command.
    exit                   Exits application.
    blockchain             See the current state of the blockchain.
    mine <data>            Mine a new block. Eg: mine hello!
    open <port>            Open port to accept incoming connections. Eg:
                           open 2727
    connect <host> <port>  Connect to a new peer. Eg: connect localhost
                           2727
    peers                  Get the list of connected peers.
    discover               Discover new peers from your connected peers.

blockchain → 
```

### 区块(block)长什么样子？

在`blockchian ->`后面输入`blockchain`或者`bc`查看创始区块结构。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170913_164.png)

- `Index (Block #):` 第几个区块? (创世区块链的索引为0)
- `Hash:` 当前区块的hash值
- `Previous Hash:` 上一个区块的hash值
- `Timestamp: `当前区块创建时的时间戳
- `Data:` 存储在当前区块上的交易信息
- `Nonce:` 在找到有效区块之前，我们经历的迭代次数

#### 创世区块（Genesis Block）

每个区块链都是由一个`创始区块「🏆 Genesis Block」`开始。后面你所看到的区块都依赖于上一个区块。因此，创始区块是我们挖取第一个区块的基础。

### 当一个区块挖矿时都发生了什么？

我们在`blockchain → `中输入`mine liyc1215`，「`liyc1215`是春哥微信号，添加我微信，拉你进区块链技术交流群」挖取我们的第一个区块。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170913_165.png)

- `Index:` o+1 = 1
- `Previous Hash:` 0000018035a828da0…
- `Timestamp:` 这个区块创建的时间
- `Data:` liyc1215
- `Hash:` ??
- `Nonce:` ??

### Hash是怎么计算的？

`Hash`值是一个`十六进制`固定长度为`64位`的唯一的标识。

`hash`值是由`index`, `previous block hash`, `timestamp`, `block data`, 和 `nonce` 作为输入数据计算而得。

```js
CryptoJS.SHA256(index + previousHash + timestamp + data + nonce)
```

The SHA256 algorithm will calculate a unique hash, given those inputs. The same inputs will always return the same hash.

`SHA256`算法将根据给出的输入数据计算出一个唯一的hash值，只要输入值不变，永远返回相同的结果。

![](http://om1c35wrq.bkt.clouddn.com/liyc1215-hash.gif)

输入数据为`liyc1215`时，它的hash值永远为`dca0762d726738ebb8e6b7b43a4ba4186588a1b711f94ba9c694bffda8fcccf9`

#### 你是否注意到块哈希中的四个前导0？

四个前导0是有效散列的最低要求。 所需的前导0的数量称为`难度`。


下面的方法验证hash难度是否有效。

```js
function isValidHashDifficulty(hash, difficulty) {
  for (var i = 0, b = hash.length; i < b; i ++) {
      if (hash[i] !== '0') {
          break;
      }
  }
  return i >= difficulty;
}
```

这就是我们所熟知的[工作量证明系统 - Proof-of-Work system](https://en.wikipedia.org/wiki/Proof-of-work_system)。


#### 什么是`nonce`？

`nonce`是一个用来找到满足条件的`hash`值的数字。

![](http://om1c35wrq.bkt.clouddn.com/nonce%E5%80%BC.gif)

```js
let nonce = 0;
let hash;
let input;
while(!isValidHashDifficulty(hash)) {     
  nonce = nonce + 1;
  input = index + previousHash + timestamp + data + nonce;
  hash = CryptoJS.SHA256(input)
}
```

`nonce`值一直迭代，直到`hash`值有效为止。在我们案例中一个有效的hash值是最少有`4`个前导`0`。找到`nonce`值以满足合适条件的`hash`值的过程就叫做挖矿。

随着难度的增加，可能的有效散列数减少。 使用较少可能的有效散列，需要更多的处理能力才能找到有效的散列。

### Hash为什么如此重要？

`hash`散列很重要是因为它可以使区块链不能被改变。

如果我们有三个区块链`1 -> 2 -> 3 -> 4 -> 5`，当某个人想要试图修改区块A时，下面几点将是会发生的几种情况。


![](http://om1c35wrq.bkt.clouddn.com/import-hash.gif)


- 区块3上的区块链被修改。
- 区块3上的hash值将发生改变，因为hash值是通过数据计算而得。
- 区块3变得无效，因为它的hash值不再具备4个前导0的条件。
- 区块4的hash值将发生改变，因为区块3的hash值用来参与计算区块4的hash值。
- 区块4变得无效，因为它的hash值不再具备4个前导0的条件。
- 区块5的hash值将发生改变，因为区块4的hash值用来参与计算区块5的hash值。
- 区块5变得无效，因为它的hash值不再具备4个前导0的条件。

如果想要无效的区块`3、4、5`变得有效，必须从区块3开始再一次重新依次挖矿，当你的区块链足够长，节点足够多时，就算你将这条链上的区块链改变并且重新挖矿成功，但是因为超过50%的节点的数据和你的节点的数据不一致，你这个被改变的节点的数据也依然无效。

![](http://om1c35wrq.bkt.clouddn.com/peer.gif)

在[这个demo](https://anders.com/blockchain/distributed.html)的演示中，一共有三个节点，我修改了节点2的区块链5并且重新挖矿取得合法的hash值，但是因为`节点A`和`节点C`中区块5的hash值为`0000e4b9052fd8aae92a8afda42e2ea0f17972ea67cead67352e74dd6f7d217c`，而`节点B`中的hash值为`0000184634edadb8fc7f4bdee87aa9d7d2a46b0c26db221998e35c1f57c0b42c`，少数服从多数，所以以节点A和C的区块数据为准。


### 参考文档

- [How does blockchain really work? I built an app to show you](https://medium.freecodecamp.org/how-does-blockchain-really-work-i-built-an-app-to-show-you-6b70cd4caf7d)
- [https://anders.com/blockchain/distributed.html](https://anders.com/blockchain/distributed.html)
- [http://blockchaindemo.io](http://blockchaindemo.io/)


### 打赏地址

**比特币：**1FcbBw62FHBJKTiLGNoguSwkBdVnJQ9NUn
**以太坊：**0xF055775eBD516e7419ae486C1d50C682d4170645


### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://orhm8wuhd.bkt.clouddn.com/qukuailian100.jpg)






