#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 输出数组
void printAll(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 冒泡排序
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// 选择排序
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}

//插入排序
void insertionSort(int a[], int n)
{
    int j;
    for (int i = 1; i < n; i++)
    {
        // 取出当前位
        int data = a[i];
        // 循环向前比较
        for (j = i - 1; j >= 0; j--)
        {
            // 当前data小于等于前一个，前一个后移 如果前一个为0，赋值
            if (data <= a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = data;
    }
}

// 希尔排序
void shellSort(int a[], int n)
{
    // 分组 增量gap 逐步减小
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        // 从第gap个元素，逐个对其所在组进行排序操作
        for (int i = gap; i < n; i++)
        {
            int j = i;
            int data = a[j];
            // 如果大于前一个就不用比较
            // 交换 与本组的前一个比较
            while (j - gap >= 0 && data < a[j - gap])
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = data;
        }
    }
}

/**
 * count从0开始，num从1开始
 * 
 */
void merge(int a[], int left, int mid, int right)
{
    int *temp;
    temp = (int *)malloc((right - left + 1) * sizeof(int));

    if (!temp)
    {
        abort();
        // name       : abort 
        // function   : 异常终止一个进程 
        // declare    : void abort(void); 
        // include    ：#include <stdlib.h> 
        // explanation：abort函数是一个比较严重的函数，当调用它时，会导致程序异常终止，而不会进行一些常规的清除工作，比如释放内存等。 
    }
    int k = 0, i, j;
    for (i = left, j = mid + 1; i <= mid && j <= right;)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }

    if (i == mid + 1)
    { // i到尽头检查j
        while (j <= right)
        {
            temp[k++] = a[j++];
        }
    }
    else
    {
        //j到尽头检查i
        while (i <= mid)
        {
            temp[k++] = a[i++];
        }
    }
    // 赋值失败 形参作用域
    // a = temp;
    memcpy(a + left, temp, (right - left + 1) * sizeof(int));
    // 原型：extern void *memcpy(void *dest, void *src, unsigned int count);
    // 用法：#include <string.h>
    // 功能：由src所指内存区域复制count个字节到dest所指内存区域。
    // 说明：src和dest所指内存区域不能重叠，函数返回指向dest的指针。
    free(temp);
}

// 归并排序
void mergeSort(int a[], int left, int right)
{
    // 递归终止条件
    if (left >= right)
    {
        return;
    }

    // 取left到right之间的中间位置mid
    int mid = (left + right) / 2;
    // 分治递归
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    // 将A[p...q]和A[q+1...r]合并为A[p...r]
    merge(a, left, mid, right);
}

int main(int argc, char const *argv[])
{
    // https://www.cnblogs.com/xiongxx/p/6239213.html
    printf("This is bubbleSort\n");
    int n = 10;
    int a[n] = {22, 3, 12, 34, 5, 6, 5, 89, 63, 24};
    // bubbleSort(a, n);
    // selectionSort(a, n);
    // insertionSort(a, n);
    // shellSort(a, n);
    // mergeSort(a, 0, n - 1);
    printAll(a, n);
    return 0;
}