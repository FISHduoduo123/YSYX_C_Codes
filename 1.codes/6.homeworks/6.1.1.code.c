/*循环变量：作为控制变量，每轮数值改变，并下一轮开始前在控制表达式进行判断用于跟踪循环次数
累加器（加法/乘法计算根据实现目标逻辑而定）：用于累计所经过循环后的总量
(a%10)取个位
(a/10)取十位
例子：统计1~100中9出现的次数*/
#include <stdio.h>

int main() 
{
    int i = 1;     //循环控制变量
    int count = 0; //累加器统计9出现次数
    while (i <= 100) 
    {
        if (i % 10 == 9) count++; // 取个位
        if (i / 10 == 9) count++;  // 取十位
        i++;
    }
    printf("9出现次数：%d\n", count);
    
    return 0;
}

//求两个正整数a和b的最大公约数（GCD，Greatest Common Divisor），
//使用Euclid算法：
/*
  1.如果a除以b能整除，则最大公约数是b。
  2.否则，最大公约数等于b和a%b的最大公约数。
*/
#include <stdio.h>

int main(void)
{   
    int a = 10; 
    int b = 2;      //初始a, b   
    int c = 0;      //计算结果   
    while (a%b)
    {
        a = b;
        b = a%b;    //下一次循环操作数
    }
    c = b;        //输出结果
    printf("最大公约数%d\n",c);
    return 0;
}

//求Fibonacci数列的第n项，
//这个数列是这样定义的：
/*
  fib(0)=1
  fib(1)=1
  fib(n)=fib(n-1)+fib(n-2)
*/
#include <stdio.h> 
int main(void)
{   
    int n = 4;      //初始n   
    int cnt = 0;
    int a = 0;
    int b = 1;      //中间结果
    int c = 0;      //计算结果   
    while (cnt < n)
    {
        if (n==0||n==1) break;
        a = a + b;
        a = a^b;
        b = a^b;    
        a = a^b;    //a, b交换数据,b为最新结果
        cnt = cnt + 1;
    }
    c = b;  //输出结果
    printf("斐波那契求和结果为%d\n",c);
    return 0;
}