#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"

void SLTest01()
{
	SL sl;
	SLInit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 1);
	SLPopBack(&sl);
	SLDestroy(&sl);
}

int main()
{
	SLTest01();
	return 0;
}