/*
编写一个函数double mypow(double x, int n);求x的n次方，参数n是正整数。最简单的算法是：
	double product = 1;
	for (i = 0; i < n; i++)
	product *= x;
请分别用递归和循环实现这个算法。
*/
double mypow_iterative(double x, int n) {
    double result = 1.0;
    double base = x;
    int exp = n;
    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

double mypow_recursive(double x, int n) {
    // 递归基：任何数的0次方为1（题目保证n为正整数，但为完备性保留）
    if (n == 0) return 1.0;
    
    // 处理负数指数（若需要，但题目n为正整数，可选）
    // if (n < 0) return 1.0 / mypow_recursive(x, -n);
    
    // 偶数情况：x^n = (x^(n/2))^2
    if (n % 2 == 0) {
        double half = mypow_recursive(x, n / 2);
        return half * half;
    } 
    // 奇数情况：x^n = x * x^(n-1)
    else {
        return x * mypow_recursive(x, n - 1);
    }
}