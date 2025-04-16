#include<bits/stdc++.h>
using namespace std;

/*

    Trie ka logic hum un problems me lga skte hai

    Jin Problems me hume Search Krna ho kisi String me,
    Ya koi string ko match krana ho

    Common Characters, Prefix or some these type of questions

*/

class TrieNode{

    public:

        // 26 child
        TrieNode *child[26];

        // check for end of the word
        bool isEndOfWord;

        TrieNode(){

            // By default end of word will be false
            isEndOfWord = false;

            // make all the child as NULL
            for(int i = 0; i < 26; i++)
                child[i] = NULL;

        }

};

class Trie{

    TrieNode *root;

    public:
        Trie(){
            root = new TrieNode();
        }

        // Insert Word
        void insert(string word){

            // Node Bnao
            TrieNode *node = root;

            // Har ek character ko traverse kro
            for(char c : word){

                // uss character ka index nikaalo
                int index = c - 'a';

                // agar node ke index child null hai to new memory allocate kro orr next me jao
                if(node -> child[index] == NULL){
                    node -> child[index] = new TrieNode();
                    node = node -> child[index];
                }
                
                // agar memory present hai to next me jao
                else
                    node = node -> child[index];

            }

            // after loop ends, we got the end of the word by end character
            // mark that as true for that character
            node -> isEndOfWord = true;

        }

        // Search Word
        bool search(string word){

            // Node to point root
            TrieNode *node = root;

            // baari baari har character me jao
            for(char c : word){

                // character ka index pkdo
                int index = c - 'a';

                // uss character ko check kro ki present hai ya nhi child me
                // agar child ka index null aata hai means vo present nhi hai
                if(node -> child[index] == NULL)
                    return false;
                
                // agar child present hai to agle me jao
                else
                    node = node -> child[index];

            }

            // loop khtm hone ke baad, end of the word check kro
            // agar true hai to word present hai
            // agar false hai to present nhi hai
            return node -> isEndOfWord;

        }

        // Delete Word
        bool remove(TrieNode *node, string word, int index){

            // Base Condition
            if(index == word.size()){

                // Is Not End of word
                if(node -> isEndOfWord == false)
                    return false;
                
                // If end of the word
                else{

                    // end of word hai to use false kar do
                    node -> isEndOfWord = false;

                    // Child Exist or not
                    return isEmpty(node);

                }
            }

            // Get the index of the character
            int idx = word[index] - 'a';
            
            // Character is not exist of the word
            if(node -> child[idx] == NULL)
                return false;

            // Character is exist of the word
            else{

                // recursive call for next character deletion in tree
                bool shouldDeleteChild = remove(node -> child[idx], word, index + 1);

                // If the child is deletable then
                // free up the memory
                // make the child of index to NULL
                // And check if it is not the end of the word and is it empty or not
                // means it doesnt exist any further child
                if(shouldDeleteChild == true){

                    delete node -> child[idx];
                    node -> child[idx] = NULL;

                    // Kya vo character end of the word to nhi 
                    // orr kya vo character ka koi children to nhi
                    // dono true honge tbhi delete hoga vo character
                    return node -> isEndOfWord == false && isEmpty(node);

                }

            }
            
            // If the character not exist then simply return false
            return false;

        }

        bool isEmpty(TrieNode *node){

            // Agar ek bhi node ka child NULL nhi milta
            // Uss case me hume use delete nhi krna hai
            for(int i = 0; i < 26; i++)
                if(node -> child[i] != NULL)
                    return false;
            
            // Agar sare child emtpy hai to vo deletable hai
            return true;

        }

        void deleteWord(string word){

            // Method to remove the word
            remove(root, word, 0);

        }

};

int main(){

    Trie *tree = new Trie();

    tree->insert("apple");
    tree->insert("appex");
    tree->insert("almond");

    tree -> deleteWord("apple");

    cout << tree -> search("apple");
    cout << tree -> search("appex");

    return 0;

}