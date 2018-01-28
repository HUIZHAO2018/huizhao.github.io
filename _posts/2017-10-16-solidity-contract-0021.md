---
layout: post
title: "『0021』- 单位（Units） 和 全局变量（Globally Available Variables）"
date: 2017-10-16
description: "单位（Units） 和 全局变量（Globally Available Variables）,Ether Units,Time Units,特殊的变量和函数和函数,区块和交易属性,错误处理"
tag: Solidity系列
keywords: "assert() require() revert()，block.blockhash block.coinbase msg.data msg.gas tx.gasprice block.gaslimit msg.sig msg.data "
---

> [孔壹学院：国内区块链职业教育领先品牌](http://www.kongyixueyuan.com)
> 
> 作者：黎跃春，区块链、高可用架构工程师
> 微信：liyc1215  QQ群：348924182  博客：http://liyuechun.org

## Ether Units


一个整数的后面可以跟一个单位，ether，finney，szabo或者wei。

**他们的单位换算如下：**

- `1 ether = 1000 finney`
- `1 ether = 1000000 szabo`
- `1 ether = 10 ** 18 wei`

```
pragma solidity ^0.4.4;

contract C {
    
    uint a = 1 ether;
    uint b = 10 ** 18 wei;
    uint c = 1000 finney;
    uint d = 1000000 szabo;
    
    function isTrueAEquleToB() view public returns (bool) {
        
        return a == b;
    }
    
    function isTrueAEquleToC() view public returns (bool) {
        
        return a == c;
    }
    
    function isTrueAEquleToD() view public returns (bool) {
        
        return a == d;
    }

}
```

![](http://om1c35wrq.bkt.clouddn.com/WX20171031-170152@2x.png)


## Time Units

时间的单位有`seconds`, `minutes`, `hours`, `days`, `weeks` 和 `years`。换算如下：

- `1 == 1 seconds`
- `1 minutes == 60 seconds`
- `1 hours == 60 minutes`
- `1 days == 24 hours`
- `1 weeks == 7 days`
- `1 years == 365 days`

```
pragma solidity ^0.4.4;

contract C {
    
    // 1 == 1 seconds
    // 1 minutes == 60 seconds
    // 1 hours == 60 minutes
    // 1 days == 24 hours
    // 1 weeks == 7 days
    // 1 years == 365 days
    
    function test1() pure public returns (bool) {
        
        return 1 == 1 seconds;
    }
    
    function test2() pure public returns (bool) {
        
        return 1 minutes == 60 seconds;
    }
    
    function test3() pure public returns (bool) {
        
        return 1 hours == 60 minutes;
    }
    
    function test4() pure public returns (bool) {
        
        return 1 days == 24 hours;
    }
    
    function test5() pure public returns (bool) {
        
        return 1 weeks == 7 days;
    }
    
    function test6() pure public returns (bool) {
        
        return 1 years == 365 days;
    }
}
```

![](http://om1c35wrq.bkt.clouddn.com/WX20171031-174618@2x.png)


## 特殊的变量和函数和函数

有一些特殊的变量和函数存在于全局的命名空间以提供区块相关信息。

### 区块和交易属性

- `block.blockhash(uint blockNumber) returns (bytes32):` 某个区块的区块链hash值
- `block.coinbase (address):` 当前区块的挖矿地址
- `block.difficulty (uint):` 当前区块的难度
- `block.gaslimit (uint):` 当前区块的`gaslimit`
- `block.number (uint):` 当前区块编号
- `block.timestamp (uint):` 当前区块时间戳
- `msg.data (bytes):` 参数
- `msg.gas (uint):` 剩余的`gas`
- `msg.sender (address):` 当前发送消息的地址
- `msg.sig (bytes4):` 方法ID
- `msg.value (uint):` 伴随消息附带的以太币数量
- `now (uint):` 时间戳，等价于`block.timestamp (uint)`
- `tx.gasprice (uint):` 交易的gas单价
- `tx.origin (address):`交易发送地址


### 错误处理

- `assert(bool condition)`：不满足条件，将抛出异常

- `require(bool condition)`：不满足条件，将抛出异常

- `revert()` 抛出异常

在`Solidity 0.4.10`版本之前，使用`throw`来处理异常。如下所示：

```
contract HasAnOwner {

    address owner;
    
    function useSuperPowers(){ 
        if (msg.sender != owner) { 
            throw; 
        }
    }
}
```

在`Solidity 0.4.10`版本之后，我们通常如下使用：

- `if(msg.sender != owner) { revert(); }`
- `assert(msg.sender == owner);`
- `require(msg.sender == owner);`


## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)

