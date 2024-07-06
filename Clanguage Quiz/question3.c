#include"head.h"
void q3(int para[100])//在传入参数后，在这里会将para当作一个指针
{
	//sizeof只有传数组名时才会返回大小，否则就会返回变量的大小
	void* p = malloc(100);//
	printf("%d, %d\n", sizeof(para), sizeof(p));
}