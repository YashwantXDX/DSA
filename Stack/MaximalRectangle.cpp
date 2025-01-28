#include<bits/stdc++.h>
using namespace std;

/*

    Same Problem as Largest Rectangle Area But Now we are given a 2-D Matrix
    problem link - https://leetcode.com/problems/maximal-rectangle/description/


*/

int largestRectangleArea(vector<int> &heights){

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

int maximalRectangle(vector<vector<char>>& matrix) {
        
    vector<int> numbers(matrix[0].size(), 0);
    int ans = 0;

    for(int i = 0; i < matrix.size(); i++){

        for(int j = 0; j < matrix[0].size(); j++){

            if(matrix[i][j] == '1')
                numbers[j]++;
            else
                numbers[j] = 0;
        }

        ans = max(ans, largestRectangleArea(numbers));
        
    }

    return ans;

}

int main(){

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "The Maximal Rectangle is : " <<maximalRectangle(matrix) << endl;

}