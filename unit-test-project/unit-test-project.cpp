#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/rainfall.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	rainfall_sub* osadki(int day, int month, int kol) {
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
			subscriptions[0] = osadki(02, 8, 10);
			subscriptions[1] = osadki(04, 8, 21);
			subscriptions[2] = osadki(06, 8, 15);
			Assert::AreEqual(46, process(subscriptions, 3, 8));
			delete_subscription(subscriptions, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			rainfall_sub* subscriptions[5];
			subscriptions[0] = osadki(01, 11, 10);
			subscriptions[1] = osadki(02, 11, 21);
			subscriptions[2] = osadki(03, 11, 22);
			subscriptions[3] = osadki(06, 11, 18);
			subscriptions[4] = osadki(18, 11, 19);
			Assert::AreEqual(90, process(subscriptions, 5, 11));
			delete_subscription(subscriptions, 5);
		}
		TEST_METHOD(TestMethod3)
		{
			rainfall_sub* subscriptions[10];
			subscriptions[0] = osadki(01, 1, 2);
			subscriptions[1] = osadki(02, 1, 3);
			subscriptions[2] = osadki(04, 1, 6);
			subscriptions[3] = osadki(05, 1, 10);
			subscriptions[4] = osadki(06, 1, 11);
			subscriptions[5] = osadki(11, 1, 24);
			subscriptions[6] = osadki(13, 1, 8);
			subscriptions[7] = osadki(15, 1, 21);
			subscriptions[8] = osadki(19, 1, 40);
			subscriptions[9] = osadki(13, 1, 18);
			Assert::AreEqual(143, process(subscriptions, 10, 1));
			delete_subscription(subscriptions, 10);
		}
		TEST_METHOD(TestMethod4)
		{
			rainfall_sub* subscriptions[9];
			subscriptions[0] = osadki(01, 3, 5);
			subscriptions[1] = osadki(02, 3, 2);
			subscriptions[2] = osadki(04, 3, 8);
			subscriptions[3] = osadki(05, 3, 14);
			subscriptions[4] = osadki(06, 3, 11);
			subscriptions[5] = osadki(11, 3, 24);
			subscriptions[6] = osadki(13, 3, 8);
			subscriptions[7] = osadki(15, 3, 20);
			subscriptions[8] = osadki(19, 3, 40);
			Assert::AreEqual(132, process(subscriptions, 9, 3));
			delete_subscription(subscriptions, 9);
		}
	};
}
