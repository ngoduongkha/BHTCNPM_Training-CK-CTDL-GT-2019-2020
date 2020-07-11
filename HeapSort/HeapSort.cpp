#include <iostream>

using namespace std;

void downHeap(int arr[], int size, int i) 
{
    while (i < size)
    {
        int child = 2 * i + 1;

        if (child >= size)
            break;

        if (child + 1 < size && arr[child] < arr[child + 1])
            child++;

        if (arr[child] > arr[i])
        {
            swap(arr[child], arr[i]);
            i = child;
        }
        else
            break;
    }
}

void createHeap(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        downHeap(arr, size, i);
}

void heapSort(int arr[], int size)
{
    createHeap(arr, size);
    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        downHeap(arr, i, 0);
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

    // Gọi hàm Heap Sort
    heapSort(arr, size);

    // Xuất kết quả
    cout << "Ket qua: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    delete[] arr;
    return 0;
}