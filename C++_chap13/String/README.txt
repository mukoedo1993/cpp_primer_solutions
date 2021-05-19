C++ 的一个常见面试题是让你实现一个 String 类，限于时间，不可能要求具备 std::string 的功能，但至少要求能正确管理资源。具体来说：

能像 int 类型那样定义变量，并且支持赋值、复制。
能用作函数的参数类型及返回类型。
能用作标准库容器的元素类型，即 vector/list/deque 的 value_type。（用作 std::map 的 key_type 是更进一步的要求，本文从略）。
换言之，你的 String 能让以下代码编译运行通过，并且没有内存方面的错误。
Question: 定义一个String class, 使得test.cpp的代码能顺利运行。

Source: https://coolshell.cn/articles/10478.html
