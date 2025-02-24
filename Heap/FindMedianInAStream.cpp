#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

    Refer Video :- https://www.youtube.com/watch?v=WfTCdP8kBWQ&t=3439s

    Problem Logic :-

    Create MinHeap and MaxHeap in way that fulfil this logic:

    1. LeftSide(min heap) == RightSide(max heap)
        (top + top) / 2  -> median

    2. LeftSide - 1 == RightSide
        LeftSide ka Top -> median
    
    3. RightSide > LeftSide , to right ka top pop kar ke left me daal do

    4. LeftSide - 1 > RightSide, to left ka top pop kar ke right me daal do

*/

// Make Min Heap and Max Heap
priority_queue<int> LeftMaxHeap;
priority_queue<int, vector<int>, greater<int>> RightMinHeap;

void balanceHeaps(){

    // Min heap size not be greater than Max Heap
    if(RightMinHeap.size() > LeftMaxHeap.size()){
        LeftMaxHeap.push(RightMinHeap.top());
        RightMinHeap.pop();
    }

    else{

        // Different Between Left - Right should not be greater than 1
        if(RightMinHeap.size() < LeftMaxHeap.size() - 1){
            RightMinHeap.push(LeftMaxHeap.top());
            LeftMaxHeap.pop();
        }

    }

}

void insertHeap(int &x){

    // Left heap me phle element daalo
    if(LeftMaxHeap.empty()){
        LeftMaxHeap.push(x); return;
    }

    // Agar x bda hai max heap ke to min heap me daalo
    if(x > LeftMaxHeap.top())
        RightMinHeap.push(x);
    
    else
        LeftMaxHeap.push(x);
    
    // Dono heap ko balance kro as said
    balanceHeaps();

}

double Median(){

    // Left > Right
    if(LeftMaxHeap.size() > RightMinHeap.size())
        return LeftMaxHeap.top();
    
    else{
        // Ye logic median nikaalne ke liye hai agar even size hua to
        double ans = LeftMaxHeap.top() + RightMinHeap.top();
        return ans / 2;
    }

}

vector<double> getMedian(vector<int> &arr) {
    
    vector<double> ans;

    for(int i = 0; i < arr.size(); i++){
        insertHeap(arr[i]);
        ans.push_back(Median());
    }

    return ans;

}

int main(){

    vector<int> arr = {4, 3, 1, 29, 24, 22, 22, 6, 15, 2, 1};
    vector<double> ans = getMedian(arr);

    for(auto &i : ans)
        cout << i << " ";

}