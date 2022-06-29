#include "iostream"
#include "time.h"
using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void printArray(int array[], int size) {
    for ( int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int partitioningTheArray(int array[], int left, int right) {
	// Choose the last element as the pivot point.
	int pivot = array[right];
	
	// Set a cursor for navigating through the array.
	// The cursor index will always be lesser than half of the current array size.
	int cursor = left - 1;
	
	// If the current value is lesser or equal to the pivot point.
	// Then increment the cursor index by 1 and swap the cursor value with the current value.
	for (int i = left; i < right; i++)
		if (array[i] <= pivot) {
			cursor++;
			swap(array[cursor], array[i]);
		}
	
	// Swap next value after the cursor index with the pivot point.
	swap(array[cursor + 1], array[right]);
	
	// Return the cursor index.
	return cursor;
}

void quickSort(int array[], int left, int right) {
	// If the array has less than 2 elements.
	if (left >= right)
		return;
		
	// Else if it has 2 elements.
	else if (left + 1 == right && array[left] > array[right])
		swap(array[left], array[right]);  // Swap them if the order is incorrect.
	
	// Otherwise, it must has more or equal to 3 elements.
	else {
		int updatedCursor = partitioningTheArray(array, left, right);		
		quickSort(array, left, updatedCursor);  // [left -> pivot]
		quickSort(array, updatedCursor + 2, right);  // + 2 because + 1 is the pivot point [pivot + 1 -> right].
	}
}

int main() {
    // t?o m?ng v?i giá tr? ng?u nhiên
    const int n = 100;
    int data[n];
    clock_t start, end;
    double duration;
    
	// Generate a random array of unsigned integers.
    srand((unsigned)time(0));
    for(int i = 0; i < n; i++){
        data[i] = (rand() % 100) + 1;
    }

	cout << "Input array: \n";
    printArray(data, n);
    
    start = clock();
    quickSort(data, 0, n - 1);
    end = clock();

	// Calculate the duration.
    duration = (double)(end - start);

    printf("Time taken: %f miliseconds\n", duration);
	
    printf("Sorted Array Using Quick Sort: \n");
    printArray(data, n);
}