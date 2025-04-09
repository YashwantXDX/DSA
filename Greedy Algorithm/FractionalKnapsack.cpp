#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=8365s


*/

// Comparator to sort items by decreasing value-to-weight ratio
bool comp(pair<int, int> a, pair<int, int> b) {
    /*
        We want to compare:
        a.first / a.second vs b.first / b.second

        To avoid division (which can cause precision errors),
        we multiply crosswise:

        a.first * b.second > b.first * a.second
        => a has a higher value-to-weight ratio than b

        like basic maths
    */
    return (a.first * b.second) > (b.first * a.second);
}

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    
    int n = val.size();

    // Combine values and weights into one list of items
    vector<pair<int, int>> items;
    for(int i = 0; i < n; i++)
        items.push_back({val[i], wt[i]});

    // Sort items by highest value-to-weight ratio
    sort(items.begin(), items.end(), comp);

    double profit = 0; // Total profit gained
    int i = 0;         // Index for items

    // Loop while we have capacity and more items
    while(capacity && i < n) {

        // If the whole item can be added
        if(capacity >= items[i].second) {
            profit += items[i].first;         // Add full value
            capacity -= items[i].second;      // Reduce knapsack capacity
        } 
        else {
            // Add fractional part of the item
            // Value per unit weight = value / weight
            // This is done for value preserving
            double temp = items[i].first;
            temp /= items[i].second;

            // Add proportional value based on remaining capacity
            profit += temp * capacity;

            // Knapsack is full now
            capacity = 0;
        }

        i++;
    }

    // Return the maximum profit possible
    return profit;
}



int main(){
    
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int cap = 50;


    double ans = fractionalKnapsack(val, wt, cap);

    cout << ans;

}