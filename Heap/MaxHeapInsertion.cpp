#include<bits/stdc++.h>
using namespace std;

class MaxHeap{

 public:
    int *arr;
    int size; // total elements in heap 
    int total_size; // total size of array

    MaxHeap(int n){
        arr = new int[n];
        total_size = n;
        size = 0;
    }

    // Insert in the heap
    void insert(int val){

        // Array overflow?
        if(size == total_size){
            cout<< "Heap Overflow\n";
            return;
        }

        // Insert value
        arr[size] = val;

        // get the index and increase the size
        int index = size;
        size++;

        // Compare it with parent
        while(index > 0 && arr[(index - 1) / 2] < arr[index]){
            
            // If value is bigger than its parent
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;

        }

        cout << arr[index] << " inserted in the Max Heap" << endl;

    }

    void print(){
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }

};

int main(){

    MaxHeap h1(10);

    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.insert(24);
    h1.insert(35);
    h1.insert(17);

    cout << "Printing Elements in Max Heap : ";
    h1.print();

}