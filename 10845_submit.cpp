#include <iostream>
#include <string>

using namespace std;


class Queue {
public:
	long int* push_List(long int* p, int size, int num);
	long int* pop_List(long int* p, int size, int num);
	bool isEmpty(int);

};

int main(){
	Queue queue;

	int num;
	string order;
	int size = 0;
	int count;
	long int* pointer_List = new long int[1];

	cin >> count;

	for (int t = count; t > 0; t--)
	{
		cin >> order;

		if (order == "push")
		{
			cin >> num;
			if (size == 0)
			{
				pointer_List[0] = num;
				size++;
			}
			else
			{
				pointer_List = queue.push_List(pointer_List, size, num);
				size++;
			}
		}

		if (order == "pop")
		{
			if (size == 0)
			{
				pointer_List[0] = 0;
				cout << (-1) << endl;
			}
			else
			{
				cout << pointer_List[0] << endl;
				pointer_List = queue.pop_List(pointer_List, size, num);
				size--;

			}
		}

		if (order == "size")
		{
			cout << size << endl;
		}

		if (order == "empty")
		{
			cout << queue.isEmpty(size) << endl;
		}

		if (order == "back")
		{
			if (size == 0)
			{
				pointer_List[0] = 0;
				cout << (-1) << endl;
			}
			else
				cout << pointer_List[size-1] << endl;
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
	return 0;
};

long int* Queue::push_List(long int* p, int size, int num)
{
	long int* new_List = new long int[size + 1];

	for (int i = 0; i < size; i++)
	{
		new_List[i] = p[i];
	}

	new_List[size] = num; 

	delete[] p;
	return new_List;

};

long int* Queue::pop_List(long int* p, int size, int num)
{
	long int* new_List = new long int[size - 1];


	for (int i = 0; i < size - 1; i++)
	{
		new_List[i] = p[i + 1];
	}

	delete[] p;
	return new_List;

};

bool Queue::isEmpty(int num)
{
	if (num == 0)
		return true;
	else
		return false;
};
