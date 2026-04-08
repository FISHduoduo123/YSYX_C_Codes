## Write a "Hello World" program under GNU/Linux
Write a "Hello World" program, compile it, then run it under GNU/Linux. If you do not know what to do, refer to the GNU/Linux tutorial above.  
### 编写Hello World 
**c创建文件**  
```touch code.c```  
创建完成后编写打印程序。
![]()  

## Write a Makefile to compile the "Hello World" program
Write a Makefile to compile the "Hello World" program above. If you do not know what to do, refer to the GNU/Linux tutorial above.  
**创建Makefile文件**  
```touch Makefile```  
编写编译脚本
![]()  
运行Makefile完成编译  
**运行可执行程序**  
![]()  
## Learn to use GDB
Read the GDB tutorial above and use GDB following the tutorial. In PA1, you will be required to implement a simplified version of GDB. If you have not used GDB, you may have no idea to finish PA1.  
### GDB测试命令
#### 启动
- gdb ./prog：加载可执行文件
**打开调试hello可执行程序**  
```gdb hello```  
![]()  
#### 查看源代码
- list [N|func] / l：查看源码
![]()  
#### 设置断点并运行
- break N / b N：在第 N 行设置断点
![]()  
- run / r：开始运行程序
![]()  
- print var / p var：打印变量值
![]()  
- delete N：删除编号为 N 的断点
![]()  
- continue / c：继续执行到下一个断点
![]()  
#### 退出
- quit 或 q：退出调试器
![]()  
### 其他命令
- next / n：单步执行（不进入函数）
- step / s：单步执行（进入函数）
- break func：在函数入口设置断点
- info breakpoints：查看断点列表
- set var x=10：修改变量值
- ptype var：查看变量类型
- ···