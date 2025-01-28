#include<bits/stdc++.h>
using namespace std;

/*

    Normal Approach 

    Time Complexity - O(n)
    Space Complexity - O(n)

    Normal Coder Approach - 3 Passes Required
    i.e. Array traversed 3 times

    This method is applied when we want largest rectangle
    for all the heights

    We are taking Next Smallest Right and Next Smallest Left and
    then taking out the max

*/


int largestRectangleArea(vector<int>& heights) {
        
    vector<int> nsr(heights.size());
    vector<int> nsl(heights.size());
    stack<int> indexes;

    for(int i = 0; i < heights.size(); i++){
        
        while(!indexes.empty() && heights[indexes.top()] > heights[i]){
            
            nsr[indexes.top()] = i;
            indexes.pop();
        }

        indexes.push(i);

    }

    while(!indexes.empty()){
        nsr[indexes.top()] = heights.size();
        indexes.pop();
    }

    for(int i = heights.size() - 1; i >= 0; i--){
        
        while(!indexes.empty() && heights[indexes.top()] > heights[i]){
            
            nsl[indexes.top()] = i;
            indexes.pop();
        }

        indexes.push(i);

    }

    while(!indexes.empty()){
        nsl[indexes.top()] = -1;
        indexes.pop();
    }

    int i = 0;
    int max = INT16_MIN;
    while(i < heights.size()){

        int ans = (nsr[i] - nsl[i] - 1) * heights[i];
        max = max < ans ? ans : max;
        i++;

    }

    return max;

}

/*

    Baap Coder Approach 

    Time Complexity - O(n)
    Space Complexity - O(n)

    Baap Coder Approach - 1 Pass Required
    i.e. Array traversed 1 times

    This method is applied when we want overall largest rectangle
    in the histogram.

    Here, We know that the stack has the Next Smallest Element to the left is stored just behind that element

    Refer - Coder Army Lecture 92 - 33:19

*/

int largestRectangleArea2(vector<int> &heights){

    stack<int> indexes;
    int n = heights.size();

    int ans = 0;
    int index;

    for(int i = 0; i < n; i++){

        while(!indexes.empty() && heights[indexes.top()] > heights[i]){

            index = indexes.top();
            indexes.pop();

            if(!indexes.empty())
                ans = max(ans, heights[index] * (i - indexes.top() - 1));
            
            else
                ans = max(ans, heights[index] * i);
        }

        indexes.push(i);

    }

    while(!indexes.empty()){

        index = indexes.top();
        indexes.pop();

        if(!indexes.empty())
            ans = max(ans, heights[index] * (n - indexes.top() - 1));
        
        else
            ans = max(ans, heights[index] * n);

    }

    return ans;

}

int main(){

    vector<int> heights = {2,1,5,6,2,3};

    cout << "Largest Rectangle in Histogram : " << largestRectangleArea2(heights);

}