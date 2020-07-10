#include <iostream>

using namespace std;

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int temp = r;
	r--;

	while (true)
	{
		// Tìm phần tử lớn hơn hoặc bằng pivot ở bên trái
		while (l <= r && pivot > arr[l]) l++;

		// Tìm phần tử nhỏ hơn hoặc bằng pivot ở bên phải
		while (l <= r && pivot < arr[r]) r--;

		// l >= r thì thoát vòng lặp
		if (l >= r) break;

		// Đổi chỗ arr[l] và arr[r]
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
		// Gọi hàm phân đoạn
		int k = partition(arr, l, r);

		// Gọi hàm Quick Sort mảng trái [l .. k-1]
		quickSort(arr, l, k - 1);

		// Gọi hàm Quick Sort mảng phải [k+1 .. r]
		quickSort(arr, k + 1, r);
	}
}

// Hàm Quick Sort với hai tham số
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