#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/parallel-courses-iii/description/

    Refer Video :- https://www.youtube.com/watch?v=gLJmbAV74Bs&t=2816s

*/

int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    
    // Adjacency list to represent the graph (prerequisite relations)
    vector<int> adj[n];

    // Array to store in-degree (number of prerequisites for each course)
    vector<int> InDegree(n, 0);

    // Build the adjacency list and in-degree array
    for(int i = 0; i < relations.size(); i++) {
        // Since courses are 1-based, subtract 1 for zero-based indexing
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
        
        // Increment in-degree for the dependent course
        InDegree[relations[i][1] - 1]++;
    }
    
    queue<int> q;

    // Push all courses with no prerequisites into the queue
    for(int i = 0; i < n; i++)
        if(InDegree[i] == 0)
            q.push(i);
    
    // Array to store the earliest time required to start each course
    vector<int> CourseTime(n, 0);

    // Process the courses in topological order (Kahn's algorithm)
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        // Traverse all dependent courses
        for(int i = 0; i < adj[node].size(); i++) {
            int nextCourse = adj[node][i];

            // Decrease in-degree (prerequisite completed)
            InDegree[nextCourse]--;

            // If all prerequisites for the next course are completed, add it to the queue
            if(InDegree[nextCourse] == 0)
                q.push(nextCourse);
            
            // Update the earliest time to start the next course
            CourseTime[nextCourse] = max(CourseTime[nextCourse], CourseTime[node] + time[node]);
        }
    }

    int ans = 0;

    // Calculate the minimum time required to complete all courses
    for(int i = 0; i < n; i++)
        ans = max(ans, CourseTime[i] + time[i]);

    return ans;
}

int main(){

    vector<vector<int>> relations = {
        {1,5},
        {2,5},
        {3,5},
        {3,4},
        {4,5}
    };

    vector<int> time = {1,2,3,4,5};

    cout << minimumTime(5, relations, time);

}