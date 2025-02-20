#include<bits/stdc++.h>
using namespace std;

/*
    Step Down Approach to reduce the Time Complexity to O(n)
*/

void Heapify(int *arr, int index, int n){

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < n && arr[left > arr[largest]])
        largest = left;
    
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != index){
        
        // Swap largest and index
        swap(arr[largest], arr[index]);

        // Call the function to check the position
        Heapify(arr, largest, n);
    }

}

void BuildMaxHeap(int *arr, int n){

    // (n / 2) - 1 because we know that above that index all of the elements don't have children
    for(int i = (n / 2) - 1; i >= 0; i--){

        Heapify(arr, i, n);

    }

}

void printHeap(int *arr, int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){

    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr, 10);

    printHeap(arr, 10);
}