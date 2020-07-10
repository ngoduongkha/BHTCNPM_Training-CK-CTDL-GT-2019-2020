#include <iostream>

using namespace std;

void insertionSort(int arr[], int size)
{
	int i, key, j;

	for (i = 1; i < size; i++)
	{
		// Ghi nhớ giá trị arr[i]
		key = arr[i];
		j = i - 1;

		/* Di chuyển những phần tử lớn hơn key tới
		vị trí liền trước của nó trong mảng [0 .. i-1] */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		// Gán giá trị arr[i] cho arr[j + 1]
		arr[j + 1] = key;
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

	// Gọi hàm Insertion Sort
	insertionSort(arr, size);

	// Xuất kết quả
	cout << "Ket qua: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	delete arr;
	return 0;
}