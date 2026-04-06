/*写一个插入排序的函数和一个折半查找的函数。*/
#include <stdio.h>
void swap (int*a,int*b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
int* sort (int*arr,int len)
{
    if (len<=0) 
    {
        printf("长度错误\n");
        return arr;
    }
    // 比较
    for (int i=0;i<len-1;i++)
    {
        if (arr[i]>arr[i+1])
        {
            swap(&arr[i],&arr[i+1]);
            for (int j=i;j>0;j--)
            {
                if (arr[j-1]>arr[j]) swap(&arr[j-1],&arr[j]);
                else continue;
            }
        }
    }
    return arr;
}

int* search(int* arr, int d, int len) {
    int start = 0;
    int last = len - 1;
    while (start <= last) {
        int mid = start + (last - start) / 2;  // 防止溢出
        if (arr[mid] == d) {
            return &arr[mid];
        } else if (arr[mid] > d) {
            last = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return NULL;  // 未找到
}
