//自己实现一个strcpy函数，尽可能简洁，按照本书的编码风格你能用三行代码写出函数体吗？
#include <stdio.h>
void strcpy(char * a,char * b)
{   
    int num = 0;
    for (int i=0;b[i]!='\0';i++) 
    {
        num = i;
        a[i] = b[i];
    }
    a[num+1] = '\0';
}

int main(void)
{
    char a[3]="hi";
    char b[3];
    strcpy(b,a);
    printf("%s\n",b);
    return 0;
}