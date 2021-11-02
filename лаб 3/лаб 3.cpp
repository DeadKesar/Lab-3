//TODO: написать функцию сортировки массива.
//merge sort - сортировка слиянием
#include <iostream>
#include <iomanip>
#include <time.h>
#include <random>

//заполняем мвссив случайными числами
int* CreateArray(const int size, const int range);
// вызов сортировки слиянием
void StartMergeSort(int* arr, const int& START, const int& SIZE);
//рекурсивный вызов сортировки
void SortArray(int arr[], int start, int length);
//сортирует часть масива
void SortPath(int arr[], int start, int length);
// заполняем временный масив если один из индексов достиг конца.
void FillTempArr(const int baseArr[], int tempArr[], int baseIndex, int tempIndex, int length);
// печатаем наш массив
void PrintArr(const int arr[], int size);

//вызов сортировки пузырьком
void StartBuble(int*& arr, const int& SIZE, const int& RANGE);
//алгоритм сортировки пузырьком
void SortByBuble(int arr[], int size);

//вызов альтернативной сортировки слиянием
void StartAlternativeMergeSort(int* arr, const int& START, const int& SIZE);
//сортировка вложенным циклом
void AlternativeMergeSort(int arr[], int start, int length);
//сортировка части массива по индексам
void AlternativeSortPath(int arr[], int leftIndex, int rightIndex, int length);

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int const START = 0; // начальный индекс сортировки
	int const SIZE = 100;//количество сортируемых чисел
	int const RANGE = 100000; // диапазон значений
	clock_t timer = clock();
	int* arr = CreateArray(SIZE, RANGE);
	clock_t curent = clock();
	cout << static_cast<double>(curent - timer) / CLOCKS_PER_SEC << " - время генерации массива" << endl;

	StartAlternativeMergeSort(arr, START, SIZE);

	arr = CreateArray(SIZE, RANGE);
	StartMergeSort(arr, START, SIZE);
	//arr = CreateArray(SIZE, RANGE);
	//BubleStart(arr, SIZE, RANGE);
	return 0;
}

#pragma region MergeSort
// вызов сортировки слиянием
void StartMergeSort(int* arr, const int& START, const int& SIZE)
{
	cout << "Сортировка массива, алгоритмом - сортировка слиянием" << endl;
	//выводим числа до сортировки
	//PrintArr(arr, SIZE);
	cout << endl << setfill('-') << setw(80) << '-' << setfill(' ') << endl << endl;
	clock_t timer = clock();
	SortArray(arr, START, SIZE);
	clock_t curent = clock();
	//выводим числа после сортировки
	//PrintArr(arr, SIZE);
	delete[] arr;
	cout << static_cast<double>(curent - timer) / CLOCKS_PER_SEC << endl << endl;
	cout << endl << setfill('=') << setw(80) << '=' << setfill(' ') << endl << endl;
}

//рекурсивный вызов сортировки
void SortArray(int arr[], int start, int length)
{
	if (length > 1)
	{
		SortArray(arr, start, length / 2);	//идём влево
		if (length % 2 == 0)
		{
			SortArray(arr, start + length / 2, length / 2);	 //идём вправо
		}
		else
		{
			SortArray(arr, start + length / 2, length / 2 + 1); //идём вправо
		}
		SortPath(arr, start, length);
	}
}

//сортирует часть массива
void SortPath(int arr[], int start, int length)
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
			FillTempArr(arr, tempArr, rightIndex, tempIndex, length);
			break;
		}
		if (rightIndex >= start + length && tempIndex < length)
		{
			tempIndex++;
			FillTempArr(arr, tempArr, leftIndex, tempIndex, length);
			break;
		}
	}
	for (int baseIndex = start, tempIndex = 0; tempIndex < length;
		baseIndex++, tempIndex++)
	{
		arr[baseIndex] = tempArr[tempIndex];
	}
	delete[] tempArr;
}

// заполняем временный масив если один из индексов достиг конца.
void FillTempArr(const int baseArr[], int tempArr[], int baseIndex, int tempIndex, int length)
{
	for (; tempIndex < length; tempIndex++)
	{
		tempArr[tempIndex] = baseArr[baseIndex];
		baseIndex++;
	}
}
#pragma endregion

#pragma region BubleSort

//вызов сортировки пузырьком
void StartBuble(int*& arr, const int& SIZE, const int& RANGE)
{
	cout << "Сортировка массива, алгоритмом - сортировка пузырьком" << endl;
	arr = CreateArray(SIZE, RANGE);
	//выводим числа до сортировки
	//PrintArr(arr, SIZE);
	clock_t timer = clock();
	cout << endl << setfill('-') << setw(80) << '-' << setfill(' ') << endl << endl;
	SortByBuble(arr, SIZE);
	clock_t curent = clock();
	//выводим числа после сортировки
	//PrintArr(arr, SIZE);
	delete[] arr;
	cout << static_cast<double>(curent - timer) / CLOCKS_PER_SEC << endl << endl;
	cout << endl << setfill('=') << setw(80) << '=' << setfill(' ') << endl << endl;
}
//сортировка пузырьком
void SortByBuble(int arr[], int size)
{
	int temp = 0;
	bool isSorted = true;
	for (int i = 0; i < size; i++)
	{
		isSorted = true;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				isSorted = false;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (isSorted)
		{
			break;
		}
	}
}
#pragma endregion

#pragma region AlternativeMergeSort
// вызов альтернативной версии сортировки слиянием
void StartAlternativeMergeSort(int* arr, const int& START, const int& SIZE)
{
	cout << "Сортировка массива, алгоритмом - сортировка слиянием, не рекурсивно." << endl;
	//выводим числа до сортировки
	PrintArr(arr, SIZE);
	cout << endl << setfill('-') << setw(80) << '-' << setfill(' ') << endl << endl;
	clock_t timer = clock();
	AlternativeMergeSort(arr, START, SIZE);
	clock_t curent = clock();
	//выводим числа после сортировки
	PrintArr(arr, SIZE);
	delete[] arr;
	cout << static_cast<double>(curent - timer) / CLOCKS_PER_SEC << endl << endl;
	cout << endl << setfill('=') << setw(80) << '=' << setfill(' ') << endl << endl;
}

// сортировка слиянием через вложенный цикл
void AlternativeMergeSort(int arr[], int start, int length)
{
	for (int curentLength = 2; curentLength < length; curentLength *= 2)
	{
		for (int i = 0; (i + 1) * curentLength - 1 < length; i++)
		{
			AlternativeSortPath(arr, i * curentLength, i * curentLength + curentLength / 2, curentLength);
		}
		//сортируем хвост
		AlternativeSortPath(arr, length - length % curentLength, length - length % curentLength / 2, length % curentLength);
		// финальная сортировка
		if (curentLength * 2 >= length)
		{
			AlternativeSortPath(arr, start, curentLength, length);
		}
	}
}
// сортировка слиянием по индексам
void AlternativeSortPath(int arr[], int leftIndex, int rightIndex, int length)
{
	if (length == 1)
		return;
	const int start = leftIndex, leftStop = rightIndex;
	int* tempArr = new int[length];
	for (int tempIndex = 0;
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
		if (leftIndex >= leftStop)
		{
			tempIndex++;
			FillTempArr(arr, tempArr, rightIndex, tempIndex, length);
			break;
		}
		if (rightIndex >= start + length && tempIndex < length)
		{
			tempIndex++;
			FillTempArr(arr, tempArr, leftIndex, tempIndex, length);
			break;
		}
	}
	for (int baseIndex = start, tempIndex = 0; tempIndex < length;
		baseIndex++, tempIndex++)
	{
		arr[baseIndex] = tempArr[tempIndex];
	}
	delete[] tempArr;
}
#pragma endregion

#pragma region AdditionalFunctions
//заполняет масив случайными числами.
int* CreateArray(const int SIZE, const int RANGE)
{
	std::mt19937 engine;
	engine.seed(time(nullptr));
	//srand(static_cast<int>(time(0)));
	int* arr = new int[SIZE]();
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = engine() % RANGE;
	}
	return arr;
}

// выводим массив на экран
void PrintArr(const int arr[], int size)
{
	int count = 1;
	int const NUMBERS_IN_STRING = 10;
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << arr[i] << "| ";
		if (count % NUMBERS_IN_STRING == 0)
			cout << endl;
		count++;
	}
	cout << endl;
}
#pragma endregion
