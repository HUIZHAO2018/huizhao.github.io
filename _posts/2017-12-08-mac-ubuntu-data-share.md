---
layout: post
title: "Fabric 开发环境配置（2） - Ubuntu虚拟机和Mac/Windows主机如何实现文件共享"
date: 2017-12-08
description: "本篇文章主要为大家介绍了VirtualBox虚拟机网络设置`NAT`和`Bridged Adapter 桥接模式`之间的区别，如何配置`Bridged Adapter 桥接模式`以实现主机和虚拟机之间在同一个局域网。`Samba`服务器安装配置，数据共享相关设置。"
tag: Fabric
keywords: "Fabric 环境搭建 Virtual Ubuntu Mac Samba 数据共享 双向拷贝"
---

> [区块链技术视频：http://www.kongyixueyuan.com](http://www.kongyixueyuan.com)
> 
> [区块链技术博客：http://liyuechun.org](http://liyuechun.org)
> 
> 进区块链微信技术交流群，添加春哥微信：liyc1215

## 目录

- [1. VirtualBox虚拟机网络设置](#1- VirtualBox虚拟机网络设置)
    - [1.1 NAT 网络地址转换模式(NAT,Network Address Translation)](#11-NAT-网络地址转换模式NAT-Network-Address-Translation)
    - [1.2 Bridged Adapter 桥接模式](#12- Bridged-Adapter-桥接模式)
- [2. Mac/Windows和Ubuntu双向拷贝](#2- Mac/Windows和Ubuntu双向拷贝)
- [3. 文件共享](#3-文件共享)
    - [3.1 Bridged Adapter网络配置](#31-Bridged-Adapter网络配置)
    - [3.2 在Ubuntu上安装Samba服务器](#32-在Ubuntu上安装Samba服务器)
    - [3.3 设置要共享的文件夹](#33-设置要共享的文件夹)
    - [3.4 在Ubuntu上配置Samba服务器](#34-在Ubuntu上配置Samba服务器)
    - [3.5 添加共享文件](#35-添加共享文件)
    - [3.6 Mac/Windows访问Ubuntu共享文件夹](#36-Mac/Windows访问Ubuntu共享文件夹)
- [4. 小结](#4-小结)

在上一篇文档[Fabric 开发环境配置（1） - Ubuntu操作系统安装配置](http://liyuechun.org/2017/12/07/virtual_ubuntu/)中，我们介绍了`Mac/Windows`如何安装虚拟机、如何在虚拟机中安装`Ubuntu`操作系统以及如何安装配置搜狗输入法。

这篇文章，[春哥](http://liyuechun.org)将为大家介绍**Ubuntu虚拟机和Mac/Windows主机如何实现文件共享**。

## 1. VirtualBox虚拟机网络设置

**VirtualBox虚拟机网络设置一共有下面四种方式：**

1、`NAT` 网络地址转换模式`(NAT,Network Address Translation) `
2、`Bridged Adapter`桥接模式 
3、`Internal` 内部网络模式 
4、`Host-only Adapter` 主机模式 

在本篇文章中，我主要介绍`NAT`和`Bridged Adapter`两种模式。**`NAT`不能实现主机和虚拟机互通，`Bridged Adapter`可以实现主机与虚拟机互通。** 


### 1.1 NAT 网络地址转换模式(NAT,Network Address Translation) 

`NAT`模式是最简单的实现虚拟机上网的方式，你可以这样理解：`Vhost`访问网络的所有数据都是由主机提供的，`Vhost`并不真实存在于网络中，主机与网络中的任何机器都不能查看和访问到`Vhost`的存在。 

- **虚拟机与主机关系：**只能单向访问，虚拟机可以通过网络访问到主机，主机无法通过网络访问到虚拟机。 

- **虚拟机与网络中其他主机的关系：**只能单向访问，虚拟机可以访问到网络中其他主机，其他主机不能通过网络访问到虚拟机。 

- **虚拟机与虚拟机之间的关系：**相互不能访问，虚拟机与虚拟机各自完全独立，相互间无法通过网络访问彼此。 

- **虚拟机的IP、网关、DNS**
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_16.png)

- **NAT方案缺点：** 

**由于虚拟机和主机IP不在同一个网段，所以主机没办法和虚拟机实现文件共享。**



### 1.2 Bridged Adapter 桥接模式 

网桥模式是我最喜欢的用的一种模式，同时，模拟度也是相当完美。你可以这样理解，它是通过主机网卡，架设了一条桥，直接连入到网络中了。因此，它使得虚拟机能被分配到一个网络中**独立的IP**，所有网络功能完全和在网络中的真实机器一样。
 
 
- **虚拟机与主机关系：** 可以相互访问，因为虚拟机在真实网络段中有独立`IP`，主机与虚拟机处于同一网络段中，彼此可以通过各自`IP`相互访问。 

- **虚拟机与网络中其他主机关系：**可以相互访问，同样因为虚拟机在真实网络段中有独立`IP`，虚拟机与所有网络其他主机处于同一网络段中，彼此可以通过各自`IP`相互访问。
 
- **虚拟机与虚拟机关系：** 可以相互访问。

- **IP：**一般是`DHCP`分配的，与主机的`本地连接`的`IP`是同一网段的。虚拟机就能与主机互相通信。 

- **笔记本已插网线时：**（若网络中有`DHCP`服务器）主机与虚拟机会通过`DHCP`分别得到一个`IP`，这两个`IP`在同一网段。 主机与虚拟机可以`ping`通，虚拟机可以上互联网。
 
- **笔记本没插网线时：****主机与虚拟机不能通信。**主机的`本地连接`有红叉，就不能手工指定`IP`。虚拟机也不能通过`DHCP`得到`IP`地址，手工指定`IP`后，也无法与主机通信，因为主机无`IP。`
 

## 2. Mac/Windows和Ubuntu双向拷贝

默认情况下，虚拟机和主机之间的拷贝的数据不能直接粘贴，我们可以通过下面的设置来实现数据双向拷贝。

- `Virtual Box`设置

![](http://om1c35wrq.bkt.clouddn.com/WX20171208-151709@2x.png)

![](http://om1c35wrq.bkt.clouddn.com/WX20171208-151954@2x.png)

![](http://om1c35wrq.bkt.clouddn.com/install_tool.gif)

按照上面三个步骤设置完以后，接下来你就可以实现虚拟机与主机双向拷贝。

![](http://om1c35wrq.bkt.clouddn.com/%E4%B8%BB%E6%9C%BA%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%8F%8C%E5%90%91%E6%8B%B7%E8%B4%9D-iloveimg-compressed.gif)


## 3. 文件共享

由于`NAT`网络虚拟机和主机`IP`地址不在同一个网段，因此需要通过`Bridged Adapter`模式来实现虚拟机和主机在同一个局域网。

### 3.1 `Bridged Adapter`网络配置

- **连接网线,连接网线,连接网线**重要的事情别人说三遍，我习惯说四遍。

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_20.png)

- `Bridged Adapter`配置

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_23.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_24.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_25.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_26.png)

- `IP`地址查询，`ping`

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_27.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_28.png)
![](http://om1c35wrq.bkt.clouddn.com/mac_ping_ubuntu.gif)

### 3.2 在Ubuntu上安装Samba服务器

你可以很方便地在Ubuntu电脑上安装`Samba`。安装前，请先更新系统以便安装任何可用的更新。

```
$ sudo apt-get update && apt-get upgrade
```

然后按照这条命令安装`samba`和少量所需的软件包：

```
$ sudo apt-get install samba samba-common system-config-samba python-glade2 gksu
```
一旦安装完成`Samba`服务器，就可以从图形界面配置`Samba`来分享文件。

### 3.3 设置要共享的文件夹

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_35.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_36.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_37.png)

### 3.4 在Ubuntu上配置Samba服务器

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_29.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_30.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_31.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_32.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_33.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_34.png)


### 3.5 添加共享文件

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_38.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_39.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_40.png)

### 3.6 Mac/Windows访问Ubuntu共享文件夹

![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_41.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_42.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_43.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_44.png)
![](http://om1c35wrq.bkt.clouddn.com/Snip20171208_45.png)
![](http://om1c35wrq.bkt.clouddn.com/20171208173445.gif)

## 4. 小结

本篇文章主要为大家介绍了VirtualBox虚拟机网络设置`NAT`和`Bridged Adapter 桥接模式`之间的区别，如何配置`Bridged Adapter 桥接模式`以实现主机和虚拟机之间在同一个局域网。`SMB`服务器安装配置，数据共享相关设置。



## 5、技术交流

- 区块链技术交流QQ群：`348924182`
- 进微信群请加微信：`liyc1215`
- 「区块链部落」官方公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


