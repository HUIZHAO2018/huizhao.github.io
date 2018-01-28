---
layout: post
title: "区块链技术相关的论文、文档"
date: 2017-09-27
description: "本文汇总了区块链相关的论文、文档，内容包括各种翻译文档，优质原创，密码学，共识算法、账本结构、LMAX，P2p协议、ipfs、比特币、Raft，Paxos，随机数生成，验证交易等等内容。"
tag: 区块链
keywords: "区块链技术论文,区块链文档"
---


## 索引

* [Angaroa的实现 repo](https://github.com/chrisnc/tangaroa)
* [Understanding Serenity, Part I: Abstraction](https://blog.ethereum.org/2015/12/24/understanding-serenity-part-i-abstraction/): [中文翻译](http://ethfans.org/posts/understanding-serenity-part-i-abstraction)
* [Understanding Serenity, Part 2: Casper](https://blog.ethereum.org/2015/12/28/understanding-serenity-part-2-casper/): [中文翻译](http://ethfans.org/posts/understanding-serenity-part-ii-casper)
* [隔离见证技术 - set wit: segregated witness](http://www.8btc.com/segregated-witness-is-cool)
* [IBLTs: 可逆式布鲁姆查找表(IBLT) , 如何促进比特币的去中心化](http://www.8btc.com/iblts-bitcoin-decentralization), 弱区块（weak blocks），瘦区块（thin blocks），一个“blocktorrent”协议; Invertible Bloom Lookup Table.
* Matt Corallo的快中继网络（fast relay network）
* [Bitcoin NG](http://www.8btc.com/bitcoin-ng-2)
* [TaPOS](http://www.bts.hk/tapos-baipishu.html)
* [SkuChain](http://www.skuchain.com/): 供应链管理， [code](https://github.com/thingchain)
* [Factom](): 公正通. Factom是一个P2P的协议, 它在比特币的区块链上维护了一个数据层。 网络文件和应用被压缩成一个Merkle树上的哈希值并被存储在比特币的区块链上。Proof of existence.
* [Blockstack.io](https://blockstack.io/): 被数字资产公司收购
* [CoinSpark](https://coinspark.org/): 数字资产管理
* [MultiChain](http://www.multichain.com/): Open platform for building blockchains, It is a [DIY permissioned blockchain](http://bitcoinist.net/multichain-diy-permissioned-blockchain/). [Withe paper](http://www.multichain.com/white-paper/)
* [LightningNetwork](https://github.com/LightningNetwork/lnd): [Paper](https://github.com/LightningNetwork/paper)
* [BlackCoin](http://blackcoin.co/): POS2.0, 3.0, [CodeBase](https://github.com/rat4/blackcoin)
* [BlackHalo](http://blackhalo.info/) : Smart Contract, The first of its kind to support two-party contracts, Joint Accounts & More!
* [Greedy Heaviest Observed Subtree(GHOST)](http://www.cs.huji.ac.il/~avivz/pubs/13/btc_scalability_full.pdf) : 以太坊使用的GHOST协议，使用tree来存储交易数据
* [Emercoin](https://github.com/EvgenijM86/emercoin/): 采用STUN协议来实现P2P网络，可以与webrtc兼容 。 [代码](https://github.com/EvgenijM86/emercoin/), POW + POS , fork from [ppcoin](https://github.com/ppcoin/ppcoin)
* [openchain](https://www.openchain.org/) : client-server架构的chain，ibm贡献的代码，c#开发，适合企业内部使用
* [GitTorrent](https://github.com/conseweb/GitTorrent): 一个使用bittorrent + bitcoin构建的去中心化的github. [Blog](http://blog.printf.net/articles/2015/05/29/announcing-gittorrent-a-decentralized-github/)
* [RSCoin code](https://github.com/RSCoin/RSCoin): 英国央行的数字货币，基于莱特币
* [Codius repo](https://github.com/codius/codius): Codius Smart Oracle system, 智能合约

## 相关文章
* [精通比特币](http://www.zhibimo.com/read/wang-miao/mastering-bitcoin/index.html)
* [黎跃春区块链技术博客](http://liyuechun.org)
* [how to program block chain explorers with python part 1](http://alexgorale.com/how-to-program-block-chain-explorers-with-python-part-1)
* [How to Put Custom Messages Into Bitcoin Blockchain - OP_RETURN](http://wlangiewicz.com/blog/2014/10/24/how-to-put-custom-messages-into-bitcoin-blockchain-op-return/)
* [How to write a bit torrent client](http://www.kristenwidman.com/blog/33/how-to-write-a-bittorrent-client-part-1/)
* [A simple Distributed Hash Table (DHT)](https://rezahok.wordpress.com/2009/09/21/a-simple-distributed-hash-table-dht/)
* [Tempering Kademlia with a Robust Identity Based System](http://www.lajello.com/papers/p2p08.pdf)
* [TrustedKad – Application of Trust MechanismstoaKademlia-BasedPeer-to-Peer Network](https://duepublico.uni-duisburg-essen.de/servlets/DerivateServlet/Derivate-37616/Dissertation_Kohnen.pdf)
* [Kademlia](https://zh.wikipedia.org/wiki/Kademlia)
* [Democratizing content publication with Coral](https://www.coralcdn.org/docs/coral-nsdi04.pdf)
* [Decentralized Reddit using a DHT to store content and a blockchain to rank it](https://news.ycombinator.com/item?id=10391996) : Many other ideas about blockchains.
* [PolderCast: Fast, Robust, and Scalable Architecture for P2P Topic-based Pub/Sub](http://acropolis.cs.vu.nl/~spyros/www/papers/PolderCast.pdf)
* [Bitcoin-NG: A Scalable Blockchain Protocol](http://arxiv.org/pdf/1510.02037.pdf)
* [Bitcoin-NG 可扩展的区块链协议](http://www.8btc.com/bitcoin-ng-2)
* [LINKABLE RING SIGNATURES OVER ELLIPTIC CURVES](https://jesper.borgstrup.dk/2014/04/linkable-ring-signatures-over-elliptic-curves/)
* [Ring signature implementation with python](http://everything.explained.today/Ring_signature/)
* [Python implementation of Linkable Ring Signatures over Elliptic curves](https://gist.github.com/xbee/8a37bcfd80ef727cc3f0)
* [Bitcoin in Bloom: How IBLTs Allow Bitcoin to Scale: 使用IBLTs来增强比特币的可扩展性](https://www.cryptocoinsnews.com/bitcoin-in-bloom-how-iblts-allow-bitcoin-scale/)
* [使用IBLT来减少区块的传播速度](https://gist.github.com/gavinandresen/e20c3b5a1d4b97f79ac2)
* [BitGit](http://luke.dashjr.org/programs/bitcoin/) ： 相关开源项目的汇集
* [Secret Sharing and Erasure Coding: A Guide for the Aspiring Dropbox DecentralizerIntroduction](https://blog.ethereum.org/2014/08/16/secret-sharing-erasure-coding-guide-aspiring-dropbox-decentralizer/)
* [Ultimate blockchain compression w/ trust-free lite nodes](https://bitcointalk.org/index.php?topic=88208.0)
* 	[Python implementation of Linkable Ring Signatures over Elliptic curves](https://gist.github.com/xbee/8a37bcfd80ef727cc3f0)
* 	[MaidSafe’s consensus mechanism](https://forum.safenetwork.io/t/vitalik-buterin-on-maidsafes-consensus-mechanism/3542)
*	[Alternatives for Proof of Work, Part 1: Proof Of Stake](https://bytecoin.org/blog/proof-of-stake-proof-of-work-comparison/)
*	[Alternatives for Proof of Work, Part 2: Proof of Activity, Proof of Burn, Proof of Capacity, and Byzantine Generals](https://bytecoin.org/blog/proof-of-activity-proof-of-burn-proof-of-capacity/)


## 比特币、区块链相关可参考的项目

* [比特币协议说明](https://zh-cn.bitcoin.it/wiki/%E5%8D%8F%E8%AE%AE%E8%AF%B4%E6%98%8E)
* [A(nother) Bittorrent client written in the go programming language
](https://github.com/jackpal/Taipei-Torrent)
* [Full-featured BitTorrent client package and utilities](https://github.com/anacrolix/torrent)
* [A Golang port of peerflix.](https://github.com/Sioro-Neoku/go-peerflix)
* [dht: Kademlia/Mainline DHT node in Go.](https://github.com/nictuku/dht)
* [coinbits : A Python library for bitcoin peer to peer communication](https://github.com/8468/coinbits)
* [protocoin: A pure Python Bitcoin protocol implementation](https://github.com/perone/protocoin): [doc](http://protocoin.readthedocs.org/)
* [kademlia: A DHT in Python Twisted](https://github.com/bmuller/kademlia)
* [An alternative full node bitcoin implementation written in Go (golang)](https://github.com/btcsuite/btcd)
* [A secure bitcoin wallet daemon written in Go (golang)](https://github.com/btcsuite/btcwallet)
* [gocoin: Full bitcoin solution written in Go (golang)](https://github.com/piotrnar/gocoin)
* [bitcoinj: A library for working with Bitcoin with java](https://github.com/bitcoinj/bitcoinj)
* [dht_store](http://www.libtorrent.org/dht_store.html) : This is a proposal for an extension to the BitTorrent DHT to allow storing and retrieving of arbitrary data.
* [BlockStore](https://github.com/blockstack/blockstore): Name registrations on the Bitcoin blockchain with external storage
* [pydht](https://github.com/isaaczafuta/pydht): Python implementation of the Kademlia DHT data store
* [A way to experiment with Bitcoin.](https://github.com/gak/docker-bitcoin-regtest)
* [pyp2p](https://github.com/Storj/pyp2p)
* [python-OP_RETURN: Simple Python commands and library for using bitcoin OP_RETURNs](https://github.com/coinspark/python-OP_RETURN)
* [A Common Blockchain interface for the Bitcoin Core RPC.](https://github.com/blockai/rpc-common-blockchain): 一个接口规范
* [abstract-common-blockchain](https://github.com/blockai/abstract-common-blockchain): A test suite and interface you can use to implement standard Bitcoin blockchain API calls for various backends and platforms.
* [CryptoNote](https://github.com/cryptonotefoundation/cryptonote): CryptoNote protocol implementation. This is the reference repository for starting a new CryptoNote currency. See /src/cryptonote_config.h https://cryptonote.org/
* [Colored-Coins](https://github.com/Colored-Coins): The Open Source Protocol for Creating Digital Assets On The Bitcoin Blockchain. 基于比特币区块链创建、管理数字资产的开源协议。
* [CounterParty](http://counterparty.io/)
* [crypti](https://crypti.me/)
* [ipfs](https://github.com/ipfs/ipfs): IPFS - The Permanent Web
* [Open Assets Protocol](https://github.com/OpenAssets/open-assets-protocol)
* [Telehash](http://telehash.org/) : [source](https://github.com/telehash)
* [BlockName](https://github.com/telehash/blockname): A blockchain-backed DNS resolver
* [How to create genesis block](https://github.com/lhartikk/GenesisH0)
* [Factom](https://github.com/FactomProject/FactomCode):
* [BitShares](https://bitshares.org/): BitShares is an industrial-grade financial blockchain smart contracts platform.
* [Blockstream](https://blockstream.com/): 侧链创业公司。 Blockstream’s core area of innovation is sidechains, a technology focused on improving on the blockchain, the most powerful public utility for distributed trust systems.
* [openpublish: A publishing protocol for registering media as a digital asset on the Bitcoin blockchain.](https://github.com/blockai/openpublish): 数字内容、数字资产注册、发布平台，产权可以方便转移，交换，而且可以很准确的统计阅读数
* [bitstore]()
* [bitstore-client: A content-addressable file hosting and distribution service that uses Bitcoin public key infrastructure for authentication and payment.](https://github.com/blockai/bitstore-client)
* [abstract-common-wallet](https://github.com/blockai/abstract-common-wallet): 钱包通用服务接口
* [my-two-bits](https://github.com/blockai/my-two-bits)：付费评论系统
* [Blockai](https://www.blockai.com) : 一种数字内容发布、管理平台，似乎可以用来对盗版影视剧的解决
* [FileCoin](http://filecoin.io/)
* [Lisk](https://lisk.io/): [github](https://github.com/LiskHQ/lisk), Lisk decentralized application platform and crypto-currency
* [Boolberry](http://boolberry.org/): 更强隐私性
* [Pebblecoin (XPB) - FIRST DPOS CRYPTONOTE COIN](https://bitcointalk.org/index.php?topic=909624.0): [github](https://github.com/xpbcreator/pebblecoin/)
* [Tendermint](http://tendermint.com/): Blockchain app development simplified – focus on business logic & we’ll handle the rest. [github](https://github.com/tendermint/tendermint); [Tendermint consensus protocol](https://bitcointalk.org/index.php?topic=866460.0);
* [Tendermint TMSP](https://github.com/tendermint/tmsp): Tendermint socket protocol for blockchain applications
* [Bitfury](http://bitfury.com/)
*	[libbitcoin](https://github.com/libbitcoin)
* [Enigma](http://enigma.mit.edu/): Enigma is a decentralized cloud platform with guaranteed privacy. Private data is stored, shared and analyzed without ever being fully revealed to any party. 
*	[Keyhotee](https://github.com/InvictusInnovations/keyhotee): Decentralized ID and Communication
*	[ZeroNet](https://zeronet.io/): Open, free and uncensorable websites, using Bitcoin cryptography and BitTorrent network. [github](https://github.com/HelloZeroNet/ZeroNet)
*	[zerocash](http://zerocash-project.org/index): Zerocash is a protocol that provides a decentralized crypto-currency in which, as in Bitcoin, users collaborate to maintain the currency by broadcasting and verifying payment transactions. Zerocash, however, differs from Bitcoin in how these payment transactions are assembled and then verified. 更具有隐私保护的币。
*	[bitstarter-leaderboard](https://github.com/startup-class/bitstarter-leaderboard): A more sophisticated Bitcoin-powered crowdfunder.
*	[untitled-dice.github.io](https://github.com/untitled-dice/untitled-dice.github.io): a basic bitcoin dice site


# 算法、理论

## 密码学
* [Homomorphic secret sharing](https://en.wikipedia.org/wiki/Homomorphic_secret_sharing)

## 共识算法
* [比特币百晓生：三种POS机制及其政治信仰](http://www.wanbizu.com/xinbi/20140708540.html)
* [黑币最新动态：白皮书之黑币POS协议2.0版](http://www.wanbizu.com/xinbi/201408041253.html)

## 账本结构
* [Tree Chains](https://github.com/petertodd/tree-chains-paper): [web](http://www.mail-archive.com/bitcoin-development@lists.sourceforge.net/msg04388.html)
* [Quadtree](https://en.wikipedia.org/wiki/Quadtree): Buckettree, Q-tree
* [LLRB](https://en.wikipedia.org/wiki/Left-leaning_red%E2%80%93black_tree) - Left-leaning red–black tree

## LMAX
* [LMAX](http://martinfowler.com/articles/lmax.html): [github](https://lmax-exchange.github.io/disruptor/)
* [LMAX中文](http://www.jdon.com/42452)
*	[disruptor](https://github.com/LMAX-Exchange/disruptor): High Performance Inter-Thread Messaging Library. LMAX的java实现.
*	[go-disruptor](https://github.com/smartystreets/go-disruptor)
*	[ring-buffer](http://zhen.org/blog/ring-buffer-variable-length-low-latency-disruptor-style/): Ring Buffer - Variable-Length, Low-Latency, Lock-Free, Disruptor-Style, [code](https://github.com/zhenjl/ringbuffer)

## Decentralized ID 
* [Identity protocol v1](https://en.bitcoin.it/wiki/Identity_protocol_v1)

## Consensus Algorithm
### Raft
* [Raft](https://raft.github.io/)
* [RaftScope](https://github.com/ongardie/raftscope)
* [分布式系统的Raft算法](http://www.jdon.com/artichect/raft.html)
* [Raft一致性算法](http://blog.csdn.net/cszhouwei/article/details/38374603)
* [Raft算法的学习与理解](http://bingotree.cn/?p=611)

### Paxos
* [PaxosLease算法实现——用于Paxos自身选主](http://bingotree.cn/?p=604)
* [PAXOS算法理解](http://bingotree.cn/?p=595)
* [Paxos选举多次决议的算法实现](http://bingotree.cn/?p=607)
* [PAXOS的初次学习](http://bingotree.cn/?p=588)
* [对Raft与Paxos的关系的理解](http://bingotree.cn/?p=614)

## 随机数生成
* [Shamir's Secret Sharing Scheme](http://point-at-infinity.org/ssss/)

## Confidential Transactions
* [Confidential Transactions, Content privacy for Bitcoin transactions](https://bitcointalk.org/index.php?topic=1085273.0)
* [Blockstream's Austin Hill: confidential blockchains can remove systemic risk from finance](http://www.ibtimes.co.uk/blockstreams-austin-hill-confidential-blockchains-can-remove-systemic-risk-finance-1529333)
* [What are Confidential Transactions](https://www.weusecoins.com/adam-back-confidential-transactions/)
* [Confidential Transactions](https://people.xiph.org/~greg/confidential_values.txt)
* [The first successful Zero-Knowledge Contingent Payment](https://bitcoincore.org/en/2016/02/26/zero-knowledge-contingent-payments-announcement/)
* [PayPub: Trustless payments for information publishing on Bitcoin](https://github.com/unsystem/paypub)
* [比特币网络中第一笔零知识证明交易发送成功](http://blockchain.hk/zero-knowledge-contingent-payments-announcement/)


## LevelDB & RocksDB
* [LevelDB性能分析和表现](http://database.51cto.com/art/201106/267852.htm)
* [What are the keys used in the blockchain levelDB (ie what are the key:value pairs)?](http://bitcoin.stackexchange.com/questions/28168/what-are-the-keys-used-in-the-blockchain-leveldb-ie-what-are-the-keyvalue-pair)
* [Benchmarking LevelDB vs. RocksDB vs. HyperLevelDB vs. LMDB Performance for InfluxDB](https://influxdata.com/blog/benchmarking-leveldb-vs-rocksdb-vs-hyperleveldb-vs-lmdb-performance-for-influxdb/)

## Trie
* [Understanding the ethereum trie](https://easythereentropy.wordpress.com/2014/06/04/understanding-the-ethereum-trie/)
* [Patricia Tree](https://github.com/ethereum/wiki/wiki/Patricia-Tree)

## 技术交流

- 区块链技术交流QQ群：348924182

- 「区块链部落」公众号

![](http://om1c35wrq.bkt.clouddn.com/%E5%8C%BA%E5%9D%97%E9%93%BE%E9%83%A8%E8%90%BD.png)


