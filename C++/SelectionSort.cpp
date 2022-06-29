#include <iostream>
#include <time.h>
#define maxn 1000
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort(int array[], int n) {
    int i, j, min_idx;
	//Main loop
    for (i = 0; i < n - 1; i++) {
        min_idx = i;  // Set the min as the 1st value.
        
        for (j = i + 1; j < n; j++)
        	if (array[j] < array[min_idx])
        		min_idx = j;
        
        // Swap if the min value has been altered.
		if (min_idx != i)		
	  		swap(array[min_idx], array[i]);
    }
}


void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    // Create an array of random integer
    clock_t start, end;
    double duration;
    int data[maxn];
    
    srand((unsigned)time(0));  // Initialize random seed based on system time/
    for (int i=0; i<maxn; i++){
        data[i] = (rand()%1000)+1;
    }

    printf("Input Array:\n");
    printArray(data, maxn);

	start = clock();
    SelectionSort(data, maxn);
	end = clock();
	duration = (double)(end - start);

	printf("Time taken: %f miliseconds\n", duration);
    printf("Sorted Array Using Selection Sort: \n");
    printArray(data, maxn);
}