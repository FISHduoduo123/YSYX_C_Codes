//以可视化的形式打印直方图
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct int_list {int a[10];};
struct int_list rand_list(struct int_list z)
{   
    for(int i=0;i<10;i++)
    {
        z.a[i] = rand()%10;
    }
    for(int i=0;i<10;i++) printf("%d\t",z.a[i]);//debug
    printf("\n");
    return z;
}
struct int_list howmany(struct int_list z)
{
    for(int i=0;i<10;i++)
    {
        printf("%d:\t",i);
        int cnt = 0;
        for(int j=0;j<10;j++) if(z.a[j]==i) cnt++; // 统计数量
        for(int j=cnt;j>0;j--) printf("*\t");	//打印*
        printf("\n");
    }
}
int main(void)
{
    srand(time(NULL));
    struct int_list list;
    list = rand_list(list);
    howmany(list);
	return 0;
}
