#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/subarrays-with-k-different-integers/

    Refer Video :- https://www.youtube.com/watch?v=J-Yrx8d8c70&t=2805s

*/

int findAtLeast(vector<int> &nums, int k){

    int start = 0, end = 0, count = 0, size = nums.size(), total = 0;

    // Map to get the count of elements
    unordered_map<int, int> frequency;

    // Till end less than size
    while(end < size){

        // Increase the count of current element
        frequency[nums[end]]++;

        // If it is the first time, increase the count
        if(frequency[nums[end]] == 1)
            count++;
        
        // If we get the count eqaul to k, means we can find atleast k elements present in it
        while(count == k){

            // Decrease the count of the element
            frequency[nums[start]]--;

            // store the total subarray count
            total += size - end;

            // Check if any element got its count to 0,
            // If yes, the decrease the count of distinct element present in the subarray
            if(frequency[nums[start]] == 0)
                count--;
            
            // Decrease the window size
            start++;

        }

        // Increase the window size
        end++;
    }

    return total;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    
    // If we have to find the K Distinct elements subarray
    // we have to find AtLeast K and AtLeast K + 1
    // So if we subtract AtLeast K and AtLeast K + 1
    // We will get The equal to K 
    return findAtLeast(nums, k) - findAtLeast(nums, k + 1);

}

int main(){

    vector<int> arr = {1,2,1,2,3};
    int k = 2;

    cout << subarraysWithKDistinct(arr, k);

}