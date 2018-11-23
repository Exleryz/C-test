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

// 快速排序分区函数 升序
int partitionAsc(int a[], int left, int right)
{
    int pivot = a[right];
    int temp, i = left;
    for (int j = i; j < right; j++)
    {
        if (a[j] < pivot)
        {
            if (i != j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            i++;
        }
    }
    a[right] = a[i];
    a[i] = pivot;
    return i;
}

// 快速排序
void quickSort(int a[], int left, int right)
{
    printAll(a, 10);
    if (left >= right)
    {
        return;
    }
    int pivot = partitionAsc(a, left, right);
    quickSort(a, left, pivot - 1);
    quickSort(a, pivot + 1, right);
}

void quickSort2(int a[], int l, int r)
{
    int i, j;
    int temp;
    if (l >= r)
        return; /* 只有一个记录或无记录，则无须排序 */
    i = l;
    j = r;
    temp = a[i];
    while (i != j)
    {
        while ((a[j] >= temp) && (j > i))
            j--; /* 从右向左扫描，查找第1个排序码小于temp.key的记录 */
        if (i < j)
            a[i++] = a[j];
        while ((a[i] <= temp) && (j > i))
            i++; /* 从左向右扫描，查找第1个排序码大于temp.key的记录 */
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = temp;            /* 找到R0的最终位置 */
    quickSort(a, l, i - 1); /* 递归处理左区间 */
    quickSort(a, i + 1, r); /* 递归处理右区间 */
}

int partitionDesc(int a[], int left, int right)
{
    int temp, pivot = a[right];
    int i = left;
    for (int j = i; j < right; j++)
    {
        if (a[j] > pivot)
        {
            if (i != j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            i++;
        }
    }
    a[right] = a[i];
    a[i] = pivot;
    return i;
}

// 查找第K大元素(已检验过k在index内, 需要分区算法降序分区)
int findIndexK(int a[], int k, int left, int right)
{
    int pivot = partitionDesc(a, left, right);
    if (k > pivot)
    {
        return findIndexK(a, k, pivot + 1, right);
    }
    if (k < pivot)
    {
        return findIndexK(a, k, left, pivot - 1);
    }
    return pivot;
}

/**
 * 此排序对数据有要求
 * 规定数据在0-10之间
 * 
 * 数组a a的数量
 */
// 计数排序(Counting sort)
void countingSort(int a[], int n)
{
    // 自行定制count
    int count = a[0];
    for (int i = 0; i < n; i++)
    {
        if (count < a[i])
        {
            count = a[i];
        }
    }
    // 构建计数数组
    int c[count] = {0};
    for (int i = 0; i < n; i++)
    {
        c[a[i]]++;
    }
    // 计数数组求和
    for (int i = 1; i < count; i++)
    {
        c[i] = c[i - 1] + c[i];
    }
    // 新建排序数组
    int *temp;
    temp = (int *)malloc((n) * sizeof(int));
    if (!temp)
    {
        abort();
    }
    // 排序
    for (int i = n - 1; i >= 0; i--)
    {
        temp[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    // 赋值给数组a
    memcpy(a, temp, (n) * sizeof(int));
    // 清空 temp
    free(temp);
}

int main(int argc, char const *argv[])
{
    // https://www.cnblogs.com/xiongxx/p/6239213.html
    printf("This is bubbleSort\n");
    int n = 10;
    int k = 5;
    // int a[n] = {22, 3, 12, 34, 5, 6, 5, 89, 63, 24};
    int a[n] = {99, 86, 89, 73, 24, 57, 57, 6, 66, 22};
    // bubbleSort(a, n);
    // selectionSort(a, n);
    // insertionSort(a, n);
    // shellSort(a, n);
    // mergeSort(a, 0, n - 1);
    // quickSort(a, 0, n - 1);
    // printf("%d\n", a[findIndexK(a, k - 1, 0, n - 1)]);
    int count[12] = {1, 1, 1, 1, 2, 6, 5, 8, 2, 0, 4, 5};
    countingSort(count, 12);
    printAll(count, 12);
    // printAll(a, n);
    return 0;
}