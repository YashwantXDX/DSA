#include<iostream>
#include<queue>
using namespace std;

void printElements(queue<int> &q){

    int n = q.size(); // 4

    while(n){

        int front = q.front();
        cout << front << " ";
        q.pop();
        q.push(front);
        n--;
        
    }

}

int main(){

    queue<int> q;

    q.push(2);
    q.push(4);
    q.push(6);
    q.push(8);

    printElements(q);

}