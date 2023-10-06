#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <windows.h>

using namespace std;

int Check()
{
	int in; rewind(stdin);
	while (scanf_s("%d", &in) != 1)
		rewind(stdin), printf_s("\nНеверные данные, введите повторно: ");
	return in;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	stack<char> st; queue<char> qu; string pal; size_t cnt = 0;

	cout << "Самодуров ДИНРБ-21/2\nВариант 7\n\n\n";
	cout << "Для выхода напишите \"1488\"\n";

	do
	{
		cout << "\nВведите слово или число для проверки его на палиндром: "; cin >> pal;
		if (pal != "1488")
		{
			cnt = size(pal);

			for (auto simv : pal) st.push(simv), qu.push(simv);

			for (size_t i = 0; i < cnt; ++i)
			{
				if (st.top() == qu.front()) st.pop(), qu.pop();
				else
				{
					cout << "\nНе палиндром\n"; break;
				}
			}
			if (st.empty()) cout << "\nПалиндром\n";
			else 
			{
				cout << "Не хватает символа: " << st.top() << " или " << qu.front() << "\n";
				while (!st.empty()) st.pop(), qu.pop();
			}

			pal = "";
		}
	} while (pal != "1488");
}

//class Plane
//{
//private:
//	int index;
//	bool isOnLand, isBoarding, isTakeoff;
//public:
//	Plane() : index(0), isOnLand(0), isBoarding(0), isTakeoff(0) {};
//		
//};
//
//class Runway
//{
//private:
//	int allPlaneCount, currentPlaneCount, landingCount, takeoffRequestCount;
//	void CountingPlanes()
//	{
//		int oldCount = currentPlaneCount;
//		currentPlaneCount = landingCount - takeoffRequestCount;
//		if (currentPlaneCount - oldCount > 0) allPlaneCount += currentPlaneCount;
//	}
//public:
//	Runway() : allPlaneCount(0), currentPlaneCount(0), landingCount(0), takeoffRequestCount(0) {};
//	Runway(int land, int request) : landingCount(land), takeoffRequestCount(request) { allPlaneCount = currentPlaneCount = land; }
//
//	void Set(const int plane)
//	{
//		landingCount = plane;
//		CountingPlanes();
//	}
//	void Set(const int plane, const int req)
//	{
//		landingCount = plane;
//		takeoffRequestCount = req;
//		CountingPlanes();
//	}
//
//};

int Request(int mean)
{
	random_device rd; //генератор случайных чисел. 
	mt19937 gen(rd()); //генератор псевдослучайных чисел, который инициализируется случайным числом rd().
	poisson_distribution<>distr(mean); //создание объекта для генерации случайных чисел с распределением Пуассона при заданном среднем (ожидаемом) значении mean.
	return distr(gen);//генерирование случайного числа с распределением Пуассона с заданным параметром mean.
}

void Start(int& meanB, int& meanT, int& maxBoarding, int& maxTakeoff, int& time)
{
	cout << "Введи максимальное количество запросов на\nПосадку: "; maxBoarding = Check();
	cout << "Взлёт: "; maxTakeoff = Check();
	cout << "Введи время для моделирования запросов (значение, как час реального времени): "; time = Check();
	cout << "Введи предполагаемое (ожидаемое) число самолётов\nПрилетающих: "; meanB = Check();
	cout << "Взлетающих: "; meanT = Check();
}

//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	cout << "Самодуров ДИНРБ-21/2\nВариант 7\n\n\n";
//
//	int meanB, meanT, mB, mT, maxBoarding, maxTakeoff, time,
//		landCount = 0, takeoffCount = 0;
//	queue<int> qB, qT;
//	Start(meanB, meanT, maxBoarding, maxTakeoff, time);
//
//	int boardCountRequests = 0, takeoffCountRequests = 0,
//		acceptedBoardRequest = 0, acceptedTakeoffRequest = 0,
//		allBoardCount = 0, allTakeoffCount = 0,
//		rejectedBoardRequest = 0, rejectedTakeoffRequest = 0,
//		allTimeWaiting = 0, downtime = 0;
//
//	for (int i = 0; i < time; ++i)
//	{
//		mB = Request(meanB), mT = Request(meanT);
//
//		for (int i = 0; i < mB; ++i, qB.push(1), ++boardCountRequests);
//		for (int i = 0; i < mT; ++i, qT.push(1), ++takeoffCountRequests);
//
//		if (qB.empty() && qT.empty()) ++downtime;
//
//		if (!qB.empty())
//			for (int i = landCount; i < maxBoarding && !qB.empty(); ++i, ++landCount, ++acceptedBoardRequest, ++allBoardCount, qB.pop());
//		if (!qT.empty())
//			for (int i = takeoffCount; i < maxTakeoff && !qT.empty(); ++i, ++takeoffCount, --landCount, ++acceptedTakeoffRequest, ++allTakeoffCount, qT.pop());
//
//		if (!qB.empty())
//		{
//			cout << endl << qB.size() << " отправили на другой аэропорт\n";
//			while (!qB.empty()) qB.pop(), ++rejectedBoardRequest;
//		}
//		if (!qT.empty())
//		{
//			cout << endl << qT.size() << " задержали взлёт\n";
//			while (!qT.empty()) qT.pop(), ++rejectedTakeoffRequest;
//			takeoffCount = 0;
//			allTimeWaiting += rejectedTakeoffRequest;
//		}
//	}
//
//	cout << "\n\nОбщее количество запросов: " << boardCountRequests + takeoffCountRequests;
//	cout << "\n\nКоличество запросов на\nПосадку: " << boardCountRequests << "\nВзлёт: " << takeoffCountRequests;
//	cout << "\n\nКоличество принятых запросов на\nПосадку: " << acceptedBoardRequest << "\nВзлёт: " << acceptedTakeoffRequest;
//	cout << "\n\nКоличество\nПриземлившихся: " << allBoardCount << "\nВзлетевших: " << allTakeoffCount;
//	cout << "\n\nКоличество отказов на\nПосадку: " << rejectedBoardRequest << "\nВзлёт: " << rejectedTakeoffRequest;
//	cout << "\n\nОбщее время ожидания самолётов: " << allTimeWaiting;
//	cout << "\n\nОбщее время простоя: " << (time/100)*downtime << "%";
//	cout << "\n\nСреднее количество запросов в час на\nПосадку: " << boardCountRequests / time << "\nВзлёт: " << takeoffCountRequests / time << endl;
//
//	return 0;
//}
