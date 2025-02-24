#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

    Refer Video :- https://www.youtube.com/watch?v=ANjoYpXpDaw

    Problem Logic :-

    Just Merge Two array into a single one and call heapify function into it. So it will be converted into max heap.

*/

void heapify(vector<int> &arr, int index, int size){

    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    
    if(right < size && arr[right] > arr[largest])
        largest = right;
    
    if(largest != index){
        swap(arr[largest], arr[index]);
        heapify(arr, largest, size);
    }

}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){

    for(int i : b)
        a.push_back(i);
    
    int newSize = a.size();

    for(int i = (newSize / 2) - 1; i >= 0; i--)
        heapify(a, i, newSize);

    return a;

}

int main(){

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size();
    int m = b.size();

    vector<int> ans = mergeHeaps(a, b, n, m);

    for(int i : ans) cout << i << " ";

}