#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/trie-delete/1

*/

#define ALPHABET_SIZE (26)  // Total lowercase English letters (a-z)

// Trie node structure
class trie_node_t {
    public:
        int value;  // Used to indicate if a word ends here (non-zero means end of word)
        trie_node_t *children[ALPHABET_SIZE];  // Array of child pointers for each alphabet letter

        trie_node_t() {
            value = 0;  // Initially no word ends at this node
            for(int i = 0; i < ALPHABET_SIZE; i++)
                children[i] = NULL;  // Initialize all child pointers to NULL
        }
};

// Trie class containing deletion functionality
class Trie {
    public:

    // Public function to delete a word from Trie
    void deleteKey(trie_node_t *root, char key[]) {
        remove(root, key, 0);  // Call recursive function to delete key starting from index 0
    }

    // Recursive function to delete a word from the Trie
    bool remove(trie_node_t *node, char word[], int index) {

        // Base Case: If we've reached the end of the word
        if(word[index] == '\0') {

            // If this is not the end of any word, return false (word not present)
            if(node->value == 0)
                return false;

            // If this is the end of the word, remove it
            node->value = 0;

            // Return true if the current node has no children (safe to delete)
            return isEmpty(node);
        }

        // Get index for the current character (0 to 25)
        int idx = word[index] - 'a';

        // If character does not exist in current node's children
        if(node->children[idx] == NULL)
            return false;

        // If character exists, recursively attempt to delete the rest of the word
        bool shouldDeleteChild = remove(node->children[idx], word, index + 1);

        // If child can be deleted
        if(shouldDeleteChild == true) {

            // Free the memory and mark the child as NULL
            delete node->children[idx];
            node->children[idx] = NULL;

            // Return true if this node is not an end of another word
            // AND has no children (safe to delete this as well)
            return node->value == 0 && isEmpty(node);
        }

        // If child should not be deleted, return false
        return false;
    }

    // Helper function to check if a node has any children
    bool isEmpty(trie_node_t *node) {
        for(int i = 0; i < ALPHABET_SIZE; i++)
            if(node->children[i] != NULL)
                return false;  // Found a child, so not empty
        return true;  // All children are NULL, so node is empty
    }
};
