#include<bits./stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

    Refer Video :- https://www.youtube.com/watch?v=sCXQAXD2e_U

    Time Complextity :- 
        Best Case - O(VlogV + E)
        Worst Case - O(ElogV)

    Space Complextity :- O(V + E)

*/

int findParent(int x, vector<int> &parent){
        
    // Agar parent of x barabar ho mtlb vhi ultimate parent hai
    if(parent[x] == x)
        return x;
    
    // Path Compression kro
    // means jo bhi nodes connected hai unko unke ultimate parent se connect krva do
    parent[x] = findParent(parent[x], parent);
    
    // Return kr do uss node ko
    return parent[x];
    
}

void UnionByRank(int x, int y, vector<int> &parent, vector<int> &rank){
    
    // Ultimate parent of x and y dhundo
    int px = findParent(x, parent);
    int py = findParent(y, parent);
    
    // Agar px ka rank chota hai py ke rank se to ultimate parent update kr do px ka
    if(rank[px] < rank[py])
        parent[px] = py;
    
    // Agar px ka rank bada hai py ke rank se to ultimate parent update kr do py ka
    else if(rank[px] > rank[py])
        parent[py] = px;
    
    // Agar dono ki rank same hai to kisi ko bhi update kr skte ho
    // Update krne ke baad jis se update kiya hai uska eank ek se bhda do
    else{
        
        parent[px] = py;
        rank[py]++;
        
    }
    
}

int spanningTree(int V, vector<vector<int>> adj[]) {
    
    // Parent and Rank Vector
    vector<int> parent(V), rank(V, 0);
    
    // Mark the initial parents of all nodes
    for(int i = 0; i < V; i++){
        
        // Har node ka parent vo khud rhega    
        parent[i] = i;
        
    }
    
    // Temp vector bnao weight, node, parent ko store krne ke liye
    vector<pair<int, pair<int, int>>> temp(V);
    
    // Har node me jao
    for(int i = 0; i < V; i++){
        
        // Har Edge orr uske weight ki nikalo adj list se
        for(int j = 0; j < adj[i].size(); j++){
            
            // Temp me weight, phla node or uske edge wala node ko dalo
            temp.push_back({adj[i][j][1], {i, adj[i][j][0]}});
            
        }
        
    }
    
    // Min heap bnao orr temp ko daalo jiss se T.C. - O(E) chle jaye
    // Bina temp ke kroge to O(ElogE) jayegi
    priority_queue<pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());
    
    // Cost or edge bnao
    int cost = 0, edges = 0;
    
    // jb tk min heap empty na ho jaye
    while(!p.empty()){
        
        // Weight, phle node, edge wala node nikaalo
        int weight = p.top().first;
        int x = p.top().second.first;
        int y = p.top().second.second;
        
        // top ko pop kro
        p.pop();
        
        // x and y dono ke ultimate parent different rhne chahiye
        // same rhe to ignore kro
        if(findParent(x, parent) != findParent(y, parent)){
            
            // Cost ko update kro
            cost += weight;
            
            // Edges ko update kro ek se
            edges++;
            
            // Ab X and Y ko jod do
            UnionByRank(x, y, parent, rank);
            
        }
        
        // Agar edges ka number, V - 1 tk ho jata hai
        // mtlb sare vertex connect ho gye hai
        // uss case me simple loop break kr do
        if(edges == V - 1)
            break;
        
    }
    
    // Finally Cost ko Return kr do
    return cost;
    
}



int main(){

    int V = 3;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5}); 

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1}); 

    cout << spanningTree(V, adj);

}