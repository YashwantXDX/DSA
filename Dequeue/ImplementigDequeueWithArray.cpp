#include<bits/stdc++.h>
using namespace std;

class Dequeue{

    int *arr;
    int size;
    int front, rear;

 public:
    Dequeue(int s){
        size = s;
        arr = new int[s];
        front = rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){

         return (front == 0 && rear == size - 1) || (rear + 1) % size == front;
         
    }

    void push_front(int x){

        if(isFull())
            cout << "Dequeue is Full\n";
        
        else if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
        }
        
        else{

            front = (front - 1 + size) % size;
            arr[front] = x;

        }

    }

    void push_back(int x){

        if(isFull())
            cout << "Dequeue is Full\n";

        else if(isEmpty()){
            front = rear = 0;
            arr[0] = x;
        }
        
        else{

            rear = (rear + 1) % size;
            arr[rear] = x;

        }

    }

    void pop_front(){

        if(isEmpty())
            cout << "Dequeue is Empty\n";

        else{

            cout << "Element Popped : " << arr[front] << endl;

            if(front == rear)
                front = rear = -1;
            
            else
                front = (front + 1) % size;

        }

    }

    void pop_back(){

        if(isEmpty())
            cout << "Dequeue is Empty\n";

        else{

            cout << "Element Popped : " << arr[rear] << endl;

            if(front == rear)
                front = rear = -1;
            
            else
                rear = (rear - 1 + size) % size;

        }

    }

    int top(){

        if(isEmpty()){
            cout << "Dequeue is Empty\n";
            return -1;
        }
        
        else
            return arr[front];
    }

    int back(){

        if(isEmpty()){
            cout << "Dequeue is Empty\n";
            return -1;
        }
        
        else
            return arr[rear];
    }

};

int main(){
    
    Dequeue dq(5);

    dq.pop_back();
    dq.pop_front();

    dq.push_front(10);
    dq.push_back(30);
    dq.push_front(20);
    dq.push_back(40);
    dq.push_front(50);
    dq.pop_back();
    dq.push_back(60);
    dq.push_front(70);

    cout << dq.top() << endl;
    cout << dq.back() << endl;

}