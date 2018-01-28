---
layout: post
title: "以太坊Parity钱包合约漏洞"
date: 2017-12-02
description: "还记得今年7月Parity钱包合约被找到漏洞，结果黑客偷走了将近150,000个以太币，会发生是因为智能合约的callback里使用了delegatecall（msg.data），这个函数会呼叫data中的函数并将msg.sender设为原呼叫函数的地址，黑客利用这一点呼叫了initWallet，这时你们可能会以为Parity应该有在initWallet设置条件阻挡黑客就不能呼叫，结果竟然是没有！所以黑客就成功并改变合约的拥有者，最后再把以太币转走，细节的部分可以看这篇文章。

Parity也在几天后修复了这个问题，修复的方式就是在init*函数加上only_uninitialized modifier判断，当m_numOwners > 0时这个函数就不能使用，这时应该会想说不会再有漏洞了吧，毕竟智能合约能操作以太币，谁知道……"
tag: 安全
keywords: "Ethereum Parity 合约漏洞 安全"
---

> 作者： Peter Lai
> 
> 原文地址：`https://medium.com/taipei-ethereum-meetup/parity-%E9%8C%A2%E5%8C%85%E5%90%88%E7%B4%84%E6%BC%8F%E6%B4%9E-43ed412ebcd2`

还记得今年`7`月`Parity`钱包合约被找到漏洞，结果黑客偷走了将近`150,000`个以太币，会发生是因为智能合约的`callback`里使用了`delegatecall（msg.data）`，这个函数会呼叫`data`中的函数并将`msg.sender`设为原呼叫函数的地址，黑客利用这一点呼叫了`initWallet`，这时你们可能会以为`Parity`应该有在[initWallet](https://etherscan.io/tx/0x9dbf0326a03a2a3719c27be4fa69aacc9857fd231a8d9dcaede4bb083def75ec)设置条件阻挡黑客就不能呼叫，结果竟然是没有！所以黑客就成功并改变合约的拥有者，最后再把[以太币转走](https://etherscan.io/tx/0xeef10fc5170f669b86c4cd0444882a96087221325f8bf2f55d6188633aa7be7c)，细节的部分可以看[这篇文章](https://blog.zeppelin.solutions/on-the-parity-wallet-multisig-hack-405a8c12e8f7)。

`Parity`也在几天后[修复了这个问题](https://paritytech.io/blog/security-alert-high-2.html)，修复的方式就是在`init*`函数加上`only_uninitialized modifier`判断，当`m_numOwners > 0`时这个函数就不能使用，这时应该会想说不会再有漏洞了吧，毕竟智能合约能操作以太币，谁知道……

就在前几天有人发布了新`issue`说他不小心删除了钱包的合约，因为只有合约的拥有者可以删除，那么他到底怎么删除合约？可以看到[钱包合约](https://etherscan.io/address/0x863df6bfa4469f3ead0be8f9f2aae51c91a907b4)被删除前共有两笔交易，第一笔交易呼叫`initWallet`并将合约的拥有者设为自己。


```
function initWallet(address[] _owners, uint _required, uint _daylimit) only_uninitialized {
 initDaylimit(_daylimit);
 initMultiowned(_owners, _required);
}
```

**交易结果：**

```
Function: initWallet(address[] _owners, uint256 _required, uint256 _daylimit)
MethodID: 0xe46dcfeb
0:0000000000000000000000000000000000000000000000000000000000000060
1:0000000000000000000000000000000000000000000000000000000000000000
2:0000000000000000000000000000000000000000000000000000000000000000
3:0000000000000000000000000000000000000000000000000000000000000001
4:000000000000000000000000ae7168deb525862f4fee37d987a971b385b96952
```

[第二笔](https://etherscan.io/tx/0x47f7cff7a5e671884629c93b368cb18f58a993f4b19c2a53a8662e3f1482f690)交易呼叫了`kill`函数，而`kill`函数呼叫了`suicide`（[selfdestruct](http://solidity.readthedocs.io/en/develop/introduction-to-smart-contracts.html#self-destruct)函数的别称，功能是将合约程序从内存块链移除，并将合约剩馀的以太币转给参数的位置），钱包的程序就从内存块链上移除了。

```
function kill(address _to) onlymanyowners(sha3(msg.data)) external {
 suicide(_to);
}
```

**交易結果：**

```
Function: kill(address _to)
MethodID: 0xcbf0b0c0
0:000000000000000000000000ae7168deb525862f4fee37d987a971b385b96952
```

因为很多使用这个钱包的合约引入位置都写死导致很多合约不能运作，在[Polkadot](https://etherscan.io/address/0x3bfc20f0b9afcace800d73d2191166ff16540258)里第451行就将钱包合约地址写死：

```
address constant _walletLibrary = 0x863df6bfa4469f3ead0be8f9f2aae51c91a907b4;
```

因为所有逻辑判断都在钱包合约中，所以其他相依于钱包合约的现在以太币都被冻结，且看起来像这样（无法提款）：

```
contract Wallet {
    function () payable {
          Deposit(...)
    }
}
```

`Parity`官方还在了解可行的解决方案，如果想查询自己有没有被影响可以到这个网站。

## 如何预防

这次的事件`Parity`说明有两种预防方式。一种是智能合约不该有自杀的函数，这样即便黑客获得了权限也无法把合约移除。一种是有新的建议及改善时，要及时更新在线的合约或是找寻在线合约可能的漏洞，因为在这问题发生前，就有网友提议在合约部属时要自动呼叫`initWallet`（[pr](https://github.com/paritytech/contracts/pull/74#%20issuecomment-319892715)）加强合约的安全。

## 如何取得冻结的资金
目前没有其他方式可以取得冻结的资金，只能期待未来有相关的[改善建议](https://github.com/ethereum/EIPs)实作在以太坊，或是以太坊实行硬分叉回复状态到钱包合约删除之前。

## 技术交流

- 区块链技术交流QQ群：`348924182`
- 进微信群请加微信：`liyc1215`
- 「区块链部落」公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


