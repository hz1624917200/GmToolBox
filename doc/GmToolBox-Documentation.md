







<div id='write'  class=''><h1><a name="gmtoolbox-on-freertos--risc-v-documentation" class="md-header-anchor"></a><span>GmToolBox on FreeRTOS &amp; RISC-V Documentation</span></h1><p>&nbsp;</p><h1><a name="gmtoolbox-on-freertos--risc-v"></a><span>GmToolBox on FreeRTOS &amp; RISC-V</span></h1><h1><a name="技术文档"></a><span>技术文档</span></h1><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p><p>&nbsp;</p>












<p style="text-align:center;font-size:20pt;font:"Consolas";margin: 0 auto">北理工的恶龙</p>
<p style="text-align:center;font-size:18pt;margin: 0 auto">2022-05-31</p>
<div style="page-break-after:always"></div>





<b style=font-size:20pt;>关于本文档</b>

&emsp;&emsp;本技术文档为用户提供：

1. **GmToolBox on FreeRTOS & RISC-V** 项目介绍。
2. 利用**GmToolBox on FreeRTOS & RISC-V** 开发时的编程指南。



<b style=font-size:20pt;>发布说明</b>

| 日期       | 版本 | 发布说明 |
| ---------- | ---- | -------- |
| 2022-05-31 | V1.0 | 初始版本 |

<div style="page-break-after:always"></div>





<b style=font-size:20pt;>目录</b>

[toc]

<div style="page-break-after:always"></div>





## 关于本项目



### 项目简介

&emsp;&emsp;本项目基于[GmSSL开源项目](https://github.com/guanzhi/GmSSL)开发，将其部分主要功能（SM3 / SM4 国密散列/加密算法）移植到基于RISC-V的FreeRTOS实时操作系统上。并针对部分应用场景进行了功能拓展和优化。



### 项目特性

&emsp;&emsp;本项目相较于国密算法的简单实现，具有以下特性：

* 执行效率高：在**代码层面充分优化**，利用循环展开等技术，提高软件层面运行效率
* 针对嵌入式优化：**考虑到嵌入式设备的特性**（如存储空间小、运行内存小、处理器频率低等），优化功能结构，并在规模上加以限制，保障本库在嵌入式设备实体平台上运行的安全性。
* 模块化：功能模块耦合度低，模块复用度高、逻辑清晰
* 功能丰富：在实现SM3、SM4主算法的基础上，为了方便不同的散列、加密方式使用，提供了种类丰富的加密方式接口。使用者不需要复杂编码即可实现大部分加密模式。

