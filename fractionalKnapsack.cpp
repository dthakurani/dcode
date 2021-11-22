#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item {
    int value, weight;
    Item(int value, int weight) {
       this->value=value;
       this->weight=weight;
    }
};

bool compare(struct Item x, struct Item y) {
	double a = (double)x.value/(double)x.weight;
	double b = (double)y.value/(double)y.weight;
	return b < a;
}

double fractionalKnapsack(struct Item arr[], int n, int W) {
	int currentWeight = 0;
	double finalValue = 0;
	sort(arr, arr+n, compare);

	for(int i = 0; i < n; i++) {
		if(currentWeight + arr[i].weight <= W) {
			currentWeight += arr[i].weight;
			finalValue += arr[i].value;
		}else {
			int remainingWeight = W - currentWeight;
			finalValue += ((double)remainingWeight/(double)arr[i].weight)*arr[i].value;
			break;
		}
	}
	return finalValue;
}

int main() {
	int W = 16;
	Item arr[] = {{6, 6}, {2, 10}, {1, 3}, {8, 5}, {3, 1}, {5, 3}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<fractionalKnapsack(arr, n, W);
	return 0;
}