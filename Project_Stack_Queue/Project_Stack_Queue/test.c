#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
#include"Queue.h"

int main() 
{
	/*ST pst ;
	STInit(&pst);
	STPush(&pst, 1);
	printf("%d\n", pst.a[pst.top - 1]);
	STPush(&pst, 2);
	
	return 0;*/

	Queue pq;
	QueueInit(&pq);
	QueuePush(&pq, 1);
	QueuePush(&pq, 5);
	printf("%d ", pq.phead->val);
	printf("%d ",pq.ptile->val);
	printf("%d\n", pq.size);

	QueuePop(&pq);
	printf("%d ", pq.phead->val);
	printf("%d ", pq.ptile->val);
	printf("%d\n", pq.size);



}