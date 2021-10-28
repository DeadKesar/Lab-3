//TODO: написать функцию сортировки массива.
#include <iostream>
#include <iomanip>

//заполняем мвссив случайными числами
int* CreateArray(int size);
//рекурсивный вызов сортировки
void SortArray(int* arr, int lenght,int start = 0);
//сортирует нечётные длины
void SortOddLength(int lenght, int start, int* arr);
//сортирует чётные длины
void SortEvenLength(int lenght, int start, int* arr);
// печатаем наш массив
void PrintArr(const int arr[], int size);

using namespace std;

int main()
{
	int const SIZE = 100;//количество сортируемых чисел
	int* arr = CreateArray(SIZE);
	//выводим числа до сортировки
	PrintArr(arr, SIZE);
	cout << endl << "_______________" << endl;
	SortArray(arr, SIZE);
	//выводим числа после сортировки
	PrintArr(arr, SIZE);	delete[] arr;
	return 0;
}
//заполняет масив случайными числами.
int* CreateArray(int size)
{
	srand(static_cast<int>(time(0)));
	int *arr = new int[size]();
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	return arr;
}
//рекурсивный вызов сортировки
void SortArray(int* arr, int length, int start)
{
	if (length > 1)
	{
		if (length % 2 == 0)
		{
			SortArray(arr, length / 2, start);	//идём влево
			SortArray(arr, length / 2, start + length / 2);	 //идём вправо
			return SortEvenLength(length, start, arr);
		}
		else
		{
			SortArray(arr, length / 2, start); //идём влево
			SortArray(arr, length / 2 + 1, start + length / 2); //идём вправо
			return SortOddLength(length, start, arr);
		}
	}
}
//сортирует нечётные длины
void SortOddLength(int length, int start, int* arr)
{
	int* tempArr = new int[length];
	for (int tempIndex = 0, leftIndex = start, rightIndex = start + length / 2;
		tempIndex < length; tempIndex++)
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
		if (leftIndex >= start + length / 2)
		{
			tempIndex++;
			for (tempIndex; tempIndex < length; tempIndex++)
			{
				tempArr[tempIndex] = arr[rightIndex];
				rightIndex++;
			}
		}
		if (rightIndex >= start + length && tempIndex < length)
		{
			tempIndex++;
			for (tempIndex; tempIndex < length; tempIndex++)
			{
				tempArr[tempIndex] = arr[leftIndex];
				leftIndex++;
			}
		}
	}
	for (int baseIndex = start, tempIndex = 0; tempIndex < length;
		baseIndex++, tempIndex++)
	{
		arr[baseIndex] = tempArr[tempIndex];
	}
	delete[] tempArr;
	return;
}
//сортирует чётные длины
void SortEvenLength(int length, int start, int* arr)
{
	int *tempArr = new int[length];
	for (int tempIndex = 0, leftIndex = start, rightIndex = start + length / 2;
		tempIndex < length; tempIndex++)
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
		if (leftIndex >= start + length / 2)
		{
			tempIndex++;
			for (tempIndex; tempIndex < length; tempIndex++)
			{
				tempArr[tempIndex] = arr[rightIndex];
				rightIndex++;
			}
		}
		if (rightIndex >= start + length && tempIndex < length)
		{
			tempIndex++;
			for (tempIndex; tempIndex < length; tempIndex++)
			{
				tempArr[tempIndex] = arr[leftIndex];
				leftIndex++;
			}
		}

	}
	for (int baseIndex = start, tempIndex = 0; tempIndex < length;
		baseIndex++, tempIndex++)
	{
		arr[baseIndex] = tempArr[tempIndex];
	}
	delete[] tempArr;
	return;
}
// выводим массив на экран
void PrintArr(const int arr[], int size)
{
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << arr[i] << "| ";
		if (count % 20 == 0)
			cout << endl;
		count++;
	}
	cout << endl;
}
