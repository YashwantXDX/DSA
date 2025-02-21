#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

    Refer Video :- https://www.youtube.com/watch?v=pCsWDX2K06o&t=4205

    thoda sa piche kar lena taki approach pta chale.

    Problem Logic :- 

    Use Max Heap for this Problem,

    Take the top , square root it, and push it as int in the max heap back, do this till k = 0,

    after that, sum all the elements of the max heap and return it.

*/

long long pickGifts(vector<int>& gifts, int k) {
    
    // Max Heap
    priority_queue<int> p;

    // Elements in Max Heap
    for(int i : gifts)
        p.push(i);
    
    // take gifts in the given time
    while(k--){

        int temp = p.top(); p.pop();

        p.push((int)sqrt(temp));

    }

    // Now sum all the gifts (elements)
    long long ans = 0;

    while(!p.empty()){
        ans += p.top(); p.pop();
    }

    return ans;
}

int main(){

    vector<int> arr = {1,1,1,1};
    int timer = 4;
    
    cout << "Answer : " << pickGifts(arr, timer);

}