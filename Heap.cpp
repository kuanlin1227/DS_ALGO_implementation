#include <iostream>
#include <limits.h>
#include <array>

using namespace std;

void adjustment(int arr[], int index, int len);
void print_arr(int arr[], int n);
void build_heap(int arr[], int index, int len);
void heapsort(int arr[], int len);

void heapsort(int arr[], int len)
{
    while (len - 1 > 0)
    {
        adjustment(arr, 1, len);
        int tmp = arr[len - 1];
        arr[len - 1] = arr[0];
        arr[0] = tmp;

        len--;
    }

    return;
}

void build_heap(int arr[], int index, int len)
{
    if (index >= len)
        return;

    adjustment(arr, index, len);
    build_heap(arr, index * 2, len);
    build_heap(arr, index * 2 + 1, len);
}

void adjustment(int arr[], int index, int len)
{
    if (index >= len)
    {
        return;
    }

    adjustment(arr, index * 2, len);
    adjustment(arr, index * 2 + 1, len);

    int r = index - 1;
    int r1 = index * 2 - 1;
    int r2 = index * 2;

    if (r1 < len && arr[r1] > arr[r])
    {
        int tmp = arr[r];
        arr[r] = arr[r1];
        arr[r1] = tmp;
    }

    if (r2 < len && arr[r2] > arr[r])
    {
        int tmp = arr[r];
        arr[r] = arr[r2];
        arr[r2] = tmp;
    }
}

void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    build_heap(arr, 1, end(arr) - begin(arr));
    print_arr(arr, end(arr) - begin(arr));

    int arr2[] = {3, 4, 52, 6, 7, 8, 93, 2, 2, 3, 1, 44};
    heapsort(arr2, end(arr2) - begin(arr2));
    print_arr(arr2, end(arr2) - begin(arr2));

    return 0;
}
