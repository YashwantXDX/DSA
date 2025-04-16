#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

*/

// Node structure for Trie
class TrieNode {
    public:
        TrieNode *child[26];      // Array to hold references to child nodes (26 letters)
        bool isEndOfWord;         // Marks if this node represents the end of a word

        TrieNode() {
            isEndOfWord = false;  // Initially not the end of any word
            for(int i = 0; i < 26; i++)
                child[i] = NULL;   // Initialize all children as NULL
        }
};

class Trie {
  public:
    TrieNode *root;  // Root node of the Trie

    Trie() {
        root = new TrieNode();  // Initialize root when Trie is created
    }

    // Function to insert a word into the Trie
    void insert(string &word) {
        TrieNode *node = root;  // Start from root

        for(char c : word) {
            int index = c - 'a';  // Convert character to index (0-25)

            // If there is no node at this index, create a new node
            if(node->child[index] == NULL) {
                node->child[index] = new TrieNode();  // Create a new node
                node = node->child[index];            // Move to the new node
            }
            else {
                node = node->child[index];            // Move to existing node
            }
        }

        node->isEndOfWord = true;  // Mark the last node as end of word
    }

    // Function to search for a full word in the Trie
    bool search(string &word) {
        TrieNode *node = root;

        for(char c : word) {
            int index = c - 'a';

            // If the path doesn't exist, word is not present
            if(node->child[index] == NULL)
                return false;

            node = node->child[index];  // Move to next node
        }

        return node->isEndOfWord;  // Check if it's the end of a valid word
    }

    // Function to check if a prefix exists in the Trie
    bool isPrefix(string &word) {
        TrieNode *node = root;

        for(char c : word) {
            int index = c - 'a';

            // If the prefix path breaks, return false
            if(node->child[index] == NULL)
                return false;

            node = node->child[index];  // Move to next node
        }

        return true;  // All characters matched; it's a valid prefix
    }
};
