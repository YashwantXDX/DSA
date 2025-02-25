#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

    Refer Video :- https://www.youtube.com/watch?v=XePjO6Q8FDE&t=2691s

    Problem Logic :- Similar to Kth Largest Element in a Matrix

*/

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{

    // temp array
    vector<pair<int, pair<int, int>>> temp;

    // Push Values of Column in temp array
    for(int i = 0; i < K; i++)
        temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));

    // Min Heap with pair of data, row, col
    priority_queue<pair<int, pair<int, int>>,
     vector<pair<int, pair<int, int>>>,
      greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());

    // Answer Array
    vector<int> ans;

    pair<int, pair<int, int>> element;
    int i, j;

    while(!p.empty()){

        // Fetch the top pair from min heap
        element = p.top(); p.pop();

        // Push the data 
        ans.push_back(element.first);

        // Get row and col
        i = element.second.first;
        j = element.second.second;

        // Check if the row is present
        if(j + 1 < K)
            p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));

    }

    return ans;

}

int main(){

    vector<vector<int>> arr = {
        {1,2,3,4},
        {2,2,3,4},
        {5,5,6,6},
        {7,8,9,9}
    };

    int k = 4;

    vector<int> ans = mergeKArrays(arr, k);

    for(int i : ans) cout << i << " ";

}