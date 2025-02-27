#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

    Refer Video :- https://www.youtube.com/watch?v=J-Yrx8d8c70

*/

int maxSubarrayLength(vector<int>& nums, int k) {
    
    // Variable for use
    // start , end, and length
    int start = 0, end = 0, length = 0;

    // Use map to store element and its count
    unordered_map<int, int> map;
    
    // Go to end less than size
    while(end < nums.size()){

        // As we go through the elements, increase their count in the map
        map[nums[end]]++;

        // If we got any element count greater than k
        // Then we have to reduce the window size to get that count in the range
        while(map[nums[end]] > k){

            // Decrease the element ka count from start
            map[nums[start]]--;

            // Decrease the window size
            start++;

        }

        // store the max length of the window which fulfills the requirement i.e. <= k
        length = max(length, end - start + 1);

        // Increase the window size
        end++;

    }

    return length;
    
}

int main(){

    vector<int> arr = {1,2,3,1,2,3,1,2};
    int k = 2;

    cout << maxSubarrayLength(arr, k);

}