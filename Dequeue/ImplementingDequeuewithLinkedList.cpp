#include<bits/stdc++.h>
using namespace std;

class Node{

 public:
    int data;
    Node *next, *prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }   

};

class Dequeue{

    Node *front, *rear;
    
 public:
    Dequeue(){
        front = rear = NULL;
    }

    void push_front(int x){

        if(front == NULL){
            front = new Node(x);
            rear = front;
        }

        else{

            Node *temp = new Node(x);

            temp -> next = front;
            front -> prev = temp;

            front = temp;

        }

    }

    void push_back(int x){

        if(rear == NULL){
            rear = new Node(x);
            front = rear;
        }

        else{

            Node *temp = new Node(x);

            temp -> prev = rear;
            rear -> next = temp;

            rear = temp;

        }

    }

    void pop_front(){

        if(front == NULL){
            cout << "Dequeue is Empty\n";
        }

        else{

            Node *temp = front;
            front = front -> next;
            delete temp;

            if(front)
                front -> prev = NULL;
            
            else
                rear = NULL;

        }
    }

    void pop_back(){

        if(rear == NULL){
            cout << "Dequeue is Empty\n";
        }

        else {

            Node *temp = rear;
            rear -> prev = rear;
            delete temp;

            if(rear)
                rear -> next = NULL;
            
            else
                front = NULL;

        }

    }

    int top(){
        if(front == NULL){
            cout << "Dequeue is Empty\n";
            return -1;
        }
        
        else
            return front -> data;
    }

    int back(){
        if(rear == NULL){
            cout << "Dequeue is Empty\n";
            return -1;
        }
        
        else
            return rear -> data;
    }

};

int main(){

    Dequeue dq;

    dq.pop_back();
    dq.pop_front();

    dq.push_back(20);
    dq.push_front(10);

    cout << dq.top() << endl;
    cout << dq.back();
}