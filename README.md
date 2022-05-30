# OS-166-GMSSL
> 基于FreeRTOS on RISC-V 的国密算法（SM3, SM4）实现 `GmToolBox`

## 文件目录结构

下面是对工程文件目录结构的说明：

```
.
├─doc
│  └─pic
├─firmware
├─include
├─lib
├─src
└─test
```

* doc：存放绝大部分文档
  * pic: 文档对应Markdown 文件的图片链接位置
* firmware：已经完成，可用于测试的第三方固件
* include：工程自定义头文件
* lib：工程使用的第三方库
* src：工程主要代码
* test：工程单元测试文件

## 项目要求
详见[项目要求](./doc/%E9%A1%B9%E7%9B%AE%E8%A6%81%E6%B1%82.md)

## 实现思路
详见[实现思路](./doc/%E5%AE%9E%E7%8E%B0%E6%80%9D%E8%B7%AF.md)

## 中期报告

### 与导师的沟通情况

​	项目过程中始终同导师保持良好的沟通，在微信群中同步项目进度，并多次通过腾讯会议交流项目。

### 当前开发状态说明

1.SM3的移植及相应测试基本完成

2.SM4的移植还未进行

3.设计了一个教学实验，之后的实验待设计

4.算法优化待设计

### 待解决的问题

​	优化方向尚不明确

## 研究记录

### SM3的算法流程

详见[SM3密码杂凑算法](./doc/SM3密码杂凑算法.md)

### SM4的算法流程

待补充

### Platform IO
详见[Platform IO x FreeRTOS 环境搭建](./doc/Platform%20IO%20x%20FreeRTOS%20%E7%8E%AF%E5%A2%83%E6%90%AD%E5%BB%BA.md)

## 工作记录

详见[工作记录](./工作记录.md)

