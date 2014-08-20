#include <stdlib.h>
#include <stdio.h>


/* 逆置数组 arr[0..i] */
void flip(int arr[], int i)
{
	int temp, start = 0;

	while (start < i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}

/* 找出 arr[0..n-1] 内最大的元素的下标 */
int findMax(int arr[], int n)
{
	int mi, i;
	for (mi = 0, i = 0; i < n; ++i)
		if (arr[i] > arr[mi])
			mi = i;
	return mi;
}

void pancakeSort(int *arr, int n)
{
	// 每次翻转可以定位一个做大的元素
	for (int curr_size = n; curr_size > 1; --curr_size)
	{
		// 在 arr[0..curr_size-1] 找到最大的元素
		int mi = findMax(arr, curr_size);
		//记性两次flip操作，将最大的元素翻转到最后
		if (mi != curr_size-1)
		{
			flip(arr, mi);
			flip(arr, curr_size-1);
		}
	}
}

/* 打印数组 */
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
}
int main()
{
	int arr[] = {23, 10, 20, 11, 12, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	pancakeSort(arr, n);
	puts("Sorted Array ");
	printArray(arr, n);
	puts("\n");
	return 0;
}

