#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

    Refer Video - Coder Army - https://www.youtube.com/watch?v=loLfzoeeyEQ

    Time Stamp - 1 : 07 : 10

*/

int minKBitFlips(vector<int>& nums, int k) {
    
    queue<int> q;
    int flips = 0;

    for(int i = 0; i < nums.size(); i++){

        if(!q.empty() && q.front() < i)
            q.pop();
        
        if(q.size() % 2 == nums[i]){

            if( i + k - 1 >= nums.size())
                return -1;
            
            else
                q.push(i + k - 1);
                flips++;

        }

    }

    return flips;

}

int main(){

    vector<int> arr = {0,0,1,0,0,1,1,0,1,0};
    int k = 4;

    cout << "Minimum No. of FLips : " << minKBitFlips(arr, k);

}