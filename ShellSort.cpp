#include <iostream.h>
#include <time.h>

void shellSort(int array[], int n) {
    int h = 1, i, j, tmp;
    
	// Find the interval h based on the formula: [current_h = 3 * previous_h + 1].
	// h must be lesser or equal to n/3.
    while (h <= n / 3)
    	h = 3*h + 1;
    	
   	// While the interval is greater than 0
   	while (h > 0) {
		for (i = h; i < n; i++) {
			tmp = array[i];  // Store the current value at index i in the temp variable.
			j = i;  // Set j = i.
			
			// While the value at index (j - interval) is greater than the temp.
			// And j is greater than h - 1.
			while ((array[j - h] > tmp) && (j > h - 1)) {
				array[j] = array[j - h];  // Swap the current value with the previous interval-th value.
				j -= h;  // Decrease j by the interval h.
			}
			
			// When j reach its last position, assign the temp value to this position to complete the swapping process.
			array[j] = tmp;
		}
		
		// Finally, decrease the interval h by inverting the formula: [previous_h = (current_h - 1) / 3].
		h = (h - 1) / 3;
 	}
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    // Create an array of random integer
    int n = 100;
    clock_t start, end;
    double duration;
    int data[n];
    
    // Generate a random array of unsigned integers.
    srand((unsigned)time(0));
    for(int i = 0; i < n; i++){
        data[i] = (rand() % 500) + 1;  // The random range.
    }
	
	printf("Input array:\n");
	printArray(data, n);
	
	start = clock();
    shellSort(data, n);
	end = clock();
	
	// Calculate the duration.
	duration = (double)(end - start);

	printf("\nTime taken: %f miliseconds\n", duration);
	
    printf("\nSorted Array Using Shell Sort: \n");
    printArray(data, n);
}