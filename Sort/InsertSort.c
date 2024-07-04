#include"Sort.h"
void insertsort(int* arr,int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = arr[end +1];
		while (end >= 0)
		{
			if (arr[end + 1] < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
			arr[end + 1] = tmp;
		}
	}
}