# Fast_IO

## Summary

算法竞赛中卡常利器，利用`fread`和`fwrite`实现的快读快写，完美跨平台并且支持C++98及以上。

支持的数据类型包括：

- int, unsigned int, long long, unsigned long long
- char, char[]

**警告:** 一旦使用`Fast_In`和`Fast_Out`接管文件流后，该文件流不可再次使用（如果接管`stdio`，则不能使用任何标准库中的IO函数）



## 实现原理

利用`fread`和`fwrite`一口气读/写约10M的内容，尽力减少因系统IO带来的阻塞。



## Usage

### 准备工作

由于算法竞赛中，大部分只能提交一个文件，故需要使用者手动引入头文件

```cpp
#include <cstdio>
#include <cstring>
#include <cctype>
```

同时将需要的类粘贴到你的代码中。



### 标准输入输出

从控制台读入和读出，`Fast_In`和`Fast_Out`构造函数的默认参数为为`stdin/stdout`。

构造如下，建议放在全局中：

```cpp
Fast_In fast_read_std();
// 等同于
Fast_In fast_read_std(stdin);

// 同理
Fast_Out fast_print_std();
// 等同于
Fast_Out fast_print_std(stdout);
```

使用方法如下

```cpp
fast_read_std >> x >> y >> z;
fast_print_std << x << '\n' << y << "\n" << z;
```



### 从文件输入输出

从文件输入输出，需要在构造函数中传入对应的文件流。

其构造如下：

```cpp
Fast_In fast_read_file(fopen("test.in", "r"));
Fast_Out fast_print_file(fopen("test.out", "w"));
```

使用方法如下：

```cpp
fast_read_file >> x >> y >> z;
fast_print_file << x << '\n' << y << "\n" << z;
```

