#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/insert-interval/

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=10030s

*/

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    vector<vector<int>> ans;  // Result array to store the final intervals
    int i = 0, n = intervals.size();

    // Step 1: Add all intervals that end before the new interval starts
    while(i < n && newInterval[0] > intervals[i][1]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // If all intervals are added and no merge is needed
    if(i == n) {
        ans.push_back(newInterval);
        return ans;
    }

    // Step 2: Merge all overlapping intervals with the newInterval
    while(i < n && newInterval[1] >= intervals[i][0]) {
        // Update the start to the minimum of both starts
        newInterval[0] = min(newInterval[0], intervals[i][0]);

        // Update the end to the maximum of both ends
        newInterval[1] = max(newInterval[1], intervals[i][1]);

        i++; // Move to the next interval
    }

    // Add the merged interval
    ans.push_back(newInterval);

    // Step 3: Add all remaining intervals after the merged one
    while(i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans; // Return the final set of intervals
}


int main(){
    
    vector<vector<int>> intervals = {
        {1,3},
        {6,9}
    };

    vector<int> newInterval = {2,5};
    
    vector<vector<int>> ans = insert(intervals, newInterval);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}