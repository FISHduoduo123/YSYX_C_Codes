/*编一个函数，输入一个字符串，要求做一个新字符串，把其中所有的一个或多个连续的空白字符都压缩为一个空格。这里所说的空白包括空格、'\t'、'\n'、'\r'。例如原来的字符串是：

This Content hoho       is ok
        ok?

        file system
uttered words   ok ok      ?
end.
压缩了空白之后就是：

This Content hoho is ok ok? file system uttered words ok ok ? end.
实现该功能的函数接口要求符合下述规范：
*/
#include <stdio.h>
#include <string.h>

char *shrink_space(char *dest, const char *src, size_t n)
{
    int num;
    for (int i=0;i<n;i++)
    {
        dest[i] = src[i];
        num = i;
    }
    dest[num+1] = '\0';
    return dest;
}

int main(void) {
    char dest[5];
    char s[4] = "123";
    printf("data:%s\n",shrink_space(dest,s,3));
    return 0;
}
