#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/huffman-encoding3345/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=12795s

    NOTE :- VERY VERY VERY IMPORTANT

    Algorithm Steps :- 

    Step 1: Create Leaf Nodes

    1. For each character in the string S and its corresponding frequency in f, create a node.

    2. Each node stores:

        i. the character,

        ii. its frequency,

        iii. and points to its left and right children (initially NULL).

    3. Insert all these nodes into a min-heap (priority queue) so that the node with the smallest frequency is on top.

    Step 2: Build the Huffman Tree

    1. While there is more than one node in the min-heap:

        i. Remove the two nodes with the smallest frequencies.

        ii. Create a new internal node with:

            a. Frequency equal to the sum of the two removed nodes,

            b. A dummy character (like '$'),

            c. The two nodes as its left and right children.

        iii. Insert this new node back into the min-heap.

    2. Repeat this process until only one node remains in the heap. This node becomes the root of the Huffman Tree.

    Step 3: Generate Huffman Codes

    1. Use preorder traversal to walk through the Huffman Tree:

        i. Start from the root with an empty string ("").

        ii. When moving to the left child, add '0' to the string.

        iii. When moving to the right child, add '1'.

        iv. When a leaf node (real character) is reached, store the current binary string as the Huffman code for that character.

    2. Backtrack after each path to explore the next branch.

    Step 4: Return the Codes

    1. Return the list of Huffman codes generated from the tree.

*/  

// Define a tree node for the Huffman Tree
class Node {
    public:
        int freq;       // Frequency of the character
        char c;         // Character itself
        Node *left, *right; // Left and right children
    
        // Constructor to initialize the node
        Node(int freq, char c) {
            this -> freq = freq;
            this -> c = c;
            left = right = NULL;
        }
    };
    
    // Comparator class to sort nodes based on frequency in a min-heap
class comp {
public:
    // Overloading the () operator to compare two Node pointers
    bool operator() (Node *a, Node *b) {
        return a -> freq > b -> freq; // Min heap based on frequency
    }
};

// Helper function to perform preorder traversal of the Huffman Tree
void preorder(Node *root, vector<string> &ans, string &temp) {
    
    // If the root is null, return
    if(root == NULL) return;

    // If it's a leaf node (i.e., a character node), save the code path
    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(temp); // Add the binary path to result
        return;
    }

    // Go left → add '0' to the path
    temp.push_back('0');
    preorder(root -> left, ans, temp);

    // Backtrack → remove last character
    temp.pop_back();

    // Go right → add '1' to the path
    temp.push_back('1');
    preorder(root -> right, ans, temp);

    // Backtrack again
    temp.pop_back();
}

// Main function to generate Huffman codes for characters
vector<string> huffmanCodes(string S, vector<int> f, int N) {

    // Step 1: Create a min-heap (priority queue)
    priority_queue<Node *, vector<Node *>, comp> p;

    // Step 2: Insert all characters and their frequencies into the heap
    for(int i = 0; i < N; i++) {
        p.push(new Node(f[i], S[i]));
    }

    // Step 3: Build the Huffman Tree
    while(p.size() > 1) {

        // Remove the two nodes with the lowest frequency
        Node *first = p.top(); p.pop();
        Node *second = p.top(); p.pop();

        // Create a new internal node with these two as children
        // Use '$' as a dummy character for internal nodes
        Node *root = new Node(first->freq + second->freq, '$');

        root->left = first;
        root->right = second;

        // Push the new node back into the heap
        p.push(root);
    }

    // Step 4: Generate Huffman codes using preorder traversal
    vector<string> ans;
    string temp;
    
    Node *root = p.top(); p.pop(); // Root of the Huffman Tree
    preorder(root, ans, temp);     // Traverse tree and fill answers

    return ans;
}
    

int main(){
    
    string S = "abcdef";
    vector<int> f = {5,9,12,13,16,45};
    int N = S.size();
    
    vector<string> ans = huffmanCodes(S, f, N);

    for(string i : ans)
        cout << i << " ";

}