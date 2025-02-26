#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/minimum-size-subarray-sum/description/

    Refer Video :- https://www.youtube.com/watch?v=lni2JkC9_1Y

*/

int minSubArrayLen(int target, vector<int>& nums) {
    
    // Variables for future
    int start = 0, end = 0, size = 0, sum = 0;

    // Answer variable declared with Int Max
    int ans = INT_MAX;

    // Go till end less than nums size
    while(end < nums.size()){

        // Get the sum of the subarray window
        sum += nums[end];

        // Increase the size of the window
        size++;

        // If we found the sum greater than or equal to target and start is less than end
        while(sum >= target && start <= end){

            // Store the minimum window in the answer
            ans = min(ans, size);

            // Decrease the sum by decreasing the window size
            sum -= nums[start];

            // Decrease the size
            size--;

            // Increment the start
            start++;

        }

        // Increment the End
        end++;

    }

    // Return if the answer is still int max or not
    // if it is then answer not found so return 0, otherwise return ans
    return (ans == INT_MAX) ? 0 : ans;

}

int main(){

    vector<int> arr = {2,3,1,2,4,3};
    int target = 7;

    cout << minSubArrayLen(target, arr);

}