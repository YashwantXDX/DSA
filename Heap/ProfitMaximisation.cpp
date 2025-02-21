#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.interviewbit.com/problems/profit-maximisation/

    Refer Video :- https://www.youtube.com/watch?v=pCsWDX2K06o&t=4225

    Problem Logic :- 

    Use Max Heap for this Problem,

    top element ko lo, sum me add kro, orr push kro do use 1 se decrement kar ke, ye tb tk kro jb tk B = 0 nhi ho jata.

    Note :- Heaps ko tb use krna hai jb deletion and insertion dono ho,
            vrna hum array se bhi kr skte hai agar sirf deletion ho

*/

int solve(vector<int> &A, int B) {

    // Max Heap
    priority_queue<int> p;

    // Elements Daalo
    for(int i : A) p.push(i);

    // Ab Seats Becho Customers ko orr profit kmao

    int profit = 0;

    while(B-- && !p.empty()){
        
        int temp = p.top(); p.pop();

        profit += temp;

        // If seats = 0 then it doesn't make sense to push it
        if(temp - 1)
            p.push(temp - 1);

    }

    return profit;

}

int main(){

    vector<int> seats = {6,4,2,3};
    int customers = 5;
    
    cout << "Answer : " << solve(seats, customers);

}