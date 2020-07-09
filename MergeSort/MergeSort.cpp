#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Tạo các mảng tạm
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy dữ liệu sang các mảng tạm
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Gộp hai mảng tạm vừa rồi vào mảng arr
	i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
	j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
	k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy các phần tử còn lại của mảng L vào arr nếu có
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy các phần tử còn lại của mảng R vào arr nếu có
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	delete L;
	delete R;
}

// l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
		int m = l + (r - l) / 2;

		// Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// Hàm Merge Sort với hai tham số
void mergeSort(int arr[], int size)
{
	mergeSort(arr, 0, size - 1);
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

	// Gọi hàm Merge Sort
	mergeSort(arr, size);

	// Xuất kết quả
	cout << "Ket qua: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";

	delete arr;
	return 0;
}