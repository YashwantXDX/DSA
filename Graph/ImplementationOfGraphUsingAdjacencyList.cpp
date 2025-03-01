#include<bits/stdc++.h>
using namespace std;

int main(){

    // Undirected Unweighted Graph

    // Got Vertex and Edges
    int vertex, edges;
    cin >> vertex >> edges;

    /*
    // Define the martrix of size verex
    vector<int> matrix[vertex];

    // take two temp variable which will be used to store data
    int u, v;
    for(int i = 0; i < edges; i++){

        cin >> u >> v;

        // u ke index me v ko push karo
        matrix[u].push_back(v);

        // v ke index me u ko push karo
        matrix[v].push_back(u);

    }

    for(int i = 0; i < vertex; i++){
        cout << i << " -> ";

        for(int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    */

    // Undirected Weighted Graph

    vector<pair<int, int>> matrix[vertex];

    int u, v, weight;

    for(int i = 0; i < edges; i++){

        cin >> u >> v >> weight;
        matrix[u].push_back(make_pair(v, weight));
        matrix[v].push_back(make_pair(u, weight));

    }

    for(int i = 0; i < vertex; i++){

        cout << i << " -> ";

        for(int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j].first<< " -> " << matrix[i][j].second << " , ";
        cout << endl;
    }

}