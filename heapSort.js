function buildMaxHeap(arr, size) {
	for(let i = 1; i < size; i++) {
		if(arr[i] > arr[Math.floor((i-1)/2)]) {
			let j = i;
			while(arr[j] > arr[Math.floor((j-1)/2)] && j > 0) {
				let temp = arr[j]; 
				arr[j] = arr[Math.floor((j-1)/2)];
				arr[Math.floor((j-1)/2)] = temp;
				j = Math.floor((j-1)/2);
			}
		}
	}
}

function heapSort(arr, size) {
	buildMaxHeap(arr, size);

	for(let i = size-1; i >= 0; i--) {
		let temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		buildMaxHeap(arr, i);
	}
}

let arr = [12, 11, 13, 5, 6, 7, 15, 5, 19];
heapSort(arr, arr.length);
console.log(arr);