#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I

*/

vector<int> minPartition(int N)
{
    // List of available currency denominations in descending order
    vector<int> curr = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    // This vector will store the result: the minimum number of notes used
    vector<int> ans;

    int notes = 0, i = 0;

    // Loop until the entire amount is broken down into notes
    while(N) {

        // Calculate how many notes of the current denomination can be used
        notes = N / curr[i];

        // Add that many notes to the answer
        while(notes--)
            ans.push_back(curr[i]);

        // Reduce the amount by removing the value we've accounted for
        N %= curr[i];

        // Move to the next smaller denomination
        i++;
    }

    // Return the final list of notes used
    return ans;
}


int main(){
    
    int num = 143;
    vector<int> ans = minPartition(num);

    for(int i : ans)
        cout << i << " ";

}