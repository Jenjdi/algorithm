#include"Sort.h"
void swap(int* a1, int* a2)
{
	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}
void selectsort(int* arr, int n)
{
	int begin = 0, end = n - 1;
	while (begin <= end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (arr[min] > arr[i])
			{
				min = i;
			}
			if (arr[max] < arr[i])
			{
				max = i;
			}
		}
		swap(&arr[min], &arr[begin]);
		if (max == begin)
		{
			max = min;
		}
		swap(&arr[max], &arr[end]);
		begin++;
		end--;
	}
}