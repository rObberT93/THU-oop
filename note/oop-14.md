---
title: oop-14
date: 2023-05-29 08:01:55
tags: oop
---
# 设计模式
- 行为型模式
  - 模板方法模式
  - 策略模式
  - 迭代器模式
- 结构性模式
- 创建型模式
<!-- more -->
## 模板方法模式
- 抽象类（父类）定义算法骨架
- 细节由实现类（子类）负责实现
- 定义一个新类，需要重新弄一个实现所有函数的子类
- Q：如果函数之间可自由组合？使用模板方法需要定义所有组合数量个子类。

## 策略模式
- monitor对函数进行组合
- ![image-20230529085737435](C:\Users\yuton\AppData\Roaming\Typora\typora-user-images\image-20230529085737435.png)

## 比较

- 模板方法：
  - ![image-20230529090117490](C:\Users\yuton\AppData\Roaming\Typora\typora-user-images\image-20230529090117490.png)
  - 逻辑复杂但结构稳定

- 策略模式：
  - ![image-20230529090135035](C:\Users\yuton\AppData\Roaming\Typora\typora-user-images\image-20230529090135035.png)
  - 功能灵活多变，多种算法之间协同工作

## 迭代器

实现了算法和数据存储的隔离