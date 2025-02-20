#include<bits/stdc++.h>
using namespace std;

int main(){

    // By Default Max Heap
    priority_queue<int> q;

    q.push(10);
    q.push(20);
    q.push(11);
    q.push(18);
    q.push(15);

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    
    // To get Min heap
    priority_queue<int, vector<int>, greater<int>> p;

    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
}
