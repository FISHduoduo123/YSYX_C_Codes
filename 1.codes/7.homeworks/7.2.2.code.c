/*
实现一个用分子分母的格式来表示有理数的结构体rational以及相关的函数，
rational结构体之间可以做加减乘除运算，
运算的结果仍然是rational。测试代码如下：
    int main(void)
{
	struct rational a = make_rational(1, 8);  a=1/8 
	struct rational b = make_rational(-1, 8);  b=-1/8 
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}
注意要约分为最简分数，例如1/8和-1/8相减的打印结果应该是1/4而不是2/8，
可以利用第 3 节 “递归”练习题中的Euclid算法来约分。
在动手编程之前先思考一下这个问题实现了什么样的数据抽象，抽象层应该由哪些函数组成。
*/
#include <stdio.h>
//取绝对值
int abs(int a)
{
    if (a<0) return -a;
    else return a;
}
// 提供分数存储表示层
//分数变量类型
struct rational {int x, y;};
//分子提取
int num_part(struct rational z)
{
	return z.x;
}
//分母提取
int den_part(struct rational z)
{
	return z.y;
}
//分数构造
struct rational make_rational(int x, int y)
{
	struct rational z;
	z.x = x;
	z.y = y;
	return z;
}

//分数运算层
//递归化简
int gcd_rational(int a,int b)
{
    if (a%b) return gcd_rational(b,a%b);
    else return b;
}
//add
struct rational add_rational(struct rational z1, struct rational z2)
{
    int num_add = (num_part(z1))*(den_part(z2)) + (num_part(z2))*(den_part(z1));
    int den = den_part(z1)*den_part(z2);
    int gcd = gcd_rational(abs(num_add),den); //求最大公约数
	return make_rational(num_add/gcd,den/gcd);
}
//sub
struct rational sub_rational(struct rational z1, struct rational z2)
{
    int num_add = (num_part(z1))*(den_part(z2)) - (num_part(z2))*(den_part(z1));
    int den = den_part(z1)*den_part(z2);
    int gcd = gcd_rational(abs(num_add),den); //求最大公约数
	return make_rational(num_add/gcd,den/gcd);
}
//mul
struct rational mul_rational(struct rational z1, struct rational z2)
{
    int num_mul = num_part(z1)*num_part(z2);
    int den_mul = den_part(z1)*den_part(z2);
    int gcd = gcd_rational(abs(num_mul),den_mul); //求最大公约数
	return make_rational(num_mul/gcd,den_mul/gcd);
}
//div
struct rational div_rational(struct rational z1, struct rational z2)
{
	int num_div = num_part(z1)*den_part(z2);
    int den_div = den_part(z1)*num_part(z2);
    //符号设置
    if(num_div<0 && den_div<0) 
    {
        num_div = -num_div;
        den_div = -den_div;
    }
    else if (den_div<0) //符号移动至分子
    {
        num_div = -num_div;
        den_div = -den_div;
    }
    int gcd = gcd_rational(abs(num_div),den_div); //求最大公约数
	return make_rational(num_div/gcd,den_div/gcd);
}
//分数打印
void print_rational(struct rational z)
{   
    printf("%d/%d\n",num_part(z),den_part(z));
}

int main(void)
{
    struct rational a = make_rational(1, 8);  //a=1/8 
	struct rational b = make_rational(-1, 8);  //b=-1/8 
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}

