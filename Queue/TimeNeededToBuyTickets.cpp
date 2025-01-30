#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/time-needed-to-buy-tickets/

    Problem Video - Coder Army - LEcture 97 - 44 : 20

*/

// Can Go O(n^2), queue is implimented
int timeRequiredToBuy(vector<int>& tickets, int k) {
        
    queue<int> q;

    for(int i = 0; i < tickets.size(); i++)
        q.push(i);
    
    int element = tickets[k];
    int time = 0;

    while(true){

        if(q.front() == k){

            tickets[q.front()]--;
            time++;

            if(tickets[q.front()] == 0)
                break;
            
            else{
                q.push(q.front());
                q.pop();
            }

        }

        else{

            tickets[q.front()]--;
            time++;

            if(tickets[q.front()] == 0){
                q.pop();
            }
            
            else{
                q.push(q.front());
                q.pop();
            }

        }

    }

    return time;

}

// Can Only go O(n), Without Queue
// Refer Video Coder Army - Lecture 97 - 47:27
int timeRequiredToBuy2(vector<int>& tickets, int k){

    int time = 0;

    for(int i = 0; i <= k; i++){
        time += min(tickets[k], tickets[i]);
    }

    for(int i = k + 1; i < tickets.size(); i++){
        time += min(tickets[k] - 1, tickets[i]);
    }

    return time;

}


int main(){

    vector<int> tickets = {5,1,1,1};
    int k = 0;

    cout << timeRequiredToBuy2(tickets, k) << endl;

}