#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

    Refer Video :- https://www.youtube.com/watch?v=J-Yrx8d8c70&t=1268s

*/

long long countSubarrays(vector<int>& nums, int k) {

    // take start, end , count, size and largest variable
    int start = 0, end = 0, count = 0, size = nums.size(), large = INT_MIN;

    // take total for the ans
    long long total = 0;

    // Find the max element
    for(int i : nums)
        large = max(large, i);
    
    // Go till end less than size
    while(end < size){

        // Check if the current element is the largest element of not
        // If it is than increase the count
        if(nums[end] == large)
            count++;
        
        // If largest element count is equal to k then find all the subarrays containing that element and decrease the window size
        while(count == k){

            // store the total subarray count
            total += size - end;

            // check is the current element is the largest number or not
            // if it is then decrease the count as we are decreasing the window size
            if(nums[start] == large)
                count--;

            // Decrease the window size
            start++;
        }
        
        // Increase the window size
        end++;

    }

    return total;
       
}

int main(){

    vector<int> arr = {1,3,2,3,3};
    int k = 2;

    cout << countSubarrays(arr, k);

}