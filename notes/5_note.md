# 五、深入理解函数
## 1.return语句  
    在有返回值的函数中，return语句的作用是**提供整个函数的返回值，并结束当前函数返回到调用它的地方**。在没有返回值的函数中也可以使用return语句，例如当检查到一个错误时提前结束当前函数的执行并返回：
```
#include <math.h>
void print_logarithm(double x)
{
	if (x <= 0.0) {
		printf("Positive numbers only, please.\n");
		return;
	}
	printf("The log of x is %f", log(x));
}
```
  函数的返回值应该这样理解：**函数返回一个值相当于定义一个和返回值类型相同的临时变量并用return后面的表达式来初始化**。
注意：
  1.函数的返回值不是左值，或者说函数调用表达式不能做左值，因此下面的赋值语句是非法的：
```
is_even(20) = 1;  
```
  2.在写带有return语句的函数时要小心检查所有的代码路径（Code Path）。有些代码路径在任何条件下都执行不到，这称为Dead Code，例如把&&和||运算符记混了（据我了解初学者犯这个低级错误的不在少数），写出如下代码：
```
void foo(int x, int y)
{
	if (x >= 0 || y >= 0) {
		printf("both x and y are positive.\n");
		return;
	} else if (x < 0 || y < 0) {
		printf("both x and y are negetive.\n");
		return;
	}
	printf("x has a different sign from y.\n");
}
```
最后一行printf永远都没机会被执行到，是一行Dead Code。  
## 习题 (见 YXYX_Clearning/codes/5_codes.c)
1、编写一个布尔函数int is_leap_year(int year)，判断参数year是不是闰年。如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，此外，能被400整除的年份也是闰年。  
2、编写一个函数double myround(double x)，输入一个小数，将它四舍五入。例如myround(-3.51)的值是-4.0，myround(4.49)的值是4.0。可以调用math.h中的库函数ceil和floor实现这个函数。

## 2.增量式开发
  增量式开发非常适合初学者，每写一行代码都编译运行，确保没问题了再写一下行，一方面在写代码时更有信心，另一方面也方便了调试：总是有一个先前的正确版本做参照，改动之后如果出了问题，几乎可以肯定就是刚才改的那行代码出的问题，这样就避免了必须从很多行代码中查找分析到底是哪一行出的问题。在这个过程中printf功不可没，你怀疑哪一行代码有问题，就插一个printf进去看看中间的计算结果，任何错误都可以通过这个办法找出来。
  尽可能复用（Reuse）以前写的代码，避免写重复的代码。封装就是为了复用，把解决各种小问题的代码封装成函数，在解决第一个大问题时可以用这些函数，在解决第二个大问题时可以复用这些函数。  
  解决问题的过程是把大的问题分成小的问题，小的问题再分成更小的问题，这个过程在代码中的体现就是函数的分层设计（Stratify）。distance和area是两个底层函数，解决一些很小的问题，而area_point是一个上层函数，上层函数通过调用底层函数来解决更大的问题，底层和上层函数都可以被更上一层的函数调用，最终所有的函数都直接或间接地被main函数调用。如下图所示：  
  ![image](https://akaedu.github.io/book/images/func2.stratify.png)





  
