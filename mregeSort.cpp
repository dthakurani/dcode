#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
	int size1 = mid - low +1;
	int size2 = high - mid;

	int arr1[size1], arr2[size2];

	for(int i = 0; i < size1; i++) 
		arr1[i] = arr[low+i];
	for(int i = 0; i < size2; i++) 
		arr2[i] = arr[mid+1+i];

	int i = 0, j = 0;
	int k = low;

	while(i < size1 && j < size2) {
		if(arr1[i] <= arr2[j]) {
			arr[k] = arr1[i];
			i++;
		}else {
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while(i < size1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while(j < size2) {
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int low, int high) {
	if(low >= high) return;

	int mid = low + (high-low)/2;	
	mergeSort(arr, low, mid);
	mergeSort(arr, mid+1, high);
	merge(arr, low, mid, high);
}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) 
		cout<<arr[i]<<"  ";
	cout<<"\n";
}

int main() {
	int arr[] = {38, 27, 43, 3, 9, 82, 10};
	int size = sizeof(arr) / sizeof(int);

	cout<<"\nArray before sort\n";
	printArray(arr, size);

	mergeSort(arr, 0, size-1);

	cout<<"\nArray after sort\n";
	printArray(arr, size);

	return 0;
}