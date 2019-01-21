#include "stdafx.h"
#include "CppUnitTest.h"

#include <thread>

#include "..\QueuePractice\TQueue.h"
using namespace QueueTemplate;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueUnitTests
{		
	TEST_CLASS(QueueTemplateUnitTests)
	{
	public:
		TEST_METHOD(EnQSearchDeQSearch_SL_Dyn_Test)
		{
			TQueue<int> Q;

			int iTestVals[1000] = { 0 };
			for (int x = 0; x < 1000; x++) {
				iTestVals[x] = std::rand();
				Q.EnQueue(iTestVals[x]);
			}

			bool bResult = false;
			for (int x = 0; x < 1000; x += 2) {
				bResult = Q.Search(iTestVals[x]);
				Assert::IsTrue(bResult);
			}

			int iRetVal = 0;
			for (int x = 0; x < 1000; x++) {
				Q.DeQueue(iRetVal);
				Assert::AreEqual(iRetVal, iTestVals[x]);
			}
		}

		TEST_METHOD(EnQDeQ_SL_Dyn_Test)
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
				Assert::AreEqual(iRetVal,iTestVals[x]);
			}
		}
		TEST_METHOD(EnQDeQClrEnQDeQ_SL_Dyn_Test)
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
				Assert::AreEqual(iRetVal, iTestVals[x]);
			}

			// add a bunch of values
			for (int x = 0; x < 1000; x++) {
				iTestVals[x] = std::rand();
				Q.EnQueue(iTestVals[x]);
			}
			// clear the Q
			Q.Clear();

			// add a bunch of values
			for (int x = 0; x < 1000; x++) {
				iTestVals[x] = std::rand();
				Q.EnQueue(iTestVals[x]);
			}

			// validate the values
			for (int x = 0; x < 1000; x++) {
				Q.DeQueue(iRetVal);
				Assert::AreEqual(iRetVal, iTestVals[x]);
			}

		}
		TEST_METHOD(EnQDeQ_DL_Dyn_Test)
		{
			TQueue<int> Q(TQueue<int>::eQT_DoubleLinked, TQueue<int>::eAT_DynamicMem,-1);

			int iTestVals[1000] = { 0 };
			for (int x = 0; x < 1000; x++) {
				iTestVals[x] = std::rand();
				Q.EnQueue(iTestVals[x]);
			}

			int iRetVal = 0;
			for (int x = 0; x < 1000; x++) {
				Q.DeQueue(iRetVal);
				Assert::AreEqual(iRetVal, iTestVals[x]);
			}
		}
		TEST_METHOD(EnQDeQClrEnQDeQ_DL_Dyn_Test)
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
				Assert::AreEqual(iRetVal, iTestVals[x]);
			}

			// add a bunch of values
			for (int x = 0; x < 1000; x++) {
				iTestVals[x] = std::rand();
				Q.EnQueue(iTestVals[x]);
			}
			// clear the Q
			Q.Clear();

			// add a bunch of values
			for (int x = 0; x < 1000; x++) {
				iTestVals[x] = std::rand();
				Q.EnQueue(iTestVals[x]);
			}

			// validate the values
			for (int x = 0; x < 1000; x++) {
				Q.DeQueue(iRetVal);
				Assert::AreEqual(iRetVal, iTestVals[x]);
			}

		}

	};
}