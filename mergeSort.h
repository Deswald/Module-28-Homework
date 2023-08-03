#include <iostream>
#include <future>
#include <random>
#include <chrono>

void merge(int* arr, const int l, const int m, const int r);
void mergeSort(int* arr, const int l, const int r, const bool &make_thread);
void printArray(int A[], int size);