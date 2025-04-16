#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/trie-delete/1

*/

#define ALPHABET_SIZE (26)

class trie_node_t
{
    public:
    int value;
    trie_node_t *children[ALPHABET_SIZE];

    trie_node_t(){

        value = 0;

        for(int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;

    }

};

class Trie{

    public:

    void deleteKey(trie_node_t *root, char key[])
  {
        remove(root, key, 0);
  }
  
   bool remove(trie_node_t *node, char word[], int index){

        // Base Condition
        if(word[index] == '\0'){
    
            // Is Not End of word
            if(node -> value == 0)
                return false;
            
            // If end of the word
            else{
    
                // end of word hai to use false kar do
                node -> value = 0;
    
                // Child Exist or not
                return isEmpty(node);
    
            }
        }
    
        // Get the index of the character
        int idx = word[index] - 'a';
        
        // Character is not exist of the word
        if(node -> children[idx] == NULL)
            return false;
    
        // Character is exist of the word
        else{
    
            // recursive call for next character deletion in tree
            bool shouldDeleteChild = remove(node -> children[idx], word, index + 1);
    
            // If the child is deletable then
            // free up the memory
            // make the child of index to NULL
            // And check if it is not the end of the word and is it empty or not
            // means it doesnt exist any further child
            if(shouldDeleteChild == true){
    
                delete node -> children[idx];
                node -> children[idx] = NULL;
    
                // Kya vo character end of the word to nhi 
                // orr kya vo character ka koi children to nhi
                // dono true honge tbhi delete hoga vo character
                return node -> value == 0 && isEmpty(node);
    
            }
    
        }
        
        // If the character not exist then simply return false
        return false;
    
    }
    
    bool isEmpty(trie_node_t *node){
    
        // Agar ek bhi node ka child NULL nhi milta
        // Uss case me hume use delete nhi krna hai
        for(int i = 0; i < ALPHABET_SIZE; i++)
            if(node -> children[i] != NULL)
                return false;
        
        // Agar sare child emtpy hai to vo deletable hai
        return true;
    
    }
};