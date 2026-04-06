/*
在本节的基础上实现一个打印复数的函数，打印的格式是x+yi，
如果实部或虚部为0则省略，例如：1.0、-2.0i、-1.0+2.0i、1.0-2.0i。
最后编写一个main函数测试本节的所有代码。想一想这个打印函数应该属于上图中的哪一层？
*/
#include <stdio.h>
#include <math.h>
// 提供复数存储表示层
//复数变量类型
struct complex_struct {
	double x, y;
};
//复数直角坐标提取
double real_part(struct complex_struct z)
{
	return z.x;
}
double img_part(struct complex_struct z)
{
	return z.y;
}
//复数极坐标提取
double magnitude(struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}
double angle(struct complex_struct z)
{
	return atan2(z.y, z.x);
}
//复数构造
struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}
struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}
//提供复数运算层
struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}

//复数打印(属于第二层，调用底层存储层并执行数据操作)
void complex_print(struct complex_struct z1)
{   
    printf("%f+%fi/n",real_part(z1),img_part(z1));
}

int main(void)
{
    struct complex_struct a = {1.0,1.0};    // 定义并初始化复数变量 a
    complex_print(a);   // 打印 a
    struct complex_struct b = {2.0,2.0};    // 定义并初始化复数变量 b
    complex_print(b);   // 打印 b

    //运算操作并打印
    complex_print(add_complex(a,b));    // add
    complex_print(sub_complex(a,b));    // sub
    complex_print(mul_complex(a,b));    // mul
    complex_print(div_complex(a,b));    // div
    return 0;
}
