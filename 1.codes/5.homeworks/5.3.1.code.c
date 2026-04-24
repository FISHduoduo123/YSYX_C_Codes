//编写递归函数求两个正整数a和b的最大公约数（GCD），
/*使用Euclid算法：
	1.如果a除以b能整除，则最大公约数是b。
	2.否则，最大公约数等于b和a%b的最大公约数。
*/
#include <stdio.h> 
int gcd(int a,int b)
{
    if (a%b) return gcd(b,a%b);
    else return b;
}
int main(void)
{   
    int a, b;
    a = 10;
    b = 4;
    printf("a和b最大公约数为%d\n",gcd(a,b));
    return 0;
}