#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
};

class Queue{

    int count;
    Node *front, *rear;
    int size;
    public:
    Queue(int n){
        count = 0;
        front = rear = NULL;
        size = n;
    }

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == size;
    }

    void push(int x){

        if(isFull()){
            cout << "Queue Overflow\n";
        }

        else if(isEmpty()){
            rear = new Node(x);
            front = rear;
            count++;
        }

        else{
            rear -> next = new Node(x);
            rear = rear -> next;
            count++;
            cout << "Element Pushed : " << rear -> data << endl;
        }

    }

    void pop(){

        if(isEmpty()){
            cout << "Queue Underflow\n";
        }

        else{
            cout << "Element Popped : " << front -> data << endl;

            Node *temp = front;
            front = front -> next;
            delete temp;
            count--;
        }

    }

    int start(){

        if(isEmpty()){
            cout << "Queue is Empty\n";
            return -1;
        }
        
        else
            return front -> data;

    }

};

int main(){

    Queue q(3);
    q.pop();
    q.push(69);
    q.push(79);
    q.push(89);
    q.push(99);
    cout << q.start() << endl;
    q.pop();
    q.pop();
    cout << q.start() << endl;
    q.pop();
    q.pop();

}