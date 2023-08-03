#include "mergeSort.h"

int main() {
	srand(0);
	long arr_size = 5000000;
	int* array = new int[arr_size];
	for (long i = 0; i < arr_size; i++) {
		array[i] = rand() % 500000;
	}

    time_t start, end;

    // MULTIPLE THREADS
    bool make_thread = true;
    std::cout << "MULTIPLE THREADS" << std::endl;

    time(&start);
    mergeSort(array, 0, arr_size - 1, make_thread);
    time(&end);

    double seconds = difftime(end, start);
    printf("The time: %f seconds\n", seconds);

    for (long i = 0; i < arr_size - 1; i++) {
        if (array[i] > array[i + 1]) {
            std::cout << "Unsorted" << std::endl;
            break;
        }
    }

    for (long i = 0; i < arr_size; i++) {
        array[i] = rand() % 500000;
    }

    // ONE THREAD
    make_thread = false;
    std::cout << std::endl;
    std::cout << "ONE THREAD" << std::endl;

    time(&start);
    mergeSort(array, 0, arr_size - 1, make_thread);
    time(&end);

    seconds = difftime(end, start);
    printf("The time: %f seconds\n", seconds);

    for (long i = 0; i < arr_size - 1; i++) {
        if (array[i] > array[i + 1]) {
            std::cout << "Unsorted" << std::endl;
            break;
        }
    }

	delete[] array;
	return 0;
}