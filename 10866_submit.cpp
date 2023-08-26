#include <iostream>
#include <string>

using namespace std;

class Deque {
public:
	long int* pushBack_List(long int*, int, int);
	long int* pushFront_List(long int*, int, int);
	long int* popBack_List(long int*, int, int);
	long int* popFront_List(long int*, int, int);

	bool isEmpty(int);
};

int main()
{
	Deque deque;

	int num;
	string order;
	int size = 0;
	int count;
	long int* pointer_List = new long int[1];

	cin >> count;

	for (int t = count; t > 0; t--)
	{
		cin >> order;
		if (order == "push_back")
		{
			cin >> num;
			if (size == 0)
			{
				pointer_List[0] = num;
				size++;
			}
			else
			{
				pointer_List = deque.pushBack_List(pointer_List, num, size);
				size++;
			}
		}

		if (order == "push_front")
		{
			cin >> num;
			if (size == 0)
			{
				pointer_List[0] = num;
				size++;
			}
			else
			{
				pointer_List = deque.pushFront_List(pointer_List, num, size);
				size++;
			}
		}

		if (order == "pop_back")
		{
			if (size == 0)
			{
				pointer_List[0] = 0;
				cout << (-1) << endl;
			}
			else
			{
				cout << pointer_List[size - 1] << endl;
				pointer_List = deque.popBack_List(pointer_List, num, size);
				size--;
			}
		}

		if (order == "pop_front")
		{
			if (size == 0)
			{
				pointer_List[0] = 0;
				cout << (-1) << endl;
			}
			else
			{
				cout << pointer_List[0] << endl;
				pointer_List = deque.popFront_List(pointer_List, num, size);
				size--;

			}
		}

		if (order == "size")
		{
			cout << size << endl;
		}

		if (order == "empty")
		{
			cout << deque.isEmpty(size) << endl;
		}

		if (order == "back")
		{
			if (size == 0)
			{
				pointer_List[0] = 0;
				cout << (-1) << endl;
			}
			else
				cout << pointer_List[size - 1] << endl;
		}

		if (order == "front")
		{
			if (size == 0)
			{
				pointer_List[0] = 0;
				cout << (-1) << endl;
			}
			else
				cout << pointer_List[0] << endl;
		}

	}
	delete[] pointer_List;
	return 0;
}

long int* Deque::pushBack_List(long int* p, int num, int size) {

	long int* new_List = new long int[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_List[i] = p[i];
	}

	new_List[size] = num;

	delete[] p;
	return new_List;


};

long int* Deque::pushFront_List(long int* p, int num, int size) {

	long int* new_List = new long int[size + 1];

	new_List[0] = num;

	for (int i = 0; i < size; i++)
	{
		new_List[i + 1] = p[i];
	}

	delete[] p;
	return new_List;

};

long int* Deque::popBack_List(long int* p, int num, int size) {

	if (size == 1) {
		return p;
	}

	else
	{
		long int* new_List = new long int[size - 1];

		for (int i = 0; i < size - 1; i++) {
			new_List[i] = p[i];
		}

		delete[] p;
		return new_List;
	}

};

long int* Deque::popFront_List(long int* p, int num, int size) {

	if (size == 1) {
		return p;
	}

	else
	{
		long int* new_List = new long int[size - 1];

		for (int i = 0; i < size - 1; i++) {
			new_List[i] = p[i + 1];
		}

		delete[] p;
		return new_List;
	}

};

bool Deque::isEmpty(int size) {
	if (size == 0)
		return true;
	else
		return false;
}