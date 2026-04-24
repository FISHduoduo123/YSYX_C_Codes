//用rand函数生成[10, 20]之间的随机整数，表达式应该怎么写？
#include <stdio.h>
#include <stdlib.h>
int rand_10_to_20(void)
{   
    int a;
    while(1) 
    {
        a = rand();
        if((a>=10)&&(a<=20))
        {
            return a;
        }
    }
}
int main(void)
{
    for(int i=0;i<10;i++) 
    {
        printf("Rand:%d\n",rand_10_to_20());
    }
	return 0;
}
