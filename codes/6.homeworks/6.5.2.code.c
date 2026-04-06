/*编写函数diamond打印一个菱形。如果调用diamond(3, '*')则打印：
	*
*	*	*
	*
*/
#include <stdio.h>
void iamond(int num_char,char a)
{
    if ((num_char+1)%2) printf("请输入奇数");
    int cnt_tab = num_char/2; // 求初始空缺数
    //字符数递增
    for(int i=1;i<=num_char;i+=2) 
    {
        for (int tab=1;tab<=cnt_tab;tab++) printf("\t");
        cnt_tab --; // 更新空缺数
        for (int cnt_char=1;cnt_char<=i;cnt_char++) printf("%c\t",a);
        printf("\n");
    }
    cnt_tab = 1;
    //字符数递减
    for(int i=num_char-2;i>=1;i-=2) 
    {
        for (int tab=1;tab<=cnt_tab;tab++) printf("\t");
        cnt_tab ++; // 更新空缺数
        for (int cnt_char=1;cnt_char<=i;cnt_char++) printf("%c\t",a);
        printf("\n");
    }
    
}
int main() 
{
    iamond(5,'a');
    return 0;
}