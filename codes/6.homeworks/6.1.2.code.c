//编写程序数一下1到100的所有整数中出现多少次数字
#include <stdio.h> 
int main(void)
{   
    int i = 1;
    int cnt = 0;
    while (i<=100)
    {
        if (i<10) cnt+=1;       //1~9每次出现1个数字
        else if (i<100) cnt+=2; //10~99每次出现2个数字
        else cnt+=3;            //100出现3个数字
        i++;
    }
    printf("1~100总共出现了%d个数字\n",cnt);//一共出现了192个数字
    return 0;
}