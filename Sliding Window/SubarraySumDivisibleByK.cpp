#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/subarray-sums-divisible-by-k/

    Refer Video :- https://www.youtube.com/watch?v=rLOFyQ3FW20&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=130

*/

int subarraysDivByK(vector<int>& nums, int k) {
    
    // take prefix sum, total count, remainder
    int prefixSum = 0, totalCount = 0, rem;

    // Take unordered map which will store remainder and its count
    unordered_map<int, int> m;

    // Increase the count of remainder 0 as 1 (Edge Case)
    m[0] = 1;

    for(int i = 0; i < nums.size(); i++){

        // Take prefix sum
        prefixSum += nums[i];

        // Get the remainder by modding with k
        rem = prefixSum % k;

        // Check if the remainder is negetive?
        // If negetive, then make it positive by adding k to it
        if(rem < 0)
            rem = k + rem;
        
        // Check if the remainder is present in the map or not
        // If remainder is present then we know that the subarray sum of that part is divisible so,
        // we will increase the total count and increase the count of remainder as we have stumbled upon.
        if(m.count(rem)){
            totalCount += m[rem];
            m[rem]++;
        }

        // If we didn't found, then just add the remainder to the map for future
        else
            m[rem]++;

    }

    return totalCount;

}

int main(){

    vector<int> arr = {2,3,-8,-3,11,4,8,6,9,4};
    int k = 7;

    cout << subarraysDivByK(arr, k);

}