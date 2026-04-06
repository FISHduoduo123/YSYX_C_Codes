//实现一个算法，在一组随机排列的数中找出最小的一个
int find_min(int *arr, int len) {
    int min = arr[0];
    for (int i = 1; i < len; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}