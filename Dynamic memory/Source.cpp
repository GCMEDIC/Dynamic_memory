#include <iostream>
using namespace std;

void fillrand(int* arr, const int n);
void print(int arr[], const int n);

#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	fillrand(arr, n);
	print(arr, n);

	int brr[5];
	fillrand(brr, 5);
	print(brr, 5);
	
	delete[] arr;
}

void fillrand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		// * - ���������� �������� �� ������
		*(arr + i) = rand() % 100;
	}
}

void print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// [] - �������� �������������� ���������� �������� �� �������
		cout << arr[i] << "\t";
	}
	cout << endl;
}