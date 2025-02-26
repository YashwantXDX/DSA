#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/

    Problem Logic :- Similar to Subarray Product Less than K

    Will be found in my github. Just a little bit of change

*/

long long countSubarrays(vector<int>& nums, long long k) {
    
    // Variables start, end, sum, count, productSum and size
    long long start = 0, end = 0, sum = 0, count = 0, prodSum = 0, size = 0;

    // Go till end less than array ka size
    while(end < nums.size()){

        // Subarray Sum
        sum += nums[end];

        // Get the size of the subarray window
        size++;

        // prodSum means the sum of window * window size
        // Question based
        prodSum = sum * size;

        // Check if the prodSum greater or equal to the K
        // Also start is less than end
        while(prodSum >= k && start <= end){

            // Decrease the window size from start
            sum -= nums[start];

            // Decrease the size of the window
            size--;

            // Increase the start
            start++;

            // Get the decreased window prodSum
            prodSum = sum * size;

        }

        // If everything is okay, than just increase the count 
        // with the window size, as the elemnts are also counted
        count += size;

        // Increase the window size
        end++;

    }

    return count;

}

int main(){

    vector<int> arr = {2,1,4,3,5};
    int k = 10;

    cout << countSubarrays(arr, k);
}