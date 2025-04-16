#include<bits/stdc++.h>
using namespace std;

/*

    Segment Tree ka logic hum tb lga skte hai

    Jb Hume koi range me problem solve krna ho

    Like minimum dhund lo range me, maximum dhund lo range me, Sum, Product etc type

    Range Type ki problems me Segment Tree Kaam Aayega

    Real Life Appliations :-

    Traffic, Network, Stock Market, Weather Forecasting, etc.

*/

class SegmentTree{

    // Segment Tree -> This array should be 4 * size of segment tree for safe side
    vector<int> tree;

    // Array which is inputed
    vector<int> arr;

    // Size of array
    int size;

    // To Access Child, we follow previous tree approach i.e.
    // i -> parent and 2 * i + 1 -> left child and 2 * i + 2 -> right child

    public:
        SegmentTree(vector<int> input){

            // Get the size of input array
            size = input.size();

            // Copy the input array into this array
            arr = input;

            // Segment Tree ko resize karo
            // with size = 4 * size
            tree.resize(4 * size);

            // Segment tree create kar do
            // Root Node Index, Starting Index, End Index 
            build(0, 0, size - 1);

        }

        void build(int node, int start, int end){

            // Base Condition
            if(start == end){

                tree[node] = arr[start];
                return;

            }

            // Mid Index Nikaalo
            int mid = start + (end - start) / 2;

            // Create Left Child
            build(2 * node + 1, start, mid);
            
            // Create Right Child
            build(2 * node + 2, mid + 1, end);

            // Now make Sum of both nodes i.e. left and right child
            // and store them as the child of their sum
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];

        }

        int query(int left, int right){

            // Root Node Index, Start, End, Left and Right
            return range(0, 0, size - 1, left, right);

        }

        int range(int node, int start, int end, int left, int right){

            // Fully Out Of Range
            // agar end chota hua left se ya phir start bda hua right se
            // To out of range
            if(end < left || start > right)
                return 0;

            // Fully In Range
            // Agar left chota hua start se and end chota hua right se
            // Means In Range
            if(left <= start && end <= right){

                // Simply Return the current node answer in the tree
                return tree[node];

            }

            // Overlapping Or Partially In range
            int mid = start + (end - start) / 2;

            // Left Child me Jao
            int leftChildSum =  range(2 * node + 1, start, mid, left, right);

            // Right Child me Jao
            int rightChildSum = range(2 * node + 2, mid + 1, end, left, right);

            // Dono ke sum ko upar return kar do
            return leftChildSum + rightChildSum;

        }

        // Get the update function with index and value
        // in which index the value should be updated
        void update(int index, int value){

            // Root Node, start, end, index, value
            updateIndex(0, 0, size - 1, index, value);

            // Update the Array Index with updated Value
            arr[index] = value;

        }

        void updateIndex(int node, int start, int end, int index, int value){

            // Base Condition
            // Agar out of range hai to simply return
            if(index > end || index < start)
                return;
            
            // Agar Bottom me poch gye, means vo index pe
            if(start == end){
                tree[node] = value;
                return;
            }

            // If range ke andar hai index
            // Phle jo value hai uss se tree[node] ko minus kro 
            // Uske baad jo value update ho rha hai uss se tree[node] me add kro
            // tree[node] = tree[node] - arr[index]
            // tree[node] = tree[node] + value
            tree[node] += value - arr[index];

            // Mid Nikaalo
            int mid = start + (end - start) / 2;

            // Left Child me jao
            updateIndex(2 * node + 1, start, mid, index, value);

            // Right Child me jao
            updateIndex(2 * node + 2, mid + 1, end, index, value);

        }
};

int main(){

    vector<int> arr = {3,6,4,25,5,13,18};

    SegmentTree *tree = new SegmentTree(arr);

    tree -> update(2, 10);

    cout << tree -> query(1, 5) << endl;

}