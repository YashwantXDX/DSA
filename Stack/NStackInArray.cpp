#include<bits/stdc++.h>
using namespace std;

/*

    This is an improtant problem so must remember it how to solve it

    problem link :- https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271?leftPanelTabValue=PROBLEM

    Problem Video - Coder Army - Lecture 95 - 22:32

*/

class Node{

    public:
        int data;
        Node *next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }

};

class NStack
{
public:

    int *arr;
    Node **top;
    stack<int> st;

    NStack(int N, int S)
    {
        arr = new int[S];
        top = new Node *[N];

        // Initialize the tops with NULL for the linkedlist
        for(int i = 0; i < N; i++)
            top[i] = NULL;
        
        // Initiliaze the stack with empty spaces
        for(int i = 0; i < S; i++)
            st.push(i);

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        
        if(st.empty()){
            cout << "Element cannot be pushed\n";
            return false;
        }

        // Pust the value in the array of empty space
        arr[st.top()] = x;
        cout << "Element Pushed in " << m << " " << x << endl;

        // Just like when we push the elements in singly linked list
        Node *temp = new Node(st.top());
        temp -> next = top[m - 1];
        top[m - 1] = temp;

        // Fill out the empty space
        st.pop();
        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        
        if(top[m - 1] == NULL){
            cout << "Element cannot be popped\n";
            return -1;
        }

        // Empty out the data from the array
        int element = arr[top[m - 1] -> data];

        // Push the empty space in the stack
        st.push(top[m - 1] -> data);

        top[m - 1] = top[m - 1] -> next;

        cout << "Element popped from " << m << " i.e. " << element << endl;  

        return element;
    }
};

int main(){

    NStack st(3,6);
    st.push(1,10);
    st.push(1,20);
    st.push(2,30);
    st.pop(1);
    st.pop(2);

}