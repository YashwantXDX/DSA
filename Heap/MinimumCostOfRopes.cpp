#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

*/

int minCost(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> p;

    // Convert the array into min heap
    for(int i = 0; i < arr.size(); i++)
        p.push(arr[i]);
    
    int ans = 0;

    while(!p.empty()){
        int first = p.top();
        p.pop();

        if(p.empty())
            break;

        int second = p.top();
        p.pop();

        ans += first + second;

        p.push(first + second);

    }

    return ans;
}

int main(){

    vector<int> arr = {4,2,7,6,9};
    // BuildMinHeap(arr, 4);

    cout << "Min Cost : " << minCost(arr);
}