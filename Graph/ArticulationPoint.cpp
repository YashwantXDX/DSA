#include<bits/stdc++.h>
using namespace std;

/*

        IMPORTANT QUESTION
    
    Problem Link :- https://www.geeksforgeeks.org/problems/articulation-point-1/1

    Refer Video :- https://www.youtube.com/watch?v=HSAcx2mEVag

    This Problem is also known as Tarjans Algorithm

    Articulation Node means aaisa node jise htane se ek graph do ya uss se jyada graphs pe bat jaye

    Note :- Iss type ke question me hum Cycle wala logic nhi lga skte
            jha hum kehte hai ki node cycle ke part hai vo articulation nhi ho skte baaki sb ho skte hai kar ke

            yha par ye logic fail ho jayega, bridge wale questions pe ye logic kaam kr skta hai but Articulation point type ke questions pe nhi krega

*/

void DFS(int node, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &disc, vector<int> &low, vector<bool> &artpoint, int &timer){

    // discovery time and low time of node me timer ki value daal do
    disc[node] = timer;
    low[node] = timer;

    // Node ko visited mark kr do
    visited[node] = true;

    // Egde Case :- Agar root node ya starting node ke child ka count ek se jyda rha to vo bhi articulation node ho jayega
    // Agar sirf ek hi hai child to uss case me starting point ko ignore krna hai
    int child = 0;

    // Connections check kro
    for(int i = 0; i < adj[node].size(); i++){

        // Get the neighbour
        int neigh = adj[node][i];

        // agar neighbour orr parent same same hai
        // uss case ko ignore kro
        if(neigh == parent)
            continue;
        
        // Agar neighbour already visited hai mtlb cycle hai
        // uss case me hume bas low of node of update krna hai
        // minimum of low of neighbour and discovery time of node dono me se
        else if(visited[neigh])
            low[node] = min(low[node], disc[neigh]);
        
        // agar jo neighbour aaya hai vo naa hi visited hai orr naa hi parent hai
        else{

            // Timer ko increase kro
            timer++;

            // Child ko ek se increament kr do har node ke liye
            child++;

            // Ab neighbour ke liye DFS call krna hai parent rhega current node
            DFS(neigh, node, adj, visited, disc, low, artpoint, timer);

            // Low of node ko update kr do
            // minimum of low of node and low of neighbour se
            low[node] = min(low[node], low[neigh]);

            // Agar discovery of node chota ya equal hota hai neighbour ke low se
            // orr sath hi jo parent hai vo -1 ke barabar nhi hai
            // uss case me hum ye keh skte hai ki hume articulation point mil gya hai
            // artpoint vector me jaa kr uss node ko true mark kr do
            if(disc[node] <= low[neigh] && parent != -1)
                artpoint[node] = true;

        }

    }

    // Edge case :- 
    // check kro ki kisi node ka child ka count agar 1 se bda hua orr
    // parent -1 hai (root node ki baat ho rhi) 
    // uss case me hum keh skte hai ki root node bhi articulation point hai
    if(child > 1 && parent == -1)
        artpoint[node] = true;
                    

}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    
    // ye btayega ki kon kon se node articulation point hai
    vector<bool> artpoint(V, false);

    // discovery vector and low vector
    vector<int> disc(V), low(V);

    // Visited vector to mark the node which are already visited
    vector<bool> visited(V, false);

    // Time ka track rkho 
    int timer = 0;

    // DFS call kro starting node ko 0 rkh ke -1 as a parent
    DFS(0, -1, adj, visited, disc, low, artpoint, timer);

    // answer vector jo ki btayega ki kon konse node articulation node hai
    vector<int> ans;

    for(int i = 0; i < V; i++)
        if(artpoint[i] == true)
            ans.push_back(i);

    // By Chance agar mujhe koi bhi articulation point nhi milta 
    // uss case pe hume -1 return krna hai
    if(ans.size() == 0)
        return {-1};
    
    // Agar sb accha chla
    return ans;
}

int main(){

    vector<int> adj[] = {
        {0, 1},
        {1, 4},
        {2, 4},
        {3, 4},
        {2, 3},
    };

    int V = 5;

    vector<int> ans = articulationPoints(V, adj);

    for(int i : ans)
        cout << i << " ";

}