//2、在一组随机排列的数中找出第二小的，这个问题比上一个稍复杂，你能不能想出Θ(n)的算法？
int find_second_min(int *arr, int len) {
    if (len < 2) return 0;          
    int min1 = arr[0];                    
    int min2 = 0;                   
    for (int i = 1; i < len; ++i) 
    {
        if (arr[i] < min1) 
        {              
            min2 = min1;                  
            min1 = arr[i];
        } 
        else if (arr[i] < min2 && arr[i] != min1) 
        {  
            min2 = arr[i];
        }
    }
    return min2;                          
}