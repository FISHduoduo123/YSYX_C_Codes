//编写递归函数求Fibonacci数列的第n项，这个数列是这样定义的：
/*fib(0)=1
fib(1)=1
fib(n)=fib(n-1)+fib(n-2)
*/
#include <stdio.h> 
int fid(int a)
{
    if (a==0||a==1) return 1;
    else return fid(a-1) + fid(a-2);
}
int main(void)
{   
    int a=3;
    printf("Fibonacci数列的第%d项为%d\n",a,fid(a));
    return 0;
}