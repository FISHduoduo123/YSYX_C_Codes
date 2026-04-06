/*
  编写一个函数double mysqrt(double y);求y的正平方根，参数y是正实数。
  我们用折半查找来找这个平方根，在从0到y之间必定有一个取值是y的平方根，如果我们查找的数x比y的平方根小，
  则x2<y，如果我们查找的数x比y的平方根大，则x2>y，我们可以据此缩小查找范围，
  当我们查找的数足够准确时（比如满足|x2-y|<0.001），就可以认为找到了y的平方根。
*/
//当目标数据y非常大或非常小（接近 0）时，二分法求平方根的迭代次数都会增加。
double mysqrt(double y) {
    if (y <= 0) return -1; // y > 0
    // 确定初始区间：平方根一定在 [0, max(1, y)] 内
    double left = 0.0;
    double right = (y > 1) ? y : 1.0;

    double mid = 0.0;
    double sq = 0.0;
    while (1) {
        mid = (left + right) / 2.0;
        sq = mid * mid;
        if (((sq - y)>0?(sq - y):-(sq - y)) < 0.001)   
            break;
        if (sq < y)
            left = mid;              // 平方根在右半区间
        else
            right = mid;             // 平方根在左半区间
    }
    return mid;
}
