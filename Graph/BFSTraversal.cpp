#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

    Refer Video :- https://www.youtube.com/watch?v=Vtu7qgF0ksw

    Problem Logic :- To Do BFS in Graph, we need to follow this steps :

        i. Push any element of graph into the queue and mark it as visited
        ii. Jb tk queue empty nhi ho jata tb tk chlo.
        iii. Queue ke front ke element ko bahar nikaalo orr ans me push karo
        iv. Ab uss element ke connections ko traverse kro orr check kro visited hai ya nhi
        v. Jo visited nhi hai unko queue me daalo orr use visited mark karo
        vi. aakhir me answer ko return krva do

*/

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    
    queue<int> q;
    vector<bool> visited(adj.size(), 0);
    vector<int> ans;

    // By default 0 se start krne bola hai question
    q.push(0);
    visited[0] = 1;
    
    while(!q.empty()){

        // Queue ke front ko bahar nikaalo
        int temp = q.front(); q.pop();

        // Use push karo
        ans.push_back(temp);

        // Connections check karo
        for(int i = 0; i < adj[temp].size(); i++){
            
            // Not viisted then visited mark karo orr queue me push kar do
            if(!visited[adj[temp][i]]){

                visited[adj[temp][i]] = 1;
                q.push(adj[temp][i]);

            }

        }

    }

    return ans;

}

int main(){

    vector<vector<int>> matrix = {
        {1,2},
        {0,7,5},
        {0,3,4},
        {2},
        {2},
        {1,6},
        {5,8},
        {1,8},
        {6,7}
    };

    vector<int> ans = bfsOfGraph(matrix);

    for(int i : ans)
        cout << i << " ";

}