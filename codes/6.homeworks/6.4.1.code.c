/*求素数这个程序只是为了说明break和continue的用法才这么写的，
其实完全可以不用break和continue，请读者修改一下控制流程，
去掉break和continue而保持功能不变。*/
#include <stdio.h>
int main() 
{
    // 打印1~100所有素数，大于1并且只能被自身和1整除的自然数
    for(int i=1;i<=100;i++) 
    {
        int s = 1; // 1=素数 
        int j = 1; //循环变量
        while (j<=100)
        {
            if (!(i%j)&&(j!=1)&&(j!=i)) 
            {
                s = 0;   //设置非素数
                j = 100; //设置循环变量最大值结束循环
            }
            j++;
        }
        if (s&&(i>1)) printf("素数：%d\n", i); //素数
        else s = 1;  
    }
    
    return 0;
}