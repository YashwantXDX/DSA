#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/subarray-sum-equals-k/description/

    Refer Video :- https://www.youtube.com/watch?v=HZWTEeOqF4c&list=PLQEaRBV9gAFu4ovJ41PywklqI7IyXwr01&index=129


*/

int subarraySum(vector<int>& nums, int k) {
        
    int totalCount = 0, prefixSum = 0;

    // Make a unorderd map for O(1) T.C. Insertion and Searching
    unordered_map<int, int> m;

    // Mark 0 element as counted
    m[0] = 1;

    for(int i = 0; i < nums.size(); i++){

        // get the prefix sum
        prefixSum += nums[i];

        // Agar prefix sum - k ka count hai, means vo exist kr rha hai orr mil jata hai us case me andar jao
        if(m.count(prefixSum - k)){
            
            // total count ko prefixsum - k ke andar ke count se add kro
            totalCount += m[prefixSum - k];

            // jo prefix sum aya hai uska count bdha do
            m[prefixSum]++;

        }

        // Agar count nhi hai, iska mtlb ye nhi ki element bhi nhi hoga
        // is case me hum sirf increment krna ha naa ki m[prefixSm] = 1, iss se answer galat aayega
        // aaisa isliye because agar count nhi bhi hai tb bhi vo element present ho skta hai
        else
            m[prefixSum]++;
    }

    return totalCount;

}

int main(){

    vector<int> nums = {1,2,3};
    int k = 3;

    cout << subarraySum(nums, k);

}