#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
	
	long int* push_List(long int*, int, int);
	long int* pop_List(long int*, int, int);
	bool isEmpty(int);;
};

int main()
{
	Stack stack;

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
				pointer_List = stack.push_List(pointer_List, size, num);
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
				pointer_List = stack.pop_List(pointer_List, size, num);
				size--;

			}
		}

		if (order == "size")
		{
			cout << size << endl;
		}

		if (order == "empty")
		{
			cout << stack.isEmpty(size) << endl;
		}

		if (order == "top")
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

long int* Stack::push_List(long int* p, int size, int num)
{
	long int* new_List = new long int[size + 1];

	new_List[0] = num;

	for (int i = 0; i < size; i++)
	{
		new_List[i + 1] = p[i];
	}

	delete[] p;
	return new_List;

};

long int* Stack::pop_List(long int* p, int size, int num)
{
	long int* new_List = new long int[size-1];


	for (int i = 0; i < size-1; i++)
	{
		new_List[i] = p[i+1];
	}

	delete[] p;
	return new_List;

};

bool Stack::isEmpty(int num)
{
	if (num == 0)
		return true;
	else
		return false;
};
