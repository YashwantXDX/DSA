#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

    
*/

int maxProfit(vector<int>& prices) {
    
    // Initialize the maximum profit to 0
    // 'size' stores the total number of days (elements in the prices array)
    // 'stock' holds the minimum price seen so far (starting with the first day's price)
    int profit = 0, size = prices.size(), stock = prices[0];

    // Loop through each day starting from the second day
    for(int i = 1; i < size; i++) {

        // Calculate the profit if we sold on the current day (buying at the lowest price so far)
        // Update 'profit' only if this new profit is higher than the previous maximum
        profit = max(profit, prices[i] - stock);

        // Update 'stock' to hold the lowest price seen so far (minimum buying price)
        stock = min(stock, prices[i]);
    }

    // Return the maximum profit that can be achieved
    return profit;
}


int main(){

    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit(prices);

}