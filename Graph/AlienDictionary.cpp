#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/alien-dictionary/1

    Refer Video :- https://www.youtube.com/watch?v=gLJmbAV74Bs&t=1296s


*/

string findOrder(vector<string> &words) {
    
    vector<int> adj[26]; // Adjacency list for graph (26 letters)
    vector<int> InDegree(26, 0); // Tracks incoming edges for each character
    unordered_set<int> chars; // Stores unique characters present in the words

    // Step 1: Identify all unique characters in the given words
    for(const string &word : words){
        for(char c : word)
            chars.insert(c - 'a');
    }

    // Step 2: Build the adjacency list by comparing adjacent words
    for(int i = 0; i < words.size() - 1; i++){

        string str1 = words[i], str2 = words[i + 1];
        int j = 0, k = 0;

        // Find the first differing character
        while(j < str1.size() && k < str2.size() && str1[j] == str2[k]){
            j++; k++;
        }

        // Edge case: If str1 is longer but is a prefix of str2 → Invalid order
        if(j < str1.size() && k == str2.size())
            return "";
        
        // Create a directed edge (order dependency)
        if(j < str1.size() && k < str2.size()){
            adj[str1[j] - 'a'].push_back(str2[k] - 'a');
            InDegree[str2[k] - 'a']++;
        }
    }

    // Step 3: Perform Kahn's Algorithm (BFS-based Topological Sorting)
    queue<int> q;
    string ans = "";

    // Push nodes with zero in-degree into the queue
    for(int i : chars){
        if(InDegree[i] == 0)
            q.push(i);
    }
    
    // Process the characters in topological order
    while(!q.empty()){

        int node = q.front();
        q.pop();
        ans += (node + 'a'); // Convert index back to character
        
        // Reduce in-degree of adjacent characters
        for(int i = 0; i < adj[node].size(); i++){
            InDegree[adj[node][i]]--;

            if(InDegree[adj[node][i]] == 0)
                q.push(adj[node][i]);
        }
    }

    // Step 4: If all characters are sorted, return the result, else return ""
    return ans.size() == chars.size() ? ans : "";
}


int main(){

    vector<string> words = {"cb", "cba", "a", "bc"};

    string ans = findOrder(words);
    cout << ans;

}