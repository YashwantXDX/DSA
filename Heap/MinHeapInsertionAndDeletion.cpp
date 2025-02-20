#include<bits/stdc++.h>
using namespace std;

/*

    Heapify means ek element ko uske sahi position me daal to
    compare apne child node se kar ke

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

    // Delete in the Heap
    // Deletion is performed in the root element
    
    void deletion(){

        // Check if the hep is present
        if(size == 0){
            cout << "Heap is Empty\n";
            return;
        }

        cout << arr[0] << " deleted from the Heap\n";

        // Replace the last element with the first element
        // So we can delete the root element and replace it with te updated element

        arr[0] = arr[size - 1];
        size--;

        // Heap gone empty
        if(size == 0)
            return;
        
        Heapify(0);

    }

    void Heapify(int index){

        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Smallest will store jo in teeno me se bda hoga
        if(left < size && arr[left] < arr[smallest])
            smallest = left;
        
        if(right < size && arr[right] < arr[smallest])
            smallest = right;
        
        // Check kro ki Smallest update to nahi hua?
        // Agar hua hai to swap kr do arr[index] and arr[smallest] ko
        // Orr Heapify function ko dobara call kro Smallest ke liye
        if(smallest != index){
            swap(arr[index], arr[smallest]);
            Heapify(smallest);
        }

    }

    void print(){
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }

};

int main(){

    MinHeap h1(10);

    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.deletion();
    h1.insert(24);
    h1.insert(35);
    h1.deletion();
    h1.insert(17);
    h1.deletion();
    h1.deletion();
    h1.insert(12);

    cout << "Printing Elements in Max Heap : ";
    h1.print();

}