---
layout: post
title: "『0018』 - Solidity Types - Solidity 结构体（Structs）"
date: 2017-10-10
description: "Solidity Types - Solidity 结构体（Structs），Structs init，Structs 初始化"
tag: Solidity系列
keywords: "Structs init，Structs 初始化，Solidity 结构体（Structs）"
---


> [孔壹学院：国内区块链职业教育领先品牌](http://www.kongyixueyuan.com)
> 
> 作者：黎跃春，区块链、高可用架构工程师
> 微信：liyc1215  QQ群：348924182  博客：http://liyuechun.org

## 自定义结构体


```
pragma solidity ^0.4.4;

contract Students {
    
    struct Person {
        uint age;
        uint stuID;
        string name;
    }

}
```

`Person`就是我们自定义的一个新的结构体类型，结构体里面可以存放任意类型的值。

## 初始化一个结构体

**初始化一个`storage`类型的状态变量。**

- 方法一

```
pragma solidity ^0.4.4;

contract Students {
    
    struct Person {
        uint age;
        uint stuID;
        string name;
    }

    Person _person = Person(18,101,"liyuechun");

}
```

- 方法二

```
pragma solidity ^0.4.4;

contract Students {
    
    struct Person {
        uint age;
        uint stuID;
        string name;
    }

    Person _person = Person({age:18,stuID:101,name:"liyuechun"});

}
```


**初始化一个`memory`类型的变量。**

```
pragma solidity ^0.4.4;

contract Students {
    
    struct Person {
        uint age;
        uint stuID;
        string name;
    }
    
    function personInit() {
        
        Person memory person = Person({age:18,stuID:101,name:"liyuechun"});
    }
}
```

## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


