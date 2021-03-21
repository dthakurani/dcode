#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}



void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) 
		cout<<arr[i]<<"  ";
	cout<<"\n";
}


int partition(int arr[], int low, int high) {

	int pivot = arr[low]; 
	int i = low, j = high+1; 

	while(i < j) {
		do {
			++i;
		}while(arr[i] <= pivot);

		do {
			--j;
		}while(arr[j] > pivot);

		if(i < j) {
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[j], &arr[low]);
	return j;
}

void quickSort(int arr[], int low, int high) {
	
	if(low >= high) return;
	
	int j = partition(arr, low, high);
	quickSort(arr, low, j-1);
	quickSort(arr, j+1, high);
}

int main() {
	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	int size = sizeof(arr) / sizeof(int);

	cout<<"\nArray before sort\n";
	printArray(arr, size);


	//First element as Pivot
	quickSort(arr, 0, size-1);

	cout<<"\nArray after sort\n";
	printArray(arr, size);

	return 0;
}