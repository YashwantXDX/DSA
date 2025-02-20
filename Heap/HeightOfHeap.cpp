#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/height-of-heap5025/1

    Refer Video :- https://www.youtube.com/watch?v=pCsWDX2K06o

    Basic maths , just divide the size (N) by 2 till N becomes 1, and increment the height meanwhile.

*/

class MinHeap{

 public:
    int *arr;
    int size; // total elements in heap 
    int total_size; // total size of array

    MinHeap(int n){
        arr = new int[n];
        total_size = n;
        size = 0;
    }

    // Insert in the heap
    void insert(int val){

        // Heap Overflow
        if(size == total_size){
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        // Comparing it with parent
        while(index > 0 && arr[(index - 1) / 2] > arr[index]){
            swap(arr[(index - 1) / 2], arr[index]);
            
            // Update The Index
            index = (index - 1) / 2;
        }

        cout << arr[index] << " inserted into the Heap\n";

    }

    int heapHeight(int N, int arr[]){
        
        if(N == 1) return 1;

        int height = 0;

        while(N != 1){
            height++;
            N /= 2;

        }

        return height;

    }

    void print(){
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }

};

int main(){

    MinHeap h1(10);

    h1.insert(1);
    h1.insert(3);
    h1.insert(6);
    h1.insert(5);
    h1.insert(9);
    h1.insert(8);

    cout << "Printing Elements in Max Heap : ";
    h1.print();

    //cout << "Height : " << h1.heapHeight(N, arr);

}