#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/rainfall.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	rainfall_sub*test(int day, int month, int kol) {
		rainfall_sub* subscription = new rainfall_sub;
		subscription->OurDay.day = day;
		subscription->OurDay.month = month;
		subscription->OurVolume.volume = kol;
		return subscription;
	}

	void delete_subscription(rainfall_sub* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			rainfall_sub* subscriptions[3];
			subscriptions[0] = test(02, 8, 10);
			subscriptions[1] = test(04, 8, 21);
			subscriptions[2] = test(06, 8, 15);
			Assert::AreEqual(46, process(subscriptions, 3, 8));
			delete_subscription(subscriptions, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			rainfall_sub* subscriptions[5];
			subscriptions[0] = test(01, 11, 10);
			subscriptions[1] = test(02, 11, 21);
			subscriptions[2] = test(03, 11, 22);
			subscriptions[3] = test(06, 11, 18);
			subscriptions[4] = test(18, 11, 19);
			Assert::AreEqual(90, process(subscriptions, 5, 11));
			delete_subscription(subscriptions, 5);
		}
		TEST_METHOD(TestMethod3)
		{
			rainfall_sub* subscriptions[10];
			subscriptions[0] = test(01, 1, 2);
			subscriptions[1] = test(02, 1, 3);
			subscriptions[2] = test(04, 1, 6);
			subscriptions[3] = test(05, 1, 10);
			subscriptions[4] = test(06, 1, 11);
			subscriptions[5] = test(11, 1, 24);
			subscriptions[6] = test(13, 1, 8);
			subscriptions[7] = test(15, 1, 21);
			subscriptions[8] = test(19, 1, 40);
			subscriptions[9] = test(13, 1, 18);
			Assert::AreEqual(143, process(subscriptions, 10, 1));
			delete_subscription(subscriptions, 10);
		}
		TEST_METHOD(TestMethod4)
		{
			rainfall_sub* subscriptions[9];
			subscriptions[0] = test(01, 3, 5);
			subscriptions[1] = test(02, 3, 2);
			subscriptions[2] = test(04, 3, 8);
			subscriptions[3] = test(05, 3, 14);
			subscriptions[4] = test(06, 3, 11);
			subscriptions[5] = test(11, 3, 24);
			subscriptions[6] = test(13, 3, 8);
			subscriptions[7] = test(15, 3, 20);
			subscriptions[8] = test(19, 3, 40);
			Assert::AreEqual(132, process(subscriptions, 9, 3));
			delete_subscription(subscriptions, 9);
		}
	};
}
