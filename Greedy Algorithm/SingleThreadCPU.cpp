#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/single-threaded-cpu/description/

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=6194s

    NOTE :- IMPORTANT PROBLEM

    Logic :-

    i. Sort the array on the basis of enqueue time
    ii. timer = first task enqueue time
    iii. push all the tasks in min heap enqueue time <= timer
    iv. if min heap empty then initialize timer with next task enqueue time
    v. vrna pop the element, print the orrder and increase the timer by timer += processing time
    vi repeat iii. to v. till all tasks are processed

*/

vector<int> getOrder(vector<vector<int>>& tasks) {
    
    vector<int> ans; // This will store the final order of task execution
    int n = tasks.size();

    // Append the original index to each task
    // Now each task = {enqueueTime, processingTime, index}
    for(int i = 0; i < n; i++)
        tasks[i].push_back(i);
    
    // Sort tasks by their enqueue time
    sort(tasks.begin(), tasks.end());

    long long timer = tasks[0][0]; // Start timer at the first task’s enqueue time
    int i = 0; // Pointer to iterate over tasks

    // Min-heap to choose task with smallest processing time (tie-breaker: smallest index)
    // Heap stores {processingTime, index}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    // Continue until all tasks are processed
    while(!p.empty() || i < n) {

        // Push all tasks that have arrived by current time into the priority queue
        while(i < n && timer >= tasks[i][0]) {
            p.push({tasks[i][1], tasks[i][2]}); // {processingTime, index}
            i++;
        }

        // If no tasks are available yet, move the timer to the next task’s enqueue time
        if(p.empty())
            timer = tasks[i][0];

        else {
            // Pick the task with smallest processing time (or smallest index if tie)
            ans.push_back(p.top().second); // Save the index of the task

            timer += p.top().first; // Advance the time by processing time

            p.pop(); // Remove the task from the queue
        }
    }

    // Return the order of task execution
    return ans;
}


int main(){
    
    vector<vector<int>> tasks = {
        {1,2},
        {2,4},
        {3,2},
        {4,1}
    };


    vector<int> ans = getOrder(tasks);

    for(int i : ans)
        cout << i << " ";

}