#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=3977s

    NOTE :- IMPORTANT PROBLEM

*/

// Comparator function to sort jobs by descending profit
bool comp(pair<int, int> a, pair<int, int> b) {
    return b.second < a.second;  // Jobs with higher profit come first
}

// Find function for DSU (with path compression)
int find(int num, vector<int> &parent) {
    // Base case: if the current slot is its own parent
    if(num == parent[num])
        return num;

    // Path compression: flatten the tree for faster future access
    parent[num] = find(parent[num], parent);

    return parent[num];
}

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    
    vector<pair<int, int>> jobs;

    // Combine each job's deadline and profit into a pair
    for(int i = 0; i < deadline.size(); i++)
        jobs.push_back({deadline[i], profit[i]});

    // Sort the jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), comp);

    // Find the maximum deadline to determine the time slots needed
    int maxDeadline = 0;
    for(int i = 0; i < deadline.size(); i++)
        maxDeadline = max(deadline[i], maxDeadline);

    // DSU parent array where parent[i] = latest available free slot <= i
    vector<int> parent(maxDeadline + 1);
    for(int i = 0; i <= maxDeadline; i++)
        parent[i] = i;

    // Variables to store results
    int totalProfit = 0, noOfJob = 0;

    // Try to schedule each job
    for(int i = 0; i < jobs.size(); i++) {

        // Find the latest available slot for this job
        int slot = find(jobs[i].first, parent);

        if(slot > 0) {  // If there is a free time slot before deadline

            noOfJob++;                        // Job is scheduled
            totalProfit += jobs[i].second;    // Add its profit
            parent[slot] = slot - 1;          // Union step: mark this slot as filled
        }
    }

    // Return the total jobs scheduled and total profit earned
    return {noOfJob, totalProfit};
}


int main(){
    
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};


    vector<int> ans = jobSequencing(deadline, profit);

    for(int i : ans)
        cout << i << " ";

}