#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


    Refer Video - Coder Army - Lecture 98 - 33:44

*/

// T.C. - O(NK)  
// S.C. - O(N)
int findNegetive(queue<int> q){

    while(!q.empty()){

        if(q.front() < 0)
            return q.front();
        
        else
            q.pop();

    }

    return 0;

}

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    
    vector<int> ans;
    queue<int> q;

    for(int i = 0; i < k - 1; i++)
        q.push(arr[i]);
    
    for(int i = k - 1; i < arr.size(); i++){

        q.push(arr[i]);
        ans.push_back(findNegetive(q));
        q.pop();

    }

    return ans;

}

vector<int> FirstNegativeInteger2(vector<int>& arr, int k){

    queue<int> q;
    vector<int> ans;

    // Only Push the index When the number is negetive
    for(int i = 0; i < k - 1; i++)
        if(arr[i] < 0)
            q.push(i);
        
    for(int i = k - 1; i < arr.size(); i++){

        // Push the index when number is negetive
        if(arr[i] < 0)
            q.push(i);
        
        // The queue is empty when the window has all positive elements
        if(q.empty())
            ans.push_back(0);
        
        else{

            // Check is the front element comes in the window
            if(q.front() <= i - k)
                q.pop();
            
            // The queue is empty when the window has all positive elements
            if(q.empty())
                ans.push_back(0);

            else
                ans.push_back(arr[q.front()]);

        }

    }

    return ans;

}

int main(){

    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> ans = FirstNegativeInteger2(arr, k);

    for(int i : ans)
        cout << i << " ";

}