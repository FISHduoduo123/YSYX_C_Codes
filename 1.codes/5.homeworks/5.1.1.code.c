//编写一个布尔函数int is_leap_year(int year)，
//判断参数year是不是闰年。如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，
//此外，能被400整除的年份也是闰年。
#include <stdio.h> 
int is_leap_year(int year)
{
    return (!(year%4)&&(year%100))||!(year%400);
}
int main(void)
{   
    int i;
    i = 2017;
    if (is_leap_year(i)) printf("闰年\n");
    else printf("平年\n");
	return 0;
}