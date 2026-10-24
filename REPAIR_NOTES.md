# 代码修复与验证说明

## 本次修改

补充动态规划空输入处理，修复摆动序列的整数溢出和空数组问题；爬楼梯改为具名滚动状态，补全移动零的稳定双指针实现。28 个算法文件均包含回归用例。

修改处使用中文注释解释原因；新增及重写的变量使用能够表达业务含义的名称，保留未涉及的公开接口和题目约定。部分教学代码仍不是生产级组件。

## 运行检查

在本仓库根目录执行，要求 GCC/G++（C11、C++17）、Python 3。Protobuf、VideoWebSite 和部分 Linux 示例还需要 Protobuf 3.21、JsonCpp、MariaDB 客户端开发库。云环境可先执行 `source /workspace/.setup/env.sh`，再设置：

```bash
export CPPFLAGS=-I/workspace/.setup/sysroot/usr/include
export LDFLAGS=-L/workspace/.setup/sysroot/usr/lib/x86_64-linux-gnu
python3 tests/check_syntax.py
```

通用系统安装路径可以不设置 CPPFLAGS/LDFLAGS。语法检查覆盖每个源文件及独立头文件，不等同于算法正确性验证。

回归测试：

```bash
set -e
g++ -std=c++17 -fsanitize=address,undefined -g tests/regression.cpp -o /tmp/algorithm-regression
/tmp/algorithm-regression
```

