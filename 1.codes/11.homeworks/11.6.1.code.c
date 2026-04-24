/*如果待查找的元素在数组中有多个则返回其中任意一个，以本节定义的数组int a[8] = { 1, 2, 2, 2, 5, 6, 8, 9 };为例，
	如果调用binarysearch(2)则返回3，即a[3]，而有些场合下要求这样的查找返回a[1]，
	也就是说，如果待查找的元素在数组中有多个则返回第一个。请修改折半查找算法实现这一特性。
*/
#include <stdio.h>

#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

int binarysearch(int number)
{
	int mid, start = 0, end = LEN - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		if (a[mid] < number)
			start = mid + 1;
		else if (a[mid] > number)
			end = mid - 1;
		else
        {
            // 返回数组索引
            for (;a[mid-1]==number;mid--);
            return mid;
        }
			
	}
	return -1;
}
int main(void)
{
	printf("%d\n", binarysearch(2));
	return 0;
}