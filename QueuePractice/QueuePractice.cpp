// QueuePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Queues.h"

int main()
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

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
