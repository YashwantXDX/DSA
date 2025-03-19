#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo-1587115621/1

    Refer Video :- https://www.youtube.com/watch?v=9VYiCAJ0mI8&t=3760s

    Time Complexity :- O(V + E) // Ignore the sorting as that was as per question

    Space Complexity :- O(V + E)

    Problem Logic :- 

    Understanding the Problem :

    We have a directed graph (a graph where edges have directions). We need to find all Strongly Connected Components (SCCs) in this graph.
    A Strongly Connected Component (SCC) is a group of nodes where:

        Every node can reach every other node in that group.

    To solve this, we use Tarjan’s Algorithm, which is based on Depth First Search (DFS).

    Step-by-Step Logic :

    Step 1: Initialize Discovery and Low Time

        Each node has a discovery time (disc[]) that tells when the node is first visited.
        Each node also has a low time (low[]) that tells the earliest visited node reachable from that node.

    Step 2: Perform DFS :

        Start DFS traversal from an unvisited node.
        For each neighbor:
        If the neighbor is not visited, call DFS for it and update low[node].
        If the neighbor is already in the stack, update low[node] to the minimum discovery time of that neighbor.

    Step 3: Identify SCC :

        If disc[node] == low[node], it means we found an SCC.
        Pop all nodes from the stack until we reach the current node and store them as an SCC.

    Step 4: Sort SCCs :

        Sort the SCC nodes (as required).
        Sort the list of SCCs (as required).

    Explanation of the Code :-

    DFS Function (DFS) :

        Marks nodes as visited.
        Updates discovery and low values.
        Pushes nodes onto the stack.
        Checks for back edges to update low[node].
        When an SCC is found, it extracts nodes from the stack.

    Main Function (tarjans) :

        Initializes discovery and low arrays.
        Calls DFS for each unvisited node.
        Returns the sorted list of SCCs.

    Final Output : The function returns a list of SCCs, where each SCC is a group of connected nodes sorted in increasing order.

*/

void DFS(int node, vector<int> adj[], vector<int> &disc, vector<int> &low, stack<int> &s, vector<bool> &visited, int &timer, vector<bool> &InStack, vector<vector<int>> &ans){

    // node ko visited mark kro
    visited[node] = true;

    // Discovery Time and Low time ko timer se mark kro
    disc[node] = timer;
    low[node] = timer;

    // Node ko stack me push kro and mark kro ki node stack me present hai
    s.push(node);

    InStack[node] = true;

    // Node ke connections me check kro
    for(int i = 0; i < adj[node].size(); i++){

        // neighbour ko bahar nikaalo
        int neigh = adj[node][i];

        // Agar neighbour visited nhi hai to timer ko increase kro and uske liye DFS call kro
        if(!visited[neigh]){

            timer++;

            DFS(neigh, adj, disc, low, s, visited, timer, InStack, ans);

            // Update the low of node with minimum of low[node] and low[neigh]
            low[node] = min(low[node], low[neigh]);

        }

        // Agar neighbour visited hai
        else{

            // Check kro ki kahi node stack me present hai?
            // agar present hai mtlb hum low of node ko update kr skte hai
            // with minimum of low of node and discovery time of neighbour se
            if(InStack[neigh])
                low[node] = min(low[node], disc[neigh]);
            
        }

    }

    // Loop se bahar aane ke baad check kro ki kahi node ka discovery time and low eqaul to nhi?
    // agar equal aa jata hai uss case me hume stack me elements pop krne hai jb tk node pop nhi ho jata
    // Orr jitne elements pop ho rhe hai use ek vector me store because they are strongly connected to each other
    if(disc[node] == low[node]){

        vector<int> temp;

        // Stack ko empty kro jb tk top element node ke barabar na ho jaye
        while(!s.empty() && s.top() != node){

            temp.push_back(s.top());

            // Ye bhi btao ki ab vo elements stack ke andar nhi rha
            InStack[s.top()] = false;

            s.pop();

        }

        // While loop ke bahar aane ke bad abhi bhi stack ke top pe node present hai
        // use bhi vector me push kro and usko stack se pop kro
        temp.push_back(s.top());

        // orr use bhi mark kro not present in Stack
        InStack[s.top()] = false;

        s.pop();

        // ab vector ke elements ko sort kro as per question
        sort(temp.begin(), temp.end());

        // After that uss vector ko answer me push kar do
        ans.push_back(temp);

    }

}

vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    
    // Answer vector
    vector<vector<int>> ans;

    // Discovery Time and Low Time
    vector<int> disc(V), low(V);

    // Stack
    stack<int> s;

    // Visited Vector
    vector<bool> visited(V, false);

    // Timer Variable
    int timer = 0;

    // InStack Vector to find if the node is present in the stack or not
    vector<bool> InStack(V, false);

    // Har Node pe jao orr non visited nodes pe DFS call kro orr answer nikaalo
    for(int i = 0; i < V; i++)
        if(!visited[i])
            DFS(i, adj, disc, low, s, visited, timer, InStack, ans);
    
    // Sort the 2D array as per the question
    sort(ans.begin(), ans.end());

    return ans;

}

int main(){

    vector<int> adj[] = {
        {1, 0},
        {0, 2},
        {2, 1},
        {0, 3},
        {3, 4}
    };

    int V = 5;

    vector<vector<int>> ans = tarjans(V, adj);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}