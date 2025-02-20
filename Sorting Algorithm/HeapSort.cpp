#include<bits/stdc++.h>
using namespace std;

/*
    1. Convert the array into MaxHeap
    2. Convert MaxHeap into Sorted Array
        Take the top of the MaxHeap and swap it with the end of the array.
        and continue till size go to 0.
*/

// Function to maintain the heap property (Heapify operation)
void Heapify(vector<int> &arr, int index, int size){

    int largest = index; // Assume the current index is the largest
    int left = 2 * index + 1; // Left child index
    int right = 2 * index + 2; // Right child index

    // Compare left child with the largest element
    if(left < size && arr[left] > arr[largest])
        largest = left;
    
    // Compare right child with the largest element
    if(right < size && arr[right] > arr[largest])
        largest = right;
    
    // If largest is not the root, swap and continue heapifying
    if(largest != index){
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, size);
    }
}

// Function to build a MaxHeap from an unsorted array
void BuildMaxHeap(vector<int> &arr, int size){
    // Start from the last non-leaf node and apply heapify
    for(int i = (size / 2) - 1; i >= 0; i--)
        Heapify(arr, i, size);
}

// Function to perform Heap Sort
void SortByHeap(vector<int> &arr, int size){
    
    for(int i = size - 1; i > 0; i--){
        // Swap the root (largest element) with the last element
        swap(arr[i], arr[0]);

        // Heapify the reduced heap
        Heapify(arr, 0, i);
    }
}

int main(){

    vector<int> arr = {10, 11, 14, 8, 3 ,19, 12}; // Input array
    BuildMaxHeap(arr, arr.size()); // Convert array into MaxHeap
    SortByHeap(arr, arr.size()); // Sort the array using Heap Sort

    // Print the sorted array
    for(int i : arr)
        cout << i << " ";
}
