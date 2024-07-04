#include"Sort.h"
int main()
{
	int arr[] = { 231,41,123,5411,2341,2,1,1456,41,213 };
	selectsort(&arr,10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}