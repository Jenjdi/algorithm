#include"head.h"
void q2()
{
	int value = 1024;
	char condition = *((char*)(&value));
	if (condition) value += 1; condition = *((char*)(&value));
	if (condition) value += 1; condition = *((char*)(&value));
	printf("%d %d", value, condition);
}
