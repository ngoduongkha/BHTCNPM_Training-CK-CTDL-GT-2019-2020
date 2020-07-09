#include <iostream>

using namespace std;

void selectionSort(int arr[], int size) 
{
	// Tạo ranh giới giữa mảng đã sắp xếp và mảng chưa sắp xếp
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;

		// Tìm min trong khoảng [i+1 .. size-1]
		// Mảng [i+1 .. size-1] là mảng chưa sắp xếp
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		// Hoán vị min và phần tử ranh giới
		swap(arr[min], arr[i]);
	}
}


int main()
{
	int size;
	int* arr;

	cout << "Nhap kich thuoc mang: ";
	cin >> size;

	// Cấp phát bộ nhớ
	arr = new int[size];

	// Khởi tạo mảng random với size phần tử
	for (int i = 0; i < size; i++)
		arr[i] = rand();

	// Gọi hàm Selection Sort
	selectionSort(arr, size);

	// Xuất kết quả
	cout << "Ket qua: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	delete arr;
	return 0;
}