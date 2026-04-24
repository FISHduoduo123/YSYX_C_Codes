//定义一个数组，编程打印它的全排列
/*
#define N 3
int a[N] = { 1, 2, 3 };
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
int a[N] = { 1, 2, 3, 4};

void list(int basic)
{
    //判断否抵达索引边界并打印当前排列数组
    if(basic==N-1) 
    {
        for(int i=0;i<N;i++)printf("%d",a[i]);
        printf("\n");
        return;
    }
    for(int j=basic;j<N;j++)
    {
        int swap = 0;
        //将当前基元素与遍历元素替换
        swap = a[basic];
        a[basic] = a[j];
        a[j] = swap;
        list(basic+1);  // 移动至下一个基元素
        //恢复初始数组
        swap = a[basic];
        a[basic] = a[j];
        a[j] = swap;
    }
    return;
}
int main(void)
{
    list(0);
    return 0;
}