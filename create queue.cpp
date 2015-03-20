//	—оздайте класс, в котором  есть ostream& operator<<.
//
//	 ласс должен содержать очередь с приоритетом.
//	—оздайте генератор Ч заполнитель очереди случайными числами.
//
//	«аполните priority_queue, использу€ генератор,
//	затем выведите содержимое очереди на экран.

#include <iostream>
#include <time.h>
using namespace std;

class QueuePriority
{
	int* Wait;
	int* Pri;
	int MaxQueueLength;
	int QueueLength;
	bool IsFull();
public:
	QueuePriority(int m);
	~QueuePriority();
	void Add(int c, int p);
	int GetCount();
	friend ostream &operator<<(ostream &os, const QueuePriority& a);
};

void main()
{
	srand(time(NULL));
	QueuePriority QUP(25);

	for (int i = 0; i<15; i++){
		QUP.Add(rand() % 100, rand() % 12);
	}

	cout << QUP;
}

QueuePriority::~QueuePriority()
{
	delete[]Wait;
	delete[]Pri;
}

QueuePriority::QueuePriority(int m)
{
	MaxQueueLength = m;
	Wait = new int[MaxQueueLength];
	Pri = new int[MaxQueueLength];
	QueueLength = 0;
}

bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
	return QueueLength;
}

void QueuePriority::Add(int c, int p)
{
	if (!IsFull()){
		for (int i = 0; i < QueueLength; i++)
		{
			if (Pri[i] > p)
			{
				for (int j = QueueLength; j > i; j--)
				{
					Wait[j] = Wait[j - 1];
					Pri[j] = Pri[j - 1];
				}
				Wait[i] = c;
				Pri[i] = p;
				QueueLength++;
				break;
			}
			if (i == QueueLength - 1)
			{
				Wait[i + 1] = c;
				Pri[i + 1] = p;
				QueueLength++;
				break;
			}
		}
		if (QueueLength == 0)
		{
			Wait[0] = c;
			Pri[0] = p;
			QueueLength++;
		}
	}
}

ostream &operator<<(ostream &os, const QueuePriority& a)
{
	cout << "\n\t\t THE QUEUE \n";
	cout << "\n-------------------------------------\n";
	cout << "Index    ID           Priority \n";
	cout << "\n-------------------------------------\n";
	for (int i = 0; i<a.QueueLength; i++){
		cout << i << "\t" << a.Wait[i] << "\t-\t" << a.Pri[i] << "\n";
	}
	cout << "\n-------------------------------------\n";
	return os;
}