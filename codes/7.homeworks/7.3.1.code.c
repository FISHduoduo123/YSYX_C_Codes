//添加enum枚举成员变量作为构造函数类型选择控制变量
// 提供复数存储表示层
//复数变量类型
enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};
//复数直角坐标提取
double real_part(struct complex_struct z)
{
	return z.a;
}
double img_part(struct complex_struct z)
{
	return z.b;
}
//复数极坐标提取
double magnitude(struct complex_struct z)
{
	return sqrt(z.a * z.a + z.b * z.b);
}
double angle(struct complex_struct z)
{
	return atan2(z.a, z.a);
}
//复数构造
struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}