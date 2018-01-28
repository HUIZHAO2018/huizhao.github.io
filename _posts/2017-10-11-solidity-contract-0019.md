---
layout: post
title: "『0019』 - Solidity Types - Solidity 字典／映射（Mappings）"
date: 2017-10-11
description: "Solidity Types - Solidity 字典／映射（Mappings），solidity mapping，soliidiy 字典 案例"
tag: Solidity系列
keywords: "Solidity 字典／映射（Mappings）"
---


> [孔壹学院：国内区块链职业教育领先品牌](http://www.kongyixueyuan.com)
> 
> 作者：黎跃春，区块链、高可用架构工程师
> 微信：liyc1215  QQ群：348924182  博客：http://liyuechun.org

## 语法

```
mapping(_KeyType => _ValueType)
```

`字典／映射`其实就是一个一对一键值存储关系。

**举个例子：**

**{age: 28, height: 172, name: liyuechun, wx: liyc1215}**

这就是一个映射，满足`_KeyType => _ValueType`之间的映射关系，`age`对应一个`28`的值，`height`对应`160`，`name`对应`liyuechun`, `wx`对应`liyc1215`。

**PS：**同一个映射中，可以有多个相同的**值**，但是**键**必须具备唯一性。

## 案例

```
pragma solidity ^0.4.4;

contract MappingExample {
    
    // 测试账号
    
    // 0xca35b7d915458ef540ade6068dfe2f44e8fa733c
    
    // 0x14723a09acff6d2a60dcdf7aa4aff308fddc160c
    
    // 0x4b0897b0513fdc7c541b6d9d7e929c4e5364d2db
    
    mapping(address => uint)  balances;

    function update(address a,uint newBalance) public {
        balances[a] = newBalance;
    }
    
    // {0xca35b7d915458ef540ade6068dfe2f44e8fa733c: 100,0x14723a09acff6d2a60dcdf7aa4aff308fddc160c: 200,0x4b0897b0513fdc7c541b6d9d7e929c4e5364d2db: 300 }
    
    function searchBalance(address a) constant public returns (uint) {
        
        return balances[a];
    }
}
```

## 结构体和字典综合案例


```
pragma solidity ^0.4.4;

contract CrowdFunding {
    // Defines a new type with two fields.
    struct Funder {
        address addr;
        uint amount;
    }

    struct Campaign {
        address beneficiary;
        uint fundingGoal;
        uint numFunders;
        uint amount;
        mapping (uint => Funder) funders;
    }

    uint numCampaigns;
    mapping (uint => Campaign) campaigns;

    function newCampaign(address beneficiary, uint goal) public returns (uint campaignID) {
        campaignID = numCampaigns++; // campaignID is return variable
        // Creates new struct and saves in storage. We leave out the mapping type.
        campaigns[campaignID] = Campaign(beneficiary, goal, 0, 0);
    }

    function contribute(uint campaignID) public payable {
        Campaign storage c = campaigns[campaignID];
        // Creates a new temporary memory struct, initialised with the given values
        // and copies it over to storage.
        // Note that you can also use Funder(msg.sender, msg.value) to initialise.
        c.funders[c.numFunders++] = Funder({addr: msg.sender, amount: msg.value});
        c.amount += msg.value;
    }

    function checkGoalReached(uint campaignID) public returns (bool reached) {
        Campaign storage c = campaigns[campaignID];
        if (c.amount < c.fundingGoal)
            return false;
        uint amount = c.amount;
        c.amount = 0;
        c.beneficiary.transfer(amount);
        return true;
    }
}
```

## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)

