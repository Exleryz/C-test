#include <stdio.h>
#include <stdlib.h>

// 冒泡排序
void bubbleSort(int *a, int n)
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
void selectionSort(int *a, int n)
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
void insertionSort(int *a, int n)
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
void shellSort(int *a, int n)
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

// 归并排序
void mergeSort(int *a, int left, int right)
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
    // merge(a[left, mid], A[p... q], A[q + 1...r])
}

/**
 * count从0开始，num从1开始
 * 
 */
void merge(int *a, int left, int mid, int right)
{
    int *temp;
    // temp = (int*)malloc();
    for (int i = left, j = mid + 1; i <= mid; j < right)
    {
        // if (a[i] > a[j])
        // {
        //     merge[countMerge++] = b[countB];
        //     countB++;
        // }
        // else
        // {
        //     merge[countMerge++] = a[i++];
        // }

        // while (countB < numB)
        // {
        //     merge[countMerge++] = b[countB++];
        // }
    }
}

void printAll(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
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
    mergeSort(a, n);
    int numA = 5;
    int numB = 2;
    int aa[numA] = {3, 4, 5, 7, 10};
    int bb[numB] = {2, 9};
    int cc[numA + numB];
    sort(aa, numA, bb, numB, cc);
    printAll(cc, numA + numB);
    return 0;
}