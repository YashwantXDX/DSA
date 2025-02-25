#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

    Refer Video :- https://www.youtube.com/watch?v=-2_sXN4IkE4

    Problem Logic :-

    1. Get the Column 0th elements and store in the temp vector and update max element

    2. make a min heap and push the elements of temp array to min heap

    3. make answer array of size 2

    4. make a temp pair, row, col

    5. update the minimum

    7. update the ans[0] and ans[1] with minimum and maximum

    8. Loop until both min heap and nums size are equal

    9. fetch the values of the min heap into temp pair, row and col

    10. check if row have elements present

    11. push the next pair into the min heap, and update minimum and maximum

    12. check the range here by (maximum - minimum) < (ans[1] - ans[0]). If this is true, then update the ans[1] and ans[0] with new maximum and minimum element

    13. Finally Return the ans

    

*/

vector<int> smallestRange(vector<vector<int>>& nums) {
        
    // temp array
    vector<pair<int, pair<int, int>>> tempArr;

    // Minimum and Maximum Elements
    int minimum = INT_MAX, maximum = INT_MIN;

    // Push the Column 0th index value in temp 
    for(int i = 0; i < nums.size(); i++){
        tempArr.push_back(make_pair(nums[i][0], make_pair(i, 0)));
        maximum = max(maximum, nums[i][0]);
    }

    // Make min heap and insert temp into the heap
    priority_queue<pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> p(tempArr.begin(), tempArr.end());

    // Make Answer Array
    vector<int> ans(2);
    pair<int, pair<int, int>> temp;
    int i, j;

    // Get minimum
    minimum = p.top().first;

    // Update the minimum and maximum in the answer array
    ans[0] = minimum;
    ans[1] = maximum;

    // Loop until the min heap size is equal to nums array
    while(p.size() == nums.size()){

        // Fetch The pairs
        temp = p.top(); p.pop();

        // Fetch the row and col
        i = temp.second.first;
        j = temp.second.second;

        // agar row ki next value present hai to ye kro
        if(j + 1 < nums[i].size()){

            // Push the new pair in min heap
            p.push(make_pair(nums[i][j + 1], make_pair(i, j + 1)));

            // Get the maximum and minimum
            maximum = max(maximum, nums[i][j + 1]);
            minimum = p.top().first;

            // Check the range, if range is small then update the answer array
            if(maximum - minimum < ans[1] - ans[0]){
                ans[0] = minimum;
                ans[1] = maximum;
            }

        }

    }

    return ans;

}

int main(){

    vector<vector<int>> arr = {
        {3,7,8},
        {1,2,4,6,12},
        {7,8,10,14}
    };

    vector<int> ans = smallestRange(arr);

    for(int i : ans) cout << i << " ";

}