#include<iostream>
using namespace std;

class Queue{

    public:
        int *arr;
        int front, rear, size;
    
    Queue(int n){
        arr = new int [n];
        front = rear = -1;
        size = n;
    }

    bool isEmpty(){

        return front == -1;

    }

    bool isFull(){
        return rear == size - 1;
    }

    void push(int val){

        if(isFull()){
            cout << "Queue Overflow\n";
            return;
        }

        else if(isEmpty()){
            front = rear = 0;
            arr[0] = val;
        }

        else{
            rear++;
            arr[rear] = val;
        }
        

    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Element Popped : " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int start(){

        if(isEmpty()){
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[front];

    }

};

int main(){

    Queue q(5);

    q.pop();
    q.push(69);
    q.pop();
    q.pop();
    

}