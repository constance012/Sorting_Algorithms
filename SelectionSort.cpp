#include <iostream.h>
#include <time.h>
#define maxn 1000

void docfile(int array[], int &n){
	FILE* f = fopen("input.txt", "rt");
	fscanf(f, "%d", &n);
	
	for (int i = 0; i < n; i++)
		fscanf(f, "%d eee eee\n", &array[i]);
	
	fclose(f);
}

void ghifile(int array[], int n){
	FILE* f = fopen("output.txt", "wt");
	fprintf(f, "Number of elements: %d\n\n", n);
	fprintf(f, "Selection Sort: \n");
	
	for (int i = 0; i < n; i++)
		fprintf(f, "%d ", array[i]);
		
	fclose(f);
}

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
    int data[maxn], n;
    
    docfile(data, n);
    
    /*srand((unsigned)time(0));  // Initialize random seed based on system time/
    for (int i=0; i<n; i++){
        data[i] = (rand()%100)+1;
    }*/

	start = clock();
    SelectionSort(data, n);
	end = clock();
	duration = (double)(end - start);
	
	ghifile(data, n);

	printf("Time taken: %f miliseconds\n", duration);
    printf("Sorted Array Using Selection Sort: \n");
    printArray(data, n);
}