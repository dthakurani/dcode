#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int val) {
	if(low < high) {
		int mid = (high-low)+low/2;
		if(arr[mid] == val) return mid+1;

		if(arr[mid] < val) return binarySearch(arr, mid+1, high, val);

		if(arr[mid] > val) return binarySearch(arr, low, mid-1, val);
	}
	return -1;
}

int main() {
	int arr[] = {10, 20, 30 ,40, 50, 60, 70, 80 ,90, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	int val;
	cin>>val;

	cout<<binarySearch(arr, 0, n-1, val);
	return 0;
}