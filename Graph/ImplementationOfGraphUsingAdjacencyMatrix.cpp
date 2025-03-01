#include<bits/stdc++.h>
using namespace std;

/*

    This is Undirected Weighted Graph, we can play along with this, like we can make directed unweighted graph, directed weighted graph etc.

*/

int main(){

    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> matrix(vertex, vector<int> (vertex, 0));

    int u, v, weight;
    for(int i = 0; i < edges; i++){

        cin >> u >> v >> weight;
        matrix[u][v] = weight;
        matrix[v][u] = weight;

    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

}