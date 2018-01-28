---
layout: post
title: "以太坊私网建立 (2) - 同一台电脑／不同电脑运行多个节点"
date: 2017-10-15
description: "以太坊私网建立 (2) - 同一台电脑／不同电脑运行多个节点，rpcport，port"
tag: 以太坊 Ethereum 私链
keywords: "以太坊私网建立 (2) - 同一台电脑／不同电脑运行多个节点"
---


> [孔壹学院：国内区块链职业教育领先品牌](http://www.kongyixueyuan.com)
> 
> 作者：黎跃春，区块链、高可用架构工程师
> 微信：liyc1215  QQ群：348924182  博客：http://liyuechun.org

- [从零构建以太坊私链免费公开课视频](http://www.kongyixueyuan.com/course/5145)
- [以太坊(Ethereum)私链建立 、合约编译、部署完全教程(1)](http://liyuechun.org/2017/10/14/eth-private-blockchain/)
- [以太坊私网建立 (2) - 同一台电脑／不同电脑运行多个节点](http://liyuechun.org/2017/10/15/eth-private-blockchain/)
- [以太坊私网建立 (3) - 通过创世区块来初始化区块链](http://liyuechun.org/2017/10/16/eth-private-blockchain/)

接下来我们将在我们的私有网络连接两个节点。

## 先思考两个问题

- 决定存储区块链数据的目录
- 选择网络id，默认1为主网

为了在同一台机器能够运行两个节点，我们需要为不同的节点设置不同的`port`和`rpcport`。

## 开始编码

```
liyuechun:Desktop yuechunli$ cd 1015/
liyuechun:1015 yuechunli$ mkdir test
liyuechun:1015 yuechunli$ cd test/
liyuechun:test yuechunli$ 
```

## 查看你的ip地址

```
liyuechun:~ yuechunli$ ifconfig|grep netmask|awk '{print $2}' 
127.0.0.1
192.168.1.5
10.20.0.8
```

## 打开节点

```
liyuechun:test yuechunli$ geth --networkid 123 --datadir data1 --rpc --rpcaddr 192.168.1.5 --rpcport 8989 --port 3000 console
WARN [10-15|08:20:18] No etherbase set and no accounts found as default 
INFO [10-15|08:20:18] Starting peer-to-peer node               instance=Geth/v1.7.1-stable-05101641/darwin-amd64/go1.9.1
INFO [10-15|08:20:18] Allocated cache and file handles         database=/Users/liyuechun/Desktop/1015/test/hi/geth/chaindata cache=128 handles=1024
INFO [10-15|08:20:18] Writing default main-net genesis block 
INFO [10-15|08:20:18] Initialised chain configuration          config="{ChainID: 1 Homestead: 1150000 DAO: 1920000 DAOSupport: true EIP150: 2463000 EIP155: 2675000 EIP158: 2675000 Byzantium: 4370000 Engine: ethash}"
INFO [10-15|08:20:18] Disk storage enabled for ethash caches   dir=/Users/liyuechun/Desktop/1015/test/hi/geth/ethash count=3
INFO [10-15|08:20:18] Disk storage enabled for ethash DAGs     dir=/Users/liyuechun/.ethash                          count=2
INFO [10-15|08:20:18] Initialising Ethereum protocol           versions="[63 62]" network=123
INFO [10-15|08:20:18] Loaded most recent local header          number=0 hash=d4e567…cb8fa3 td=17179869184
INFO [10-15|08:20:18] Loaded most recent local full block      number=0 hash=d4e567…cb8fa3 td=17179869184
INFO [10-15|08:20:18] Loaded most recent local fast block      number=0 hash=d4e567…cb8fa3 td=17179869184
INFO [10-15|08:20:18] Regenerated local transaction journal    transactions=0 accounts=0
INFO [10-15|08:20:18] Starting P2P networking 
INFO [10-15|08:20:20] UDP listener up                          self=enode://032ff589bae471ab0884cce696a632fcb44ec9b7c33dfa5c06e547de099ed116360e74172c0398396588e6a374bf0dd7da1558e0a4899e9670d2ce7a1967cf11@[::]:3000
INFO [10-15|08:20:20] RLPx listener up                         self=enode://032ff589bae471ab0884cce696a632fcb44ec9b7c33dfa5c06e547de099ed116360e74172c0398396588e6a374bf0dd7da1558e0a4899e9670d2ce7a1967cf11@[::]:3000
INFO [10-15|08:20:20] IPC endpoint opened: /Users/liyuechun/Desktop/1015/test/hi/geth.ipc 
INFO [10-15|08:20:20] HTTP endpoint opened: http://192.168.1.4:8545 
Welcome to the Geth JavaScript console!

instance: Geth/v1.7.1-stable-05101641/darwin-amd64/go1.9.1
 modules: admin:1.0 debug:1.0 eth:1.0 miner:1.0 net:1.0 personal:1.0 rpc:1.0 txpool:1.0 web3:1.0

> 
```





## 多节点连接



`Enode url`其实就是和另外一个节点互动的唯一的`id`。

#### **节点A**

```
> admin.nodeInfo.enode 
"enode://032ff589bae471ab0884cce696a632fcb44ec9b7c33dfa5c06e547de099ed116360e74172c0398396588e6a374bf0dd7da1558e0a4899e9670d2ce7a1967cf11@[::]:3000"
> 
```

`[::]`等价于`192.168.1.5`，`3000`是端口号。





#### **节点B**

如果是同一台电脑，需要设置不同的`rcpport`和不同的`port`。如果是不同的电脑，直接重复上面节点A的步骤即可。

```
> admin.addPeer("enode://032ff589bae471ab0884cce696a632fcb44ec9b7c33dfa5c06e547de099ed116360e74172c0398396588e6a374bf0dd7da1558e0a4899e9670d2ce7a1967cf11@[::]:3000")
> true
```

## 查看节点

```
admin.peers 
```

####  查看连接节点数

```
> web3.net.peerCount
1
>
```

## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


