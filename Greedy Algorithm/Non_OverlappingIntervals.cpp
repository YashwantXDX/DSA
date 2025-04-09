#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/non-overlapping-intervals/description/

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=9289s

    This problem is like N Meetings in One Room

*/

// Comparator to sort intervals by their end time in ascending order
bool comp(vector<int> a, vector<int> b) {
    // Interval with smaller end time should come first
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    // Step 1: Sort the intervals based on end time
    sort(intervals.begin(), intervals.end(), comp);

    int end = INT_MIN; // To track the end of the last non-overlapping interval
    int remove = 0;    // Count of intervals to remove

    // Step 2: Traverse through all intervals
    for(int i = 0; i < intervals.size(); i++) {

        // If current interval does NOT overlap with the previous one
        if(end <= intervals[i][0]) {
            end = intervals[i][1]; // Update the end to current interval’s end
        } 
        else {
            // If overlapping, we remove this interval
            remove++;
        }
    }

    // Return the minimum number of intervals to remove
    return remove;
}


int main(){
    
    vector<vector<int>> intervals = {
        {1,2},
        {2,3},
        {3,4},
        {1,3},
    };


    int ans = eraseOverlapIntervals(intervals);

    cout << ans;

}