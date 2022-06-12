#include <iostream.h>
#include <time.h>

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int array[], int n) {
    int i, j;
	//Main loop
    for (i=0; i < n-1; i++)
        for (j = n-1; j>i; --j)
        	if (array[j] < array[j-1])
  				swap(array[j], array[j-1]);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    // Create an array of random integer
    int n = 10000;
    clock_t start, end;
    double duration;
    int data[n];
    
    srand((unsigned)time(0));
    for (int i=0; i<n; i++){
        data[i] = (rand() % 9999) + 1;
    }

	start = clock();
    BubbleSort(data, n);
	end = clock();
	duration = (double)(end - start);

	printf("Time taken: %f miliseconds\n", duration);
    printf("Sorted Array Using Bubble Sort: \n");
    printArray(data, n);
}