#include <iostream>
#include <time.h>
using namespace std;

void InsertionSort(int array[], int n) {
    int i, j, tmp;
	//Main loop
    for (i=1; i < n; i++) {
        tmp = array[i];  // Store the 2nd value (at index 1).
        
        // If current value is smaller than the previous one, then swap them
        for (j = i; j > 0 && tmp < array[j-1]; j--)
        	array[j] = array[j-1];
  		
  		array[j] = tmp;
    }
}

void printArray(int array[], int size) {
    for ( int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    // Create an array of random integer
    const int n = 100;
    clock_t start, end;
    double duration;
    int data[n];
    
    srand((unsigned)time(0));
    for(int i=0; i<n; i++){
        data[i] = (rand()%1000)+1;
    }

    printf("Input Array:\n");
    printArray(data, n);
	
	start = clock();
    InsertionSort(data, n);
	end = clock();
	duration = (double)(end - start);
	
	printf("Time taken: %f miliseconds\n", duration);
    cout << "Sorted Array Using Insertion Sort: \n";
    printArray(data, n);
}