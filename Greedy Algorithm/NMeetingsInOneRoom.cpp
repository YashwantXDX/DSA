#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=2861s

*/

// Custom comparator function to sort meetings based on their ending time (earliest first)
bool comp(pair<int, int> a, pair<int, int> b){
    return b.second > a.second;  // Sort in increasing order of end time
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    
    // This vector will store pairs of (start time, end time) for each meeting
    vector<pair<int, int>> timer;
    
    // Combine start and end times into pairs for easier sorting and processing
    for(int i = 0; i < start.size(); i++)
        timer.push_back({start[i], end[i]});
    
    // Sort meetings using the custom comparator based on end time
    sort(timer.begin(), timer.end(), comp);

    // This variable keeps track of the end time of the last selected meeting
    int ending = -1;

    // This variable counts how many meetings can be attended
    int total = 0;

    // Iterate through the sorted meetings
    for(int i = 0; i < start.size(); i++) {

        // If the start time of the current meeting is after the end of the last one,
        // it can be attended without conflict
        if(timer[i].first > ending) {
            total++;                   // Count this meeting
            ending = timer[i].second; // Update the end time of the last selected meeting
        }
    }

    // Return the total number of non-overlapping meetings that can be attended
    return total;
}

int main(){
    
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};


    int ans = maxMeetings(start, end);

    cout << ans;

}