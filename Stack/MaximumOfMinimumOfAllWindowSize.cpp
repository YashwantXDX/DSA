#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?page=1&difficulty%5B%5D=2&category%5B%5D=Stack&sortBy=submissions

    Refer Video - Coder Army Lecture 94 - 53:38

*/

vector<int> maxOfMin(vector<int>& arr) {
        
    int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;
    
    // Iterate Through All the elements
    for(int i = 0; i < n; i++){
        
        // This is the same logic for Next Smallest to the Right and to The Left Problem
        while(!st.empty() && arr[st.top()] > arr[i]){
            
            int index = st.top();
            st.pop();
            
            // The main change is that we have to find the range
            // and update it with the maximum of range and index
            if(st.empty()){
                int range = i;
                ans[range - 1] = max(ans[range - 1], arr[index]); 
            }
            
            else{
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]); 
            }
            
        }
        
        st.push(i);
        
    }
    
    // Check form the remaining elements for the stack
    while(!st.empty()){
        
        int index = st.top();
        st.pop();
        
        if(st.empty()){
            int range = n;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        
        else{
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]); 
        }
        
    }
    
    // Finally after getting all the window elements, update all the empty 
    // blocks in array with the maximum with its next element
    for(int i = n - 2; i >= 0; i--){
        
        ans[i] = max(ans[i], ans[i + 1]);
        
    }
    
    return ans;
    
}

int main(){

    vector<int> arr = {10, 20, 30, 50, 10, 70, 30};
    vector<int> ans = maxOfMin(arr);

    for(int i : ans)
        cout << i << " ";

}