# 五、深入理解函数
## 1.return语句  
  在有返回值的函数中，return语句的作用是提供整个函数的返回值，并结束当前函数返回到调用它的地方。在没有返回值的函数中也可以使用return语句，例如当检查到一个错误时提前结束当前函数的执行并返回：
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
