---
layout: post
title: "『0012』 - Solidity Types - 字符串(String Literals)"
date: 2017-10-04
description: "solidity string 字符串其实它是一个特殊的字节数组，不过在solidity string中没有length方法，还有不可以通过s[k]的方法获取或者修个某个字符，如果需要修改某个索引位置的字符，需要转换为字节数组来修改"
tag: Solidity系列
keywords: "solidity string 教程"
---


> 孔壹学院：国内区块链职业教育领先品牌
> 
> 孔壹学院创办于2016年12月09日，专注于区块链产品底层研发和职业教育培训，致力于打造国内一流的集`线上教育`、`线下周末班`、`脱产班`、`企业内训`、`区块链产品外包`、`区块链创新社区(技术／企业招聘)` 和 `高校区块链专业共建`为一体的的综合性区块链商学院。

## 案例

字符串可以通过`""`或者`''`来表示字符串的值，Solidity中的`string`字符串不像`C语言`一样以`\0`结束，比如**我的微信号**`liyc1215`这个字符串的长度就为我们所看见的字母的个数，它的长度为`8`。

```
pragma solidity ^0.4.4;

contract StringLiterals{ 
    
    string  _name; // 状态变量
    
    //构造函数
    function StringLiterals() {
        // 将我的微信号初始化
        _name = "liyc1215";
    }
    
    // set方法
    function setString(string name) {
        
        _name = name;
    }
    
    // get方法
    function name() constant returns (string) {
        
        return _name;
    }
    
}
```

**备注：**`string`字符串不能通过`length`方法获取其长度。

### 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


