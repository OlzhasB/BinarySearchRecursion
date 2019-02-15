#include<iostream>
using namespace std;

//1.	Дан одномерный массив целых чисел.Напишите рекурсивную функцию, которая осуществляет 
//нахождения искомого значения с помощью бинарного  поиска.
//Функция возвращает позицию вхождения искомого значения.Проиллюстрируйте работу функции примером.

int binarySearch(int a[], int n, int k, int low)
{
	int middle = (low + n) / 2;
	if (a[middle] == k)
		return middle;

	if (low >= n)
		return -1;
	
	if (k < a[middle])
		binarySearch(a, middle, k, low);

	else
		binarySearch(a, n, k, middle);
	
}

void fillArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = 1 + rand() % 30;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

void sortArray(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 2; j >= i; j--)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}

int main()
{
	const int n = 10;
	int a[n] = { 0 };
	fillArray(a, n);
	cout << "Given array: " << endl;
	printArray(a, n);
	sortArray(a, n);
	cout << "Sorted array: " << endl;
	printArray(a, n);
	int k;
	cout << "Which number you want to find: ";
	cin >> k;
	cout << binarySearch(a, n, k, 0) << endl;
	system("pause");
}
