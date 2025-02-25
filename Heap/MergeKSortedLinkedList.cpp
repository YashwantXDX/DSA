#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

    Refer Video :- https://www.youtube.com/watch?v=XePjO6Q8FDE

    Problem Logic :-

    1. make a min heap of pair<int, Node*>

    2. make a Node ans with dummy data and use temp to go forward

    3. loop until min heap goes empty and store the first element of pair as data and second element of pair as ptr.

    4. add the data into the linked list.

    5. check if ptr -> next exist or not as this tell if the linked list of the given has elements or not.

    6. return the ans

*/

class Node{
    public:
    int data; Node *next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

// Method 1
// T.C. - O(K log N)
// S.C. = O(N + K)

Node* mergeKLists(vector<Node*>& arr) {
    
    // Min Heap of pair<int, Node*>
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> p;
    
    // Answer Variables
    Node *ans = new Node(0);
    Node *temp = ans;

    // Push the elements and address of the head node of the given
    for(int i = 0; i < arr.size(); i++)
        p.push(make_pair(arr[i] -> data, arr[i]));
    
    // Till min heap exists
    while(!p.empty()){

        // Grab the data and address of the minimum element
        int data = p.top().first;
        Node *ptr = p.top().second;
        p.pop();

        // Add them to the list
        temp -> next = new Node(data);
        temp = temp -> next;

        // Check if the list of the given exist further
        if(ptr -> next)
            p.push(make_pair(ptr -> next -> data, ptr -> next));

    }

    return ans -> next;

}


// Method 2 - More Efficient

/*

    We Use custom Compare class to compare the value in the min heap

    direct putting into min heap reduce the Time Complexity from O(N log N) to O(N)

*/

// T.C. - O(K log N)
// S.C. = O(K)

class Compare{
    public:

    // For Min Heap use  > and for Max Heap use <
    // Heap me ye reverse tarike se kaam krta hai

    bool operator()(Node *a, Node *b){
        return a -> data > b -> data;
    }
};

Node* mergeKLists2(vector<Node*>& arr){

    // O(N) Time me daal diye 
    priority_queue<Node*, vector<Node*>, Compare>p(arr.begin(), arr.end());

    // Answer Variable
    Node *ans = new Node(0); // Dummy Node
    Node *temp = ans;

    while(!p.empty()){

        // Extract the top from the min heap
        Node *ptr = p.top();
        p.pop();

        // point the next of temp to ptr
        temp -> next = ptr;
        temp = temp -> next;

        // Check if the next data exist of the given
        if(ptr -> next)
            p.push(ptr -> next);

    }
    
    return ans -> next;

}


int main(){

    Node *first = new Node(1);
    first -> next = new Node(2);
    first -> next -> next = new Node(3);

    Node *second = new Node(4);
    second -> next = new Node(5);

    Node *third = new Node(5);
    third -> next = new Node(6);

    Node *forth = new Node(7);
    forth -> next = new Node(8);

    vector<Node*> arr = {first, second, third, forth};

    cout << "Without Merging\n";
    for(int i = 0; i < arr.size(); i++){
        Node *curr = arr[i];

        while(curr){
            cout << curr -> data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }

    cout << "With Merging\n";
    Node *merged = mergeKLists2(arr);

    while(merged){
        cout << merged -> data << " ";
        merged = merged -> next;
    }
}