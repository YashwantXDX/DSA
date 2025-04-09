#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/task-scheduler/

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=10755s

    NOTE :- IMPORTANT PROBLEM

*/

int leastInterval(vector<char>& tasks, int n) {
    
    vector<int> freq(26, 0); // To store frequency of each task (A to Z)
    int count = 0;           // To store the max frequency of any task

    // Step 1: Count the frequency of each task
    for(int i = 0; i < tasks.size(); i++) {
        freq[tasks[i] - 'A']++;
        count = max(count, freq[tasks[i] - 'A']); // Track highest frequency
    }

    // Step 2: Calculate base idle slots
    // If one task appears `count` times, then:
    // It creates (count - 1) full cycles, each of length (n + 1)
    // Why (n + 1)? Because a cycle has `n` cooling gaps + 1 slot for the task itself
    int ans = (count - 1) * (n + 1);

    // Step 3: Add tasks that appear `count` times
    // Multiple tasks may have the same highest frequency
    for(int i = 0; i < 26; i++)
        if(freq[i] == count)
            ans++; // One extra slot for each most frequent task

    // Step 4: Return the maximum of the calculated time or total number of tasks
    // This handles the case where there’s no idle time needed
    return max(ans, (int)tasks.size());
}


int main(){
    
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    
    int ans = leastInterval(tasks, n);

    cout << ans;

}