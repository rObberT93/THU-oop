---
title: oop-1
date: 2023-02-20 08:17:45
tags: oop
---
## directory
- 前言
- 编程环境和工具
  - 命令行
  - 编译器
  - 环境变量
- ssh
<!-- more -->
## 前言
[获取全部课程笔记](https://github.com/rObberT93/THUoop)
#### 参考
- 《c++编程思想(2017)》
- 《设计模式》
- 《c++ primer》
- [c++ reference](www.cplusplus.com)

#### 课程理念
编写更好的软件
- 简单性
- 清晰性
- 普遍性——可移植性

思考c++为什么这么设计？这么设计还有没有什么问题？进行创新型思考。
培养“抽象思维”，通过抽象认知复杂世界

#### 抽象
- 过程抽象
- 数据抽象

#### 课程评价
- 平时练习6次 50%
- 期末考试 40%
- 开源工程项目的阅读报告10%
- 雨课堂(扣分) -5%
- bonus(额外) +5%
- **！！！抄袭**查重直接取消本次作业成绩
## 编程环境和工具
#### 命令行
- Linux
- wsl windows subsystem for linux
  
#### 编译器
- IDE 
  -  DEV C++ 
  -  Code::Blocks 
  -  CLion 
  -  XCode 
  -  Visual Studio Code
- Editor 
  -  Sublime Text
  -  Notepad++ 
  -  Vim
- windows上编译器
  - minGW
    - 下载链接 https://sourceforge.net/projects/mingw-w64/files/
  - TDM-GCC
  - Clang
  - MSVC

#### 环境变量
在命令⾏中执⾏命令时，系统除了在当前目录下面寻找程序外，还会到
Path环境变量中的目录去找
- 环境变量⼀般是指在操作系统中用来指定操作系统运行环境的⼀些参
数，如：临时文件夹位置和系统文件夹位置等
- Windows下配置环境变量
• 这台电脑$\rightarrow$右键$\rightarrow$高级系统设置$\rightarrow$高级$\rightarrow$环境变量$\rightarrow$用户环境变量Path$\rightarrow$添加g++所在路径并以分号与其他路径隔开
• 在命令提示符中输⼊``g++ -v``测试是否配置成功
- Linux/MAC下配置环境变量
• 配置环境变量编辑``~/.bashrc``⽂件
• 立即启用: ``source ~/.bashrc``
• 且当每次打开新的shell时，``~/.bashrc``被执⾏
• PATH的路径以冒号分隔, 上图中新增两项之后以冒号分
隔，``$PATH`` 引用原来的变量
• 在命令行中使用``echo $PATH`` 可查看当前PATH环境变量

## ssh
- 本地windows连接Ubuntu
- 本地IPV4地址：127.0.0.1
- Ubuntu
  - host name:zhang-PC
  - user name:root
  - process ID:1286
- ssh username@ip
  - ssh 1286@root