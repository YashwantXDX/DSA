#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1

    Refer Video :- https://www.youtube.com/watch?v=WfTCdP8kBWQ&t=480s

    Problem Logic :-

    1. Priority Queue bnao min heap ka

    2. ek temp vector bnao with pair<int, pair<int, int>> jisme hum value, row and col store krenge

    3. Jb tk K hai, tb tk min value dhundo 

    4. answer milte hai return kar do
    

*/

int kthSmallest(int mat[4][4], int n, int k)
{

    // make a temp array
    vector<pair<int,pair<int,int>>> temp;

    // Store all the 0th row elements
    // Store pair in value , row, col
    for(int i = 0; i < n; i++)
        temp.push_back(make_pair(mat[i][0], make_pair(i, 0)));

    // Min Heap created of pair value, row, col in O(N) Time 
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> p(temp.begin(), temp.end());

    // ans for value, i for row, j for col
    int ans, i, j;
    
    // pair for current element
    pair<int, pair<int,int>> element;

    while(k--){

        // get the top of the priority ququq
        element = p.top(); p.pop();

        // take the answer
        ans = element.first;

        // get the current row
        i = element.second.first;

        // get the current column
        j = element.second.second;

        // Check if the boundaries are crossed or what
        if(j + 1 < n){

            // Push the left side of the current element and update the column
            p.push(make_pair(mat[i][j + 1], make_pair(i, j + 1)));

        }

    }

    return ans;

}


int main(){

    int mat[4][4]= {
        {16,28,60,64},{22,41,63,91},{27,50,87,93},{36,78,87,94}
    };
    int n = 4;
    int k = 3;

    cout << kthSmallest(mat, n, k);

}