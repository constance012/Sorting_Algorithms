#include "iostream"
#include "time.h"
using namespace std;

// Function 1: Print out all elements from an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Function 2: Generate an array that contains only even elements from the main array.
void generateEvenArray(int mainArr[], int n, int evenArr[], int& m) {
	m = 0;  // The second array size.
	
	for (int i = 0; i < n; i++)
		if (mainArr[i] % 2 == 0)
			// Adding even element and increasing the size at the same time.
			evenArr[m++] = mainArr[i];
}

// Merging two sorted segments into one sorted segment.
void mergingSortedSegments(int leftSeg[], int l, int rightSeg[], int r, int mergedSeg[], int& m) {
	int i = 0, j = 0;  // Navigating cursors.
	m = 0;  // The third segment size.
	
	while (!(i >= l && j >= r)) {
		// Adding element into the merged segment in correct order:
		
		// Adding element from the left segment when it's smaller than the corresponding element from the right segment,
		// Or when all elements from the right segment have been added into the merged segment.
		if ((i < l && j < r && leftSeg[i] < rightSeg[j]) || (j >= r))
			mergedSeg[m++] = leftSeg[i++];
		
		// Otherwise, adding element from the right segment into the merged segment,
		// Or when all elements from the left segment have been added into the merge segment.
		else
			mergedSeg[m++] = rightSeg[j++];
	}
}

// Basic version.
void returnSortedArray(int array[], int left, int mid, int right) {
	// Allocate a memory area with (mid - left + 1) times of the size of integer type.
	int* leftSegment = new int[mid - left + 1];  // The left segment: [left -> mid].
	int l = 0;  // The cursor of the left segment.
	
	// Allocate a memory area with (right - mid) times of the size of integer type.
	int* rightSegment = new int[right - mid];  // The right segment: [mid + 1 -> right].
	int r = 0;  // The cursor of the right segment.
	
	// Allocate a memory area with (right - left + 1) times of the size of integer type.
	int* mergedSegment = new int[right - left + 1];  // The merged segment: [left -> right].
	int m = 0;  // The cursor of the merged segment.
	
	// Adding elements into their corresponding segments.
	for (int i = left; i <= mid; i++)
		leftSegment[l++] = array[i];
		
	for (int i = mid + 1; i <= right; i++)
		rightSegment[r++] = array[i];
		
	// Merging two segments into 1 segment after completed sorting process.
	mergingSortedSegments(leftSegment, l, rightSegment, r, mergedSegment, m);
	
	// Push all elements from the merged segment back to the main array.
	for (int i = 0; i < m; i++)
		array[left + i] = mergedSegment[i];
	
	// Release the allocated memory area of these segments.
	delete []leftSegment;
	delete []rightSegment;
	delete []mergedSegment;
}

// Enhanced version.
void returnSortedArrayEnhanced(int array[], int left, int mid, int right) {
	int* mergedSegment = new int[right - left + 1];
	int m = 0;  // The cursor of the merged segment.
	
	int l = left;  // The cursor of the left segment: [left -> mid].
	int r = mid + 1;  // The cursor of the right segment: [mid + 1 -> right].
	
	while (!(l > mid && r > right)) {
		// Adding element into the merged segment in correct order:
		
		// Adding element from the left segment when it's smaller than the corresponding element from the right segment,
		// Or when all elements from the right segment have been added into the merged segment.
		if ((l <= mid && r <= right && array[l] < array[r]) || (r > right))
			mergedSegment[m++] = array[l++];
		
		// Otherwise, adding element from the right segment into the merged segment,
		// Or when all elements from the left segment have been added into the merge segment.
		else
			mergedSegment[m++] = array[r++];
	}
	
	// Push all elements from the merged segment back to the main array.
	for (int i = 0; i < m; i++)
		array[left + i] = mergedSegment[i];
		
	delete []mergedSegment;
}

void mergeSort(int array[], int left, int right) {
	// If the current segment has more than 1 element.
	if (left < right) {
		int mid = (left + right) / 2;
		
		// Re-call the function recursively.
		mergeSort(array, left, mid);  // Sorting the left segment.
		mergeSort(array, mid + 1, right);  // Sorting the right segment.
		//returnSortedArray(array, left, mid ,right);  // Return the sorted array.
		returnSortedArrayEnhanced(array, left, mid ,right);  // Return the sorted array.
	}
}

int main() {
    // Create an array of random integer
    const int n = 100;
    clock_t start, end;
    double duration;
    int data[n];
    
    // Generate a random array of unsigned integers.
    srand((unsigned)time(0));
    for(int i = 0; i < n; i++){
        data[i] = (rand() % 200) + 1;  // The random range.
    }
	
	printf("Input array:\n");
	printArray(data, n);
	
	start = clock();
    mergeSort(data, 0, n - 1);
	end = clock();
	
	// Calculate the duration.
	duration = (double)(end - start);

	printf("\nTime taken: %f miliseconds\n", duration);
	
    printf("\nSorted Array Using Merge Sort: \n");
    printArray(data, n);
}