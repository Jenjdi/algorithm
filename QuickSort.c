#include"Sort.h"
void quicksort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		while (left<right&&arr[right]>=arr[key])
		{
			right--;
		}
		while (left<right&&arr[left]<=arr[key])
		{
			left++;
		}
		swap(&arr[left], &arr[right]);
	}
	swap(&arr[right], &arr[key]);

	key = left;
	quicksort(arr, begin, key - 1);
	quicksort(arr, key + 1, end);
}