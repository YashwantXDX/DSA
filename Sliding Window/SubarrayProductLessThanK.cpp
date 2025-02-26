#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/subarray-product-less-than-k/description/

    Refer Video :- https://www.youtube.com/watch?v=rLOFyQ3FW20&t=2542s

*/

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    
    // initialize product, start, end, count for future use
    int product = 1, start = 0, end = 0;
    int count = 0;

    // Go till end less than size of array
    while(end < nums.size()){

        // Take the product of subarray
        product *= nums[end];

        // If we get product greater than k, then we will just decrease the window from start
        // We will decrease till product gets small than k and start less than end
        while(product >= k && start <= end){

            product /= nums[start];
            start++;

        }

        // Why we did thi?
        // We did this because we want all the window size
        // for eg. count = 6, array could be {1,2,3}
        // so, {1}, {2}, {3}, {1,2}, {2,3}, {1,2,3}
        // these can be the answer, that is why we did this
        // Watch the video for proper understanding
        count += end - start + 1;
        end++;

    }

    return count;

}

int main(){

    vector<int> arr = {2,5,10,8,100,1000,5,15};
    int k = 999;

    cout << numSubarrayProductLessThanK(arr, k);

}