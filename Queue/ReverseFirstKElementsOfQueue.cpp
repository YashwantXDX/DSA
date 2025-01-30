#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1?page=1&difficulty%5B%5D=0&category%5B%5D=Queue&sortBy=submissions

*/

queue<int> modifiedQueue(queue<int> &q, int k){

    int sizeToReverse = q.size() - k;
    stack<int> st;

    while(k){
        st.push(q.front());
        q.pop();
        k--;
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    while(sizeToReverse){

        q.push(q.front());
        q.pop();
        sizeToReverse--;

    }

    return q;
    

}

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> modified = modifiedQueue(q, 3);

    while(!modified.empty()){
        cout << modified.front() << " ";
        modified.pop();
    }

}