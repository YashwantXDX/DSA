#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

    
*/

int maxProfit(vector<int>& prices) {
    
    // Initialize total profit to 0
    int profit = 0, size = prices.size();

    // Loop through the prices starting from the second day
    for(int i = 1; i < size; i++)
        // If today's price is higher than yesterday's, we can profit by buying yesterday and selling today
        if(prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1]; // Add the difference to the total profit

    // Return the accumulated profit from all such transactions
    return profit;
}

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit(prices);

}