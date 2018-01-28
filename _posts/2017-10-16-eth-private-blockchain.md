---
layout: post
title: "以太坊私网建立 (3) - 通过创世区块（genesis block）来初始化区块链"
date: 2017-10-16
description: "以太坊私网建立 (3) - 通过创世区块（genesis block）来初始化区块链私有链"
tag: 以太坊 Ethereum 私链
keywords: "Ethereum genesis block 私链"
---


> [孔壹学院：国内区块链职业教育领先品牌](http://www.kongyixueyuan.com)
> 
> 作者：黎跃春，区块链、高可用架构工程师
> 微信：liyc1215  QQ群：348924182  博客：http://liyuechun.org

- [从零构建以太坊私链免费公开课视频](http://www.kongyixueyuan.com/course/5145)
- [以太坊(Ethereum)私链建立 、合约编译、部署完全教程(1)](http://liyuechun.org/2017/10/14/eth-private-blockchain/)
- [以太坊私网建立 (2) - 同一台电脑／不同电脑运行多个节点](http://liyuechun.org/2017/10/15/eth-private-blockchain/)
- [以太坊私网建立 (3) - 通过创世区块来初始化区块链](http://liyuechun.org/2017/10/16/eth-private-blockchain/)


## genesis block file example

```
{
  "config": {
    "chainId": 15,
    "homesteadBlock": 0,
    "eip155Block": 0,
    "eip158Block": 0
  },
  "difficulty": "4",
  "gasLimit": "2100000",
  "alloc": {
    "7df9a875a174b3bc565e6424a0050ebc1b2d1d82": {
      "balance": "300000"
    },
    "f41c74c9ae680c1aa78f42e5647a62f353b7bdde": {
      "balance": "400000"
    }
  }
}
```

**config, difficulty, gasLimit, alloc**创始区块文件中，这几个文件是必须的。


## Start Coding

### 创建创世区块文件

```
/Users/liyuechun/Desktop/1015/townodes
liyuechun:townodes yuechunli$ cat > genesis.json
{
  "config": {
    "chainId": 15,
    "homesteadBlock": 0,
    "eip155Block": 0,
    "eip158Block": 0
  },
  "difficulty": "4",
  "gasLimit": "2100000",
  "alloc": {
    "7df9a875a174b3bc565e6424a0050ebc1b2d1d82": {
      "balance": "300000"
    },
    "f41c74c9ae680c1aa78f42e5647a62f353b7bdde": {
      "balance": "400000"
    }
  }
}
^C
liyuechun:townodes yuechunli$ cat genesis.json 
{
  "config": {
    "chainId": 15,
    "homesteadBlock": 0,
    "eip155Block": 0,
    "eip158Block": 0
  },
  "difficulty": "4",
  "gasLimit": "2100000",
  "alloc": {
    "7df9a875a174b3bc565e6424a0050ebc1b2d1d82": {
      "balance": "300000"
    },
    "f41c74c9ae680c1aa78f42e5647a62f353b7bdde": {
      "balance": "400000"
    }
  }
}
liyuechun:townodes yuechunli$ 
```


### 初始化区块链，并且创建一个文件夹来存储区块数据

```
liyuechun:townodes yuechunli$ geth init genesis.json --datadir blockchainData
WARN [10-15|07:50:09] No etherbase set and no accounts found as default 
INFO [10-15|07:50:09] Allocated cache and file handles         database=/Users/liyuechun/Desktop/1015/townodes/blockchainData/geth/chaindata cache=16 handles=16
INFO [10-15|07:50:09] Writing custom genesis block 
INFO [10-15|07:50:09] Successfully wrote genesis state         database=chaindata                                                            hash=884fa3…0409fd
INFO [10-15|07:50:09] Allocated cache and file handles         database=/Users/liyuechun/Desktop/1015/townodes/blockchainData/geth/lightchaindata cache=16 handles=16
INFO [10-15|07:50:09] Writing custom genesis block 
INFO [10-15|07:50:09] Successfully wrote genesis state         database=lightchaindata                                                            hash=884fa3…0409fd
liyuechun:townodes yuechunli$ 
```

### 打开终端

```
geth --networkid 123 --datadir blockchainData  console
```

### 警告

> WARN [10-15|07:53:09] No etherbase set and no accounts found as default 

出现这个警告的原因是因为，我们创世区块没有创建任何账号。

### 查看余额

```
> eth.getBalance("7df9a875a174b3bc565e6424a0050ebc1b2d1d82")
300000
> 
```

### 开始 mining

```
> miner.start()
INFO [10-15|07:57:15] Updated mining threads                   threads=0
INFO [10-15|07:57:15] Transaction pool price threshold updated price=18000000000
ERROR[10-15|07:57:15] Cannot start mining without etherbase    err="etherbase address must be explicitly specified"
Error: etherbase missing: etherbase address must be explicitly specified
    at web3.js:3104:20
    at web3.js:6191:15
    at web3.js:5004:36
    at <anonymous>:1:1

> 
```

如果你直接挖矿，会出现上面的错误。需要设置一个挖矿的账号。

```
> miner.setEtherbase("7df9a875a174b3bc565e6424a0050ebc1b2d1d82")
true
> 
```

接下来开始挖矿。

```
> miner.start()
INFO [10-15|07:58:46] Updated mining threads                   threads=0
INFO [10-15|07:58:46] Transaction pool price threshold updated price=18000000000
INFO [10-15|07:58:46] Starting mining operation 
null
> INFO [10-15|07:58:46] Commit new mining work                   number=1 txs=0 uncles=0 elapsed=159.05µs
INFO [10-15|07:58:48] Successfully sealed new block            number=1 hash=cf9d01…e0ec7a
INFO [10-15|07:58:48] 🔨 mined potential block                  number=1 hash=cf9d01…e0ec7a
INFO [10-15|07:58:48] Commit new mining work                   number=2 txs=0 uncles=0 elapsed=107.264µs
INFO [10-15|07:58:48] Successfully sealed new block            number=2 hash=1619e2…814e17
INFO [10-15|07:58:48] 🔨 mined potential block                  number=2 hash=1619e2…814e17
INFO [10-15|07:58:48] Commit new mining work                   number=3 txs=0 uncles=0 elapsed=107.323µs
INFO [10-15|07:58:50] Successfully sealed new block            number=3 hash=3c1363…683a88
INFO [10-15|07:58:50] 🔨 mined potential block                  number=3 hash=3c1363…683a88
INFO [10-15|07:58:50] Commit new mining work                   number=4 txs=0 uncles=0 elapsed=113.813µs
INFO [10-15|07:58:51] Successfully sealed new block            number=4 hash=f5878d…646398
INFO [10-15|07:58:51] 🔨 mined potential block                  number=4 hash=f5878d…646398
INFO [10-15|07:58:51] Commit new mining work                   number=5 txs=0 uncles=0 elapsed=110.545µs
INFO [10-15|07:58:51] Successfully sealed new block            number=5 hash=0dba65…e37ab9
INFO [10-15|07:58:51] 🔨 mined potential block                  number=5 hash=0dba65…e37ab9
INFO [10-15|07:58:51] Commit new mining work                   number=6 txs=0 uncles=0 elapsed=92.426µs
INFO [10-15|07:58:51] Successfully sealed new block            number=6 hash=703015…47e9f9
INFO [10-15|07:58:51] 🔗 block reached canonical chain          number=1 hash=cf9d01…e0ec7a
INFO [10-15|07:58:51] 🔨 mined potential block                  number=6 hash=703015…47e9f9
INFO [10-15|07:58:51] Mining too far in the future             wait=2s
INFO [10-15|07:58:53] Commit new mining work                   number=7 txs=0 uncles=0 elapsed=2.001s
INFO [10-15|07:58:53] Successfully sealed new block            number=7 hash=98e5b7…8d2d1a
INFO [10-15|07:58:53] 🔗 block reached canonical chain          number=2 hash=1619e2…814e17
INFO [10-15|07:58:53] 🔨 mined potential block                  number=7 hash=98e5b7…8d2d1a
INFO [10-15|07:58:53] Commit new mining work                   number=8 txs=0 uncles=0 elapsed=171.147µs
INFO [10-15|07:58:54] Successfully sealed new block            number=8 hash=3a9142…fee188
```

## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)

