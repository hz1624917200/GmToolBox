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



## 成果概要

### 核心成果

在基于RISC-V的FreeRTOS平台上构建的**国密算法工具库GmToolBox**。

* 有关工具库的特性介绍等，请参见[核心成果](./核心成果.md)
* 工具库的完整文档，请参见[GmToolBox Documentation](./GmToolBox-Documentation.pdf)

### 其他成果

* **发现社区最大国密算法项目库GmSSL中的Bug**， 向项目提交Issue，目前已经被接受并完成修改。
* 在开发的过程中，我们遇到了一些难点。为此，受我们的项目开发中遇到的问题启发，我们设计了数个教学实验，以促进学院操作系统课程实践发展。
* 为了展现**基于GmToolBox库开发应用程序的便捷性和该库与FreeRTOS任务调度系统的结合**，我们针对物联网设备中的常见应用场景——**设备拍摄图像，并加密回传**，开发了一个样例任务程序。

![Demo](./doc/pic/Demo1.jpg)

**另有样例演示视频：**

* [Demo1](./Demo1.mp4)
* [Demo2](./Demo2.mp4)

具体内容详见[成果](./成果.md)



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


