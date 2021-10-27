//TODO: написать функцию сортировки массива.

#include <iostream>

int* CreateArray(int size);
void SortArray(int* arr, int lenght,int start);

using namespace std;

int main()
{
	int const SIZE = 10;
	//int* arr = CreateArray(SIZE);
	int arr[]{ 1,5,2,3,4,7,9,8,2,1 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl<< "_______________"<< endl;

	SortArray(arr, SIZE,0);
   	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

//заполняет масив случайными числами.
int* CreateArray(int size)
{
	srand(static_cast<int>(time(0)));
	int* arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	return arr;
}

void SortArray(int* arr, int lenght, int start = 0)
{
	if (lenght > 1)
	{
		if (lenght % 2 == 0)
		{
			SortArray(arr, lenght / 2, start);
			SortArray(arr, lenght / 2, lenght / 2);
		}
		else
		{
			SortArray(arr, lenght / 2, start);
			SortArray(arr, lenght / 2 + 1, lenght / 2+1);
		}
	}
	else
	{
		return;
	}
	if (lenght % 2 == 0)
	{
		int* tempArr = new int[lenght];
		for (int tempIndex = 0, leftIndex = start, rightIndex = start+lenght / 2; tempIndex < lenght; tempIndex++)
		{
			if (arr[leftIndex] <= arr[rightIndex])
			{
				tempArr[tempIndex] = arr[leftIndex];
				leftIndex++;
			}
			else
			{
				tempArr[tempIndex] = arr[rightIndex];
				rightIndex++;
			}
			if (leftIndex >= start + lenght / 2)
			{
				tempIndex++;
				for (tempIndex; tempIndex < lenght; tempIndex++)
				{
					tempArr[tempIndex] = arr[rightIndex];
					rightIndex++;
				}
			}
			if (rightIndex >= start + lenght / 2 && tempIndex < lenght)
			{
				tempIndex++;
				for (tempIndex; tempIndex < lenght; tempIndex++)
				{
					tempArr[tempIndex] = arr[leftIndex];
					leftIndex++;
				}
			}
		}
		for (int baseIndex = start, tempIndex = 0; baseIndex < lenght; baseIndex++, tempIndex++)
		{
			arr[baseIndex] = tempArr[tempIndex];
		}
		delete[] tempArr;
		return;
	}
	else
	{
		int* tempArr = new int[lenght];
		for (int tempIndex = 0, leftIndex = start, rightIndex = start + lenght / 2 + 1; tempIndex < lenght; tempIndex++)
		{
			if (arr[leftIndex] >= arr[rightIndex])
			{
				tempArr[tempIndex] = arr[leftIndex];
				leftIndex++;
			}
			else
			{
				tempArr[tempIndex] = arr[rightIndex];
				rightIndex++;
			}
			if (leftIndex >= start + lenght / 2)
			{
				tempIndex++;
				for (tempIndex; tempIndex < lenght; tempIndex++)
				{
					tempArr[tempIndex] = arr[rightIndex];
					rightIndex++;
				}
			}
			if (rightIndex >= start + lenght / 2+1 && tempIndex < lenght)
			{
				tempIndex++;
				for (tempIndex; tempIndex < lenght; tempIndex++)
				{
					tempArr[tempIndex] = arr[leftIndex];
					leftIndex++;
				}
			}
		}
		for (int baseIndex = start, tempIndex = 0; baseIndex < lenght; baseIndex++, tempIndex++)
		{
			arr[baseIndex] = tempArr[tempIndex];
		}
		delete[] tempArr;
		return;
	}
}