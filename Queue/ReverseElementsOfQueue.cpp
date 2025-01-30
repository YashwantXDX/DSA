#include<bits/stdc++.h>
using namespace std;

queue<int> reverseQueue(queue<int> &q){
    stack<int> st;
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        return q;
}

int main(){

    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    queue<int> rev = reverseQueue(q);

    while(!rev.empty()){
        cout << rev.front() << " ";
        rev.pop();
    }
}