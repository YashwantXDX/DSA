#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=1174s

*/

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N); // Sort the candies by price (ascending)
    
    int start = 0, end = N - 1;
    
    int small = 0, large = 0;
    
    // Minimum money: buy cheapest candies, get K costliest free
    while(start <= end){
        small += candies[start]; // buy the cheapest available candy
        start++;
        end -= K; // get K costliest candies free
    }
    
    start = 0, end = N - 1;

    // Maximum money: buy costliest candies, get K cheapest free
    while(start <= end){
        large += candies[end]; // buy the most expensive available candy
        start += K; // get K cheapest candies free
        end--;
    }
    
    return {small, large};
}



int main(){
    
    int n = 5, k = 4;
    int candies[] = {3, 2, 1, 4, 5};

    vector<int> ans = candyStore(candies, n, k);

    for(int i : ans)
        cout << i << " ";

}