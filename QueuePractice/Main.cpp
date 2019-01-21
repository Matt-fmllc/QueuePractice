
#include "pch.h"
#include <iostream>
#include "Queues.h"

#include "TQueue.h"
using namespace QueueTemplate;

void PracticeStandardQ()
{
	int Data[] = { 4, 1, 3, 2 };
	CQueue* Que = new CQueue;
	CQueue_Priority* PQue = new CQueue_Priority;

	printf("\nInput");
	for (int x = 0; x < sizeof(Data) / sizeof(int); x++) {
		printf("\n %d", Data[x]);
	}
	Que->EnQueue(&(Data[0]));
	Que->EnQueue(&(Data[1]));
	Que->EnQueue(&(Data[2]));
	Que->EnQueue(&(Data[3]));

	int Out1 = -1;
	int Out2 = -1;
	int Out3 = -1;
	int Out4 = -1;

	printf("\nOutput");
	Que->DeQueue(&Out1);
	Que->DeQueue(&Out2);
	Que->DeQueue(&Out3);
	Que->DeQueue(&Out4);

	printf("\n %d", Out1);
	printf("\n %d", Out2);
	printf("\n %d", Out3);
	printf("\n %d", Out4);

	printf("\nInput");
	for (int x = 0; x < sizeof(Data) / sizeof(int); x++) {
		printf("\n %d", Data[x]);
	}
	Que->EnQueue(&(Data[0]));
	Que->EnQueue(&(Data[1]));
	Que->EnQueue(&(Data[2]));
	Que->EnQueue(&(Data[3]));


	Out1 = Out2 = Out3 = Out4 = 0;
	printf("\nOutput Reursive");
	Que->DeQueueRecursive(&Out1);
	Que->DeQueueRecursive(&Out2);
	Que->DeQueueRecursive(&Out3);
	Que->DeQueueRecursive(&Out4);

	printf("\n %d", Out1);
	printf("\n %d", Out2);
	printf("\n %d", Out3);
	printf("\n %d", Out4);

	printf("\nInput");
	for (int x = 0; x < sizeof(Data) / sizeof(int); x++) {
		printf("\n %d", Data[x]);
	}
	PQue->EnQueue(&(Data[0]));
	PQue->EnQueue(&(Data[1]));
	PQue->EnQueue(&(Data[2]));
	PQue->EnQueue(&(Data[3]));

	Out1 = Out2 = Out3 = Out4 = 0;
	printf("\nOutput - PriorityQ");
	PQue->DeQueue(&Out1);
	PQue->DeQueue(&Out2);
	PQue->DeQueue(&Out3);
	PQue->DeQueue(&Out4);

	printf("\n %d", Out1);
	printf("\n %d", Out2);
	printf("\n %d", Out3);
	printf("\n %d", Out4);
}

void PracticeTemplateQ()
{
	TQueue<int> Q;

	int iTestVals[1000] = { 0 };
	for (int x = 0; x < 1000; x++) {
		iTestVals[x] = std::rand();
		Q.EnQueue(iTestVals[x]);
	}

	int iRetVal = 0;
	for (int x = 0; x < 1000; x++) {
		Q.DeQueue(iRetVal);
		assert(iRetVal == iTestVals[x]);
	}

	for (int x = 0; x < 10; x++) {
		iTestVals[x] = std::rand();
		Q.EnQueue(iTestVals[x]);
	}
	Q.Clear();

	for (int x = 0; x < 10; x++) {
		iTestVals[x] = std::rand();
		Q.EnQueue(iTestVals[x]);
	}

	for (int x = 0; x < 10; x++) {
		Q.DeQueue(iRetVal);
		assert(iRetVal == iTestVals[x]);
	}
}

void PracticeTemplateQ2()
{
	TQueue<int> Q(TQueue<int>::eQT_DoubleLinked, TQueue<int>::eAT_DynamicMem, -1);

	int iTestVals[1000] = { 0 };
	for (int x = 0; x < 1000; x++) {
		iTestVals[x] = std::rand();
		Q.EnQueue(iTestVals[x]);
	}

	int iRetVal = 0;
	for (int x = 0; x < 1000; x++) {
		Q.DeQueue(iRetVal);
		assert(iRetVal == iTestVals[x]);
	}

	for (int x = 0; x < 10; x++) {
		iTestVals[x] = std::rand();
		Q.EnQueue(iTestVals[x]);
	}
	Q.Clear();

	for (int x = 0; x < 10; x++) {
		iTestVals[x] = std::rand();
		Q.EnQueue(iTestVals[x]);
	}

	for (int x = 0; x < 10; x++) {
		Q.DeQueue(iRetVal);
		assert(iRetVal == iTestVals[x]);
	}
}

int main()
{
	PracticeStandardQ();
	PracticeTemplateQ();
	PracticeTemplateQ2();

	return 0;
}