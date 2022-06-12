#include <iostream.h>
#include <time.h>

void docfile(int array[], int &n){
	FILE* f = fopen("input.txt", "r");
	
	fscanf(f, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(f, "%d", &array[i]);
	
	fclose(f);
}

void ghifile(int array[], int n){
	FILE* f = fopen("output.txt", "w+");
	
	fprintf(f, "Number of elements: %d\n\n", n);
	fprintf(f, "Sorted array using Insertion Sort: \n");
	for (int i = 0; i < n; i++)
		fprintf(f, "%d ", array[i]);
		
	fclose(f);
}

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
    int n = 5;
    clock_t start, end;
    double duration;
    int data[n];
    
    /*srand((unsigned)time(0));
    for(int i=0; i<n; i++){
        data[i] = (rand()%100)+1;
    }*/
	
	docfile(data, n);
	
	start = clock();
    InsertionSort(data, n);
	end = clock();
	duration = (double)(end - start);
	
	ghifile(data, n);
	
	printf("Time taken: %f miliseconds\n", duration);
    cout << "Sorted Array Using Insertion Sort: \n";
    printArray(data, n);
}