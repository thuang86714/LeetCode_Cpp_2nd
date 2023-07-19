//TC best O(nlogn), avg (nlogn), worst O(nlogn)
//SC worst O(n)
//this algo is usually done recursively
//divide & conquer
//credit to Michael Sambol https://youtu.be/4VqmGXwpLqc
//and also to GeekforGeek
// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		int const right)
{
	/*
	int const subArrayOne = mid - left + 1;//mid included
	int const subArrayTwo = right - mid;//mid not included

	// Create temp arrays
	auto *leftArray = new int[subArrayOne],//pointer to the first element of this int array
		*rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray]
			= leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray]
			= rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
	*/
	/*
	int const subArrayLeft = mid - left +1;
	int const subArrayRight = right - mid;

	auto *leftArray = new int[subArrayLeft];
	auto *rightArray = new int[subArrayRight];
	*/
	int const subArrayLeft = mid - left +1;
	int const subArrayRight = right - mid;
	vector<int> leftArray(subArrayLeft, 0);
	vector<int> rightArray(subArrayRight, 0);
	for(int i = 0; i < subArrayLeft; i++){
		leftArray[i] = array[left + i];
	}

	for(int j = 0; j < subArrayRight; j++){
		rightArray[j] = array[mid + 1 + j];
	}

	auto idxSubarrayLeft = 0, idxSubarrayRight = 0;
	int idxMergedArray = left;

	while(idxSubarrayLeft < subArrayLeft && idxSubarrayRight < subArrayRight){
		if(leftArray[idxSubarrayLeft] <= rightArray[idxSubarrayRight]){
			array[idxMergedArray] = leftArray[idxSubarrayLeft];
			idxSubarrayLeft++;
		}else{
			array[idxMergedArray] = rightArray[idxSubarrayRight];
			idxSubarrayRight++;
		}
		idxMergedArray++;
	}

	while(idxSubarrayLeft < subArrayLeft){
		array[idxMergedArray] = leftArray[idxSubarrayLeft];
		idxMergedArray++;
		idxSubarrayLeft++;
	}

	while(idxSubarrayRight < subArrayRight){
		array[idxMergedArray] = rightArray[idxSubarrayRight];
		idxMergedArray++;
		idxSubarrayRight++;
	}

	//delete[] leftArray;
	//delete[] rightArray;
	
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	/*
	if (begin >= end)//base case
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);//divide and conquer
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
	*/

	if(begin >= end)return;//base case
	int mid = (begin + end)/2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid+1, end);
	merge(array, begin, mid, end);

}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
