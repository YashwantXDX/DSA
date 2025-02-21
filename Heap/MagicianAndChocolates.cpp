#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.interviewbit.com/problems/magician-and-chocolates/

    Refer Video :- https://www.youtube.com/watch?v=pCsWDX2K06o&t=2555s

    Problem Logic :- 

    Use Max Heap for this Problem,

    When ever the child takes max chocolate, the magician will put half of the chocolate in the bag

    for ex. If child too 10 chocolate from the bag, the magician will put 5 chocolates in the bag from its own not from thi child.

    Do this till child timer goes down to 0

    Note :- Question said that we have to return our answer in mod 10^9 + 7

*/

int nchoc(int A, vector<int> &B){

    priority_queue<int> p;
    int ans = 0;

    for(int i = 0; i < B.size(); i++)
        p.push(B[i]);
    
    while(A--){
        int temp = p.top();
        p.pop();
        
        ans += temp;
        p.push(temp / 2);
       
    }

    return ans % 1000000007;

}

int main(){

    vector<int> arr = {2,4,6,8,10};
    int num = 5;

    cout << "Answer : " << nchoc(num, arr);

}