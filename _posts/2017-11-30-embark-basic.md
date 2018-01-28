---
layout: post
title: "【以太坊智能合约】Embark Framework 开发基础篇"
date: 2017-11-30
description: "本篇文章主要是带大家初步认识Embark framework，通过本篇文章，相信大家对Embark framework框架有了初步的认识，知道如何安装Embark framework环境，如何启动模拟器，如何运行程序，如何在控制台和合约实例交互。"
tag: embark
keywords: "IPFS  Ethereum embark embark_demo"
---

> 作者： 黎跃春 
> 微信：liyc1215（进微信群，加微信）

在之前的文章中，我们看到了使用Solidity开发以太坊智能合约的所有基本知识。我们使用了以太坊钱包，我们能够轻松设置小型产品开发环境。我们会发现开始的时候很不错，但是如果我们想要更深入的话呢？我们要编写更大的应用程序，能够使用多个源文件。编写、测试、调试、使用版本控制系统，一次部署多个合约等等。


为了更深入，我们将使用Embark框架。 Embark框架很容易上手，并具有很多功能：

- Blockchain (Ethereum)
- 去中心化 Storage (IPFS)
- 去中心化交流 (Whisper, Orbit)
- Web 技术

## 目录 

- [1. 安装 Embark framework](#1-安装-Embark-framework)
- [2. Embark framework Hello World](#2-Embark-framework-Hello-World)
    - [2.1 启动服务器和控制器](#21-启动服务器和控制器)
    - [2.2 终端读取和修改`storedData`的值](#22-终端读取和修改`storedData`的值)
    - [2.3 Web端获取`storedData`的值](#23-Web端获取`storedData`的值)
    - [2.4 Web端点击`Set Value`修改`storedData`的值](#24-Web端点击`Set-Value`修改`storedData`的值)
- [3. 小结](#3-小结)



## 1. 安装 Embark framework

你可以在任何平台安装`Embark framework`，下面是你需要安装的工具。

- [Geth:Ethereum 协议的官方go实现](https://github.com/ethereum/go-ethereum/wiki/Building-Ethereum)
- [NodeJS和NPM:JavaScript应用的运行时和包管理器](https://nodejs.org/en/download/)

如果你已经安装上面的工具，我们将使用`NPM`来安装` embark framework`。

```
localhost:~ yuechunli$  npm -g install embark ethereumjs-testrpc
/usr/local/bin/embark -> /usr/local/lib/node_modules/embark/bin/embark
/usr/local/bin/testrpc -> /usr/local/lib/node_modules/ethereumjs-testrpc/build/cli.node.js
+ ethereumjs-testrpc@4.1.3
+ embark@2.5.2
updated 2 packages in 42.504s


   ╭─────────────────────────────────────╮
   │                                     │
   │   Update available 5.3.0 → 5.4.2    │
   │     Run npm i -g npm to update      │
   │                                     │
   ╰─────────────────────────────────────╯

localhost:~ yuechunli$ 
```


## 2. Embark framework Hello World

### 2.1 启动服务器和控制器  

`Embark framework`包含最基本能够用来部署并让我们容易理解它如何运作的`demo`。打开终端，首先我们创建一个一个文件夹`embark_demo`，切换到`embark_demo`文件夹里面，通过`embark demo`命令来创建`Embark framework`的初始化项目。

```
localhost:SmartContractDemo yuechunli$ ls
BloggerCoin	EncryptedToken	HelloWorld
localhost:SmartContractDemo yuechunli$ mkdir embark_demo
localhost:SmartContractDemo yuechunli$ cd embark_demo/
localhost:embark_demo yuechunli$ embark demo
Initializing Embark Template....
Installing packages.. this can take a few seconds
Init complete

App ready at embark_demo
-------------------
Next steps:
-> cd embark_demo
-> embark blockchain or embark simulator
open another console in the same directory and run
-> embark run
For more info go to http://github.com/iurimatias/embark-framework
localhost:embark_demo yuechunli$ ls
embark_demo
localhost:embark_demo yuechunli$ cd embark_demo/
localhost:embark_demo yuechunli$ ls
app			embark.json		package.json
chains.json		node_modules		test
config			package-lock.json
localhost:embark_demo yuechunli$ 
```

为了运行这个demo，我们得先通过`embark simulator`启动`simulator`。

```
localhost:embark_demo yuechunli$ embark simulator
localhost:embark_demo yuechunli$ embark simulator
EthereumJS TestRPC v6.0.1 (ganache-core: 2.0.0)

Available Accounts
==================
(0) 0x32b083632f44917e2e9125c3025a120c97bb9f8c
(1) 0xe38af4e162a40d27c6f15e754be1a940ca6b41ab
(2) 0x19f321c2a9f531cd11b45be37ea12b835390d816
(3) 0x982eadda586d29e13b38d745d45dccd931a1b471
(4) 0xb0b4422bfdf431f58df48d0645e8d933d9c7f81d
(5) 0xd69080b8a458a3fbd3f354b16b2a5964178a2579
(6) 0x87b394b8f8d7530cd677fdb8fb785aed0431146e
(7) 0xc1da7d151ed95b616f8b67ed5ce4774525455ee0
(8) 0xa1878496046ff767401cb768e352c407c7f53018
(9) 0xd16faa875634d4fe88333555cd7dc9e8c22f3e2e

Private Keys
==================
(0) a70c22b2e6fe5f44ca15b44883333ad551e22608953a5f16e44a8b616e151360
(1) 73a0e9cf90828d1099e5c5ac513cb18b5b804be7278aebf9bb2db5602d0e36da
(2) 1e083df4a9aa021e64b52318fd64ec8d5959018b2244856466dc5ea102fa2cf8
(3) 74afaab038ec34c8ac18559a09888dbd4e057fdfa9f41e99a99bbb1fceb32bc7
(4) 3f27399b396c4d4cacfca45bffb0ce67f1f141bc5202bcd38bf66a9f8213c922
(5) 36e4b3bfab27957163165aa185fed01134d90a41d2dbaed88a9eeff7c7be4583
(6) 94292f49bd516fecd6bf775b5057cd215bb159efbc808b4cf0cf04afcd43418b
(7) d9d43481879b1f130379c26df5a32ded19aabe3812e46ba52ef8b163f858ce40
(8) 61679bc6a888d5d76af56ffcfcd7383befd44032254e35272e1f227f12dd4016
(9) a8ac9f59c020136da2933424bf0f196d0a42e4a7f5d1ec8b973ff4d8c6b68a6f

HD Wallet
==================
Mnemonic:      soap idle agree episode breeze utility page drive dumb vibrant repeat potato
Base HD Path:  m/44'/60'/0'/0/{account_index}

Listening on localhost:8545**
```

**`simulator`有两个优势**：

- 第一，它将在你的计算机上创建一个区块链(blockchain)，因此当你需要部署合约或者做其他交易时，你的计算机将能够挖矿(mine)。
- 第二，你不需要下载所有的`Ethereum`区块链，这样能节省你的空间。


接下来我们重启一个终端通过`embark run`命令来运行程序。

```
localhost:embark_demo yuechunli$ embark run
```

![embark run](http://om1c35wrq.bkt.clouddn.com/embark%20run%20demo.png)


**元素解释：**

1. 当前部署的合约和地址列表显示在`Embark`演示的demo中只有一个简单的合约`SimpleStorage`，`SimpleStorage`合约具有简单的任务：存储一个值，并使这个值可从外部读取。
2. `http://localhost:8000`为当前UI前端的地址和端口。
3. 可以和你合约进行交互的控制台。


### 2.2 终端读取和修改`storedData`的值

**让我们用atom打开demo看看合约代码：**`simple_storage.sol`文件在`app/contracts`文件夹下面。

![Embark 演示demo](http://om1c35wrq.bkt.clouddn.com/simple_storage_sol.png)


在`SimpleStorage`这个合约中，有一个`storedData`状态变量用于存储一个`uint无符号整型的值。`因为前面我们已经启动了服务，并且已经将合约部署到了本地测试网络，所以我们可以切换到终端，在终端中通过`SimpleStorage.get()`获取`storedData`的值，通过`SimpleStorage.set(88)`修改状态变量的值，操作如下图所示:

![](http://om1c35wrq.bkt.clouddn.com/Snip20171122_10.png)


### 2.3 Web端获取`storedData`的值

浏览项目，不难发现，在`app`这个文件夹中，除了`contracts`文件夹外，还有`css`、`images`、`js`等文件夹，它们包含了和区块链交互的`web app`的源码。在浏览器中打开`http://localhost:8000`看看`Embark`demo`web`端的效果。

**Note:**默认端口为`8000`，如果想修改端口可以到`config/webserver.json`文件里面进行修改。

![](http://om1c35wrq.bkt.clouddn.com/WX20170928-205437@2x.png)


下图是`WebApp`效果图：

![](http://om1c35wrq.bkt.clouddn.com/embark-yanshi.gif)

默认的初始值为`100`，如果想在Web端点击`Get Value`按钮获取值，当前的`MetaMask`钱包必须和本地的区块链测试网络一致，本地测试网络的RPC地址和端口为：`localhost:8545`，所以需要在`MetaMask`钱包中将测试网络切换到`localhost:8545`，然后点击`Get Value`按钮，即可获得存储到区块链上的`storedData`的值。【PS：从区块链获取值不需要花费gas，但是MetaMask钱包网络必须和区块链部署的网络是同一个测试网络。】


### 2.4 Web端点击`Set Value`修改`storedData`的值

目前我们的`MetaMask`的`localhost:8545`测试网络中，钱包地址中默认的以太币为`0`，如下图所示：

![](http://om1c35wrq.bkt.clouddn.com/Snip20171122_11.png)

如果我们想在`Web端`通过`Set Value`按钮去修改`storedData`的值，我们的`MetaMask`账号里面必须得有以太币，那么，那么，那么......

**如何获取以太币呢？**

在我们终端中通过`embark simulator`启动时，会默认分配`10`个钱包地点，并且每个账号里面的余额都默认为`100`，我们在终端查询一下先：

![](http://om1c35wrq.bkt.clouddn.com/Snip20171122_12.png)

下一步拷贝我们`MetaMask`里面的钱包地址，在控制台执行下面的命令。

```
count = web3.toWei(60,'ether');

web3.eth.sendTransaction({from: '0xe38af4e162a40d27c6f15e754be1a940ca6b41ab',to: '0xF055775eBD516e7419ae486C1d50C682d4170645',value: count});
```
![](http://om1c35wrq.bkt.clouddn.com/Snip20171122_16.png)

**⚠️：**我们在终端查询`0xe38af4e162a40d27c6f15e754be1a940ca6b41ab`地址余额时，它比`40`个以太币要少一些，原因是因为转账需要花手续费。

![](http://om1c35wrq.bkt.clouddn.com/Snip20171122_16%20%281%29.png)

如上图所示，`0xF055775eBD516e7419ae486C1d50C682d4170645`账号已充值`60 ether`。

接下来我们就可以在`Web`端调用`Set Value`来修改`storedData`的值，我们在Web端将其值修改为`520`，然后再在终端查看一下`storedData`的值是否被修改并且同步。

![](http://om1c35wrq.bkt.clouddn.com/xiugaivalue.gif)

## 3. 小结

本篇文章主要是带大家初步认识`Embark framework`，通过本篇文章，相信大家对`Embark framework`框架有了初步的认识，知道如何安装`Embark framework`环境，如何启动模拟器，如何运行程序，如何在控制台和合约实例交互。


## 4. 参考文档

- `https://solidity.readthedocs.io`
- `ethereumbuilders.gitbooks.io/guide/content/en/ethereum_javascript_api.html`
- `web3js.readthedocs.io/en/1.0/index.html`
- `https://ethereumdev.io/getting-started-with-embark-framework`
- `http://embark.readthedocs.io/en/2.5.2`

## 5. 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)

