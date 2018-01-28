---
layout: post
title: "教练，我“只”想学`solidity`"
date: 2017-09-03
description: "Coinbase CEO `Brian Armstrong` 透过他的推特（Twitter）宣布推出一个名为「Token」的新产品，这个产品是一个手机聊天 APP，应用底层是利用以太坊来建设，使用者除了可以在上面发讯息，还可以传送 ETH 币给別人。
"
tag: Solidity
keywords: Solidity 智能合约,MetaMask,以太坊,Ethereum,browser-solidity
---   

`Smart Contract`(智能合约)才是`Dapp`(去中心化应用)的核心，不是`nodejs`。

如果你想要研究Solidity，但沒碰过nodejs，那么本篇是专门为你而写的。只需要使用网页面的Solidity编辑器([https://ethereum.github.io/browser-solidity](https://ethereum.github.io/browser-solidity))，以及安装MetaMask就可以开心的编写、部署、测试智能合约。


想写这篇文章的原因是这样的，当初我想学如何写`Solidity`，作为一个初学者大概就是直接安装`Ethereum`官网提供的`Wallet`，使用它内建的编辑器来开发，但是部署的时候会经常失败，也找不到原因，区块同步又非常缓慢，实在是不太好用。


耗费一番功夫google之后，发现`testrpc + truffle`也是不错的开发工具组合，然而我就是这个时候开始被nodejs绑架的XD，写完`contract`之后要再花费很多力气写nodejs才能测试啊。不管你的Solidity学习路径如何，总是会碰到nodejs，实在是一件非常奇怪的事情。


## 1. 安装MetaMask

这是一个Chrome的套件，所以你要先安装Chrome，再安装MetaMask，裝完之后Chrome右上角就会有只狐狸跑出來，如下图所示。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_24.png)

点击红色箭头指向的图片，一步一步注册账号。

- 第一步，Accept

- 第二步，输入密码

- 第三步，拷贝恢复账号的安全码，一共是12个单词，切记，这一步很重要，一定要把这个安全码记录下来方便恢复账号。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_25.png)

- 下面是安装完后的界面效果图
    - 可以很方便的查看钱包地址
    - 将地址转换为二维码
    - 买入以太币
    - 发送以太币

![](http://om1c35wrq.bkt.clouddn.com/METAMASK.gif)


## 2. 配置MetaMask的Test Net

- 从Main Ethereum Network切换到Ropsten Test Network
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_41.png)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_42.png)

- 购买以太币

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_43.png)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_44.png)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_48.png)


![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_56.png)

## 3. 使用网页版的Solidity编辑器

#### step 1. 打开`browser-solidity`网页[https://ethereum.github.io/browser-solidity](https://ethereum.github.io/browser-solidity/)。

第一次打开网页会默认载入一个案例，如下入所示：

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_26.png)


#### step 2. 为了容易示范首先换个简单的案例，然后确认有选择Injected Web3选项，之后按下Create就会自动通过MetaMask发送部署Contract的交易。


拷贝如下代码，替换掉原代码：

```js
pragma solidity ^0.4.11;

contract SimpleStorage {
    uint data;
    
    function setData(uint x) {
        
        data = x;
    }
    
    function getData() constant returns (uint) {
        
        return data;
    }
}
```

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_28.png)

点击Create按钮后会弹出MetaMask界面，如下图所示:

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_49.png)

接下来点击SUBMIT按钮，在下图中，本次部署失败，如下图所示：
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_51.png)

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_50.png)

重新运行程序，点击Create，重新部署，下图是合约部署成功：

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_54.png)




#### step 3. 回到browser-solidity，就可以看到多了两个contract定义的function可以使用，constant function可以直接使用，就像下面的图中的get，其他的function一样会通过MetaMask发出交易，如下面图的set。


![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_59.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_60.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_62.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_64.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_65.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_67.png)


#### 补充：在browser-solidity下入中的value位置可以设定要转发多少ether給contract，这可以用来测试payable function。

![](http://om1c35wrq.bkt.clouddn.com/Snip20170903_68.png)


