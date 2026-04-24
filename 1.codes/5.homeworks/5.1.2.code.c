//编写一个函数double myround(double x)，
//输入一个小数，将它四舍五入。
//例如myround(-3.51)的值是-4.0，myround(4.49)的值是4.0。可以调用math.h中的库函数ceil和floor实现这个函数。
#include <stdio.h> 
#include <math.h> 
double myround(double x)
{
    if (x>0) return floor(x+0.5);
    else if (x<0) return floor(x-0.5);
    else return 0;
}
int main(void)
{   
    int i;
    i = 2.6;
    printf("四舍五入后：%f\n",myround(i));
	return 0;
}
