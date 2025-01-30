#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/time-needed-to-buy-tickets/

    Problem Video - Coder Army - LEcture 97 - 44 : 20

*/

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

int main(){

    vector<int> tickets = {2,3,2};
    int k = 2;

    cout << timeRequiredToBuy(tickets, k) << endl;

}