# GmToolBox Library

> &emsp;&emsp;此库为本项目的主要设计成果。在FreeRTOS上实现了包含SM3，SM4算法的国密算法库。内含多种加密、摘要计算模式。具体定义在头文件中。**详细使用说明，请参见[GmToolBox Documentation](../../doc/GmToolBox-Documentation.md)**

## 文件结构/说明

```
gmssl
├── include			# 库所使用的头文件
│   ├── endian.h	# 大小端RW、轮换等功能函数
│   ├── error.h		# 错误处理函数
│   ├── gcm.h		# SM4-gcm 加密模式功能函数
│   ├── gf128.h		# SM4-gcm 加密模式功能函数
│   ├── hex.h		# gcm 模式使用的基本函数
│   ├── mem.h		# GmSSL 内存操作函数
│   ├── padding.h	# 明文分组Padding函数
│   ├── sm3.h		# SM3 算法主函数
│   └── sm4.h		# SM4 算法主函数
├── README.md		# 本说明文档
└── src
    ├── gcm.c		
    ├── gf128.c
    ├── hex.c
    ├── padding.c
    ├── sm3.c		# SM3 算法主函数
    ├── sm3-stream.c# SM3 流式加密函数
    ├── sm4_common.c# SM4 基本定义
    ├── sm4_enc.c	# SM4 加密主函数
    ├── sm4_lcl.h	# SM4 循环展开宏
    ├── sm4_modes.c	# SM4 加密方式
    └── sm4_setkey.c# SM4 密钥设置函数
```

