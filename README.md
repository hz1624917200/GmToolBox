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

## 研究记录

### SM3的算法流程

详见[SM3密码杂凑算法](./doc/SM3密码杂凑算法.md)

### SM4的算法流程

详见[SM4分组密码算法](./doc/SM4分组密码算法.md)

### Platform IO
详见[Platform IO x FreeRTOS 环境搭建](./doc/Platform%20IO%20x%20FreeRTOS%20%E7%8E%AF%E5%A2%83%E6%90%AD%E5%BB%BA.md)

## 工作记录

详见[工作记录](./工作记录.md)

## 成果概要

### 核心成果

详见[核心成果](./核心成果.md)

### 其他成果

详见[成果](./成果.md)
