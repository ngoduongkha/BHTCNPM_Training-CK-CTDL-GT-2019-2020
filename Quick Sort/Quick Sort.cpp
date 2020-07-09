#include <iostream>

using namespace std;

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int temp = r;
	r--;

	while (true)
	{
		while (l <= r && pivot > arr[l]) l++;
		while (l <= r && pivot < arr[r]) r--;

		if (l >= r) break;

		swap(arr[l], arr[r]);

		l++;
		r--;
	}

	swap(arr[l], arr[temp]);

	return l;
}

void quickSort(int arr[], int l, int r) 
{
	if (l < r) 
	{
		int k = partition(arr, l, r);
		quickSort(arr, l, k - 1);
		quickSort(arr, k + 1, r);
	}
}

void quickSort(int arr[], int size)
{
	quickSort(arr, 0, size - 1);
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
	quickSort(arr, size);

	// Xuất kết quả
	cout << "Ket qua: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	delete arr;
	return 0;
}