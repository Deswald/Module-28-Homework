#include "mergeSort.h"

void merge(int* arr, const int l, const int m, const int r) {
    const int nl = m - l + 1;
    const int nr = r - m;

    auto* left = new int[nl],
        * right = new int[nr];

    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l;

    while (i < nl && j < nr) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, const int l, const int r, const bool &make_thread) {
    if (l >= r)
        return;

    int m = (l + r - 1) / 2;

    if (make_thread && (r - l > 1250000))
    {
        std::future<void> f = std::async(std::launch::async, [&]() {
            mergeSort(arr, l, m, make_thread);
            });
        f.wait();
        mergeSort(arr, m + 1, r, make_thread);
        merge(arr, l, m, r);
    }
    else
    {
        mergeSort(arr, l, m, make_thread);
        mergeSort(arr, m + 1, r, make_thread);
        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}