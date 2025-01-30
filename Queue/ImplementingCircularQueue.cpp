#include<iostream>
using namespace std;

class Queue{
    
    int *arr;
    int front, rear;
    int size;

    public:
        Queue(int n){
            arr = new int[n];
            size = n;
            front = rear = -1;
        }

        bool isFull(){
            return (rear + 1) % size == front;
        }

        bool isEmpty(){
            return front == -1;
        }

        void push(int val){

            if(isFull()){
                cout << "Queue Overflow\n";
                return;
            }

            else if(rear == -1){
                front = rear = 0;
                arr[rear] = val;
            }

            else{
                rear = (rear + 1) % size;
                arr[rear] = val;
            }

        }

        void pop(){

            if(isEmpty()){
                cout << "Queue Underflow\n";
                return;
            }

            else{

                cout << "Element Popped : " << arr[front] << endl;

                if(front == rear)
                    front = rear = -1;
                
                else{
                    front = (front + 1) % size;
                }

            }

        }

        int start(){

            if(isEmpty())
                cout << "Queue is Empty\n";
            
            else
                return arr[front];
        }

};

int main(){

    Queue q(5);

    q.pop();
    q.push(69);
    q.pop();
    q.push(79);
    q.pop();
    q.push(89);
    q.push(99);
    q.push(109);
    q.push(119);
    q.push(129);
    cout << q.start() << endl;
    q.pop();
    cout << q.start() << endl;
    q.pop();
    cout << q.start() << endl;

}