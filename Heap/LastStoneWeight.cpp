#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/last-stone-weight/description/

    Refer Video :- https://www.youtube.com/watch?v=pCsWDX2K06o&t=3625

    Problem Logic :- 

    Use Max Heap for this Problem,

    Just take the top 2 stones and smash them, and if one stone is heavier than just subtract the hieviest stone with the second stone weight and push it into the heap.

    If heap goes empty just return 0, else continue till only one size left io the heap and return it.

*/

int lastStoneWeight(vector<int>& stones) {
    
    // Max Heap bnao 
    priority_queue<int> p;

    // Max heap pe values daalo
    for(int i = 0; i < stones.size(); i++)
        p.push(stones[i]);

    // Loop Till size goes to 1
    while(p.size() != 1){

        // get x and y
        int y = p.top(); p.pop();
        int x = p.top(); p.pop();
        
        // If weight exist then push the remaining weight
        if(y - x > 0)
            p.push(y - x);
        
        // Check if all the stone are destroyed
        if(p.empty())
            return 0;
        
    }
    
    return p.top();
}

int main(){

    vector<int> arr = {3,5,7,8,69};
    
    cout << "Answer : " << lastStoneWeight(arr);

}