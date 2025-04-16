#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/phone-directory4628/1

    Just LEarn How to use and impliment Trie and Thats all
    All the questions are easy when you understood the TRIE.

*/

// Trie Node structure
class TrieNode {
 public:
    bool isEndOfWord;           // True if the node marks the end of a word
    TrieNode *child[26];        // Array to store child nodes for each character 'a' to 'z'

    TrieNode() {
        isEndOfWord = false;    // Initially, no word ends here
        for (int i = 0; i < 26; i++)
            child[i] = NULL;    // Initialize all children to NULL
    }
};

// Trie data structure class
class Trie {
 public:
    TrieNode *root;  // Pointer to the root node of the Trie

    Trie() {
        root = new TrieNode();  // Create a new root node when Trie is initialized
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode *node = root;  // Start from the root

        // Traverse each character of the word
        for (char c : word) {
            int index = c - 'a';  // Get index of character (0 for 'a', 1 for 'b', ..., 25 for 'z')

            // If the path does not exist, create a new node
            if (node->child[index] == NULL) {
                node->child[index] = new TrieNode();  // Create a new Trie node
                node = node->child[index];            // Move to the newly created node
            }
            // If it exists, move to the next node
            else {
                node = node->child[index];            // Continue to the next node
            }
        }

        // After inserting all characters, mark the last node as the end of a word
        node->isEndOfWord = true;
    }

    // Function to search for all contacts that match a given prefix
    vector<string> search(string prefix) {
        TrieNode *node = root;  // Start search from root

        // Traverse the prefix to reach the end node
        for (char c : prefix) {
            int index = c - 'a';  // Convert character to index

            // If prefix path doesn't exist, return {"0"}
            if (node->child[index] == NULL)
                return {"0"};  // No contacts with this prefix
            else
                node = node->child[index];  // Move to next node in the prefix
        }

        // Use DFS to gather all words with the given prefix
        vector<string> currAns;  // Stores current set of contacts
        findContact(node, prefix, currAns);  // Recursive function to find all contacts

        return currAns;  // Return all matching contacts
    }

    // Helper function to find all contacts starting from the given node
    void findContact(TrieNode *node, string prefix, vector<string> &currAns) {
        // If current node marks end of a word, add the word to the result list
        if (node->isEndOfWord == true)
            currAns.push_back(prefix);  // Add the word to the result

        // Check for all characters a-z
        for (char c = 'a'; c <= 'z'; c++) {
            int index = c - 'a';  // Convert character to index

            // If path exists for the current character, call recursively
            if (node->child[index] != NULL)
                findContact(node->child[index], prefix + c, currAns);  // Add character to prefix and recurse
        }
    }
};

// Main function to display contact suggestions after typing each character of the search string
vector<vector<string>> displayContacts(int n, string contact[], string s) {
    Trie *tree = new Trie();  // Create a new Trie

    // Insert all contact names into the Trie
    for (int i = 0; i < n; i++)
        tree->insert(contact[i]);  // Add each contact to the Trie

    vector<vector<string>> result;  // Final result for all prefixes
    string prefix = "";             // To store prefix as we go

    // For each character typed in the search string
    for (int i = 0; i < s.length(); i++) {
        prefix += s[i];                       // Add current character to prefix
        vector<string> currAns = tree->search(prefix);  // Search for all contacts with this prefix
        result.push_back(currAns);           // Store result for this prefix
    }

    return result;  // Return 2D vector with suggestions for each prefix
}

int main(){

    int n = 3;

    string contacts[] = {"geeikistest", "geeksforgeeks", "geeksfortest"};

    string s = "geeips";

    vector<vector<string>> ans = displayContacts(n, contacts, s);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}