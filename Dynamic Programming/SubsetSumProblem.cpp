#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

    Algorithm :

    1. Input:

        An array arr of size n

        A target sum

    2. Create a 2D DP Table:

        Let dp be a 2D table of size (n + 1) x (sum + 1)

        dp[i][j] means: is it possible to form sum j using elements from index i to n-1?

    3. Initialize the Table:

        For all i: dp[i][0] = true → because a sum of 0 is always possible (by picking no elements)

        For all j > 0: dp[n][j] = false → because with no elements left, we can't form a positive sum

    4. Fill the DP Table (Bottom-Up):

        Loop i from n - 1 down to 0:

            Loop j from 0 to sum:

                If arr[i] > j, we cannot include the current element:

                    dp[i][j] = dp[i + 1][j]

            Else:

                We can either include or exclude the current element:

                dp[i][j] = dp[i + 1][j] OR dp[i + 1][j - arr[i]]

    5. Return Result:

        Return dp[0][sum] which gives the final answer
    
*/

bool isSubsetSum(vector<int>& arr, int sum) {
    
    // Get the number of elements in the array
    int n = arr.size();
    
    // Create a 2D DP table of size (n+1) x (sum+1), initialized with 0
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
    
    // Initialize the last row: when no elements are left, we can't form any positive sum
    for(int i = 0; i <= sum; i++)
        dp[n][i] = 0;

    // Initialize the first column: sum 0 is always possible with any number of elements (by picking none)
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Fill the DP table in bottom-up manner
    for(int i = n - 1; i >= 0; i--) { // Loop through elements from last to first
        for(int j = 0; j <= sum; j++) { // Loop through all possible target sums from 0 to given sum

            if(j < arr[i])
                // If current element is greater than target sum, we can't include it
                dp[i][j] = dp[i + 1][j];
            else
                // Otherwise, we check two possibilities:
                // 1. Include current element and see if remaining sum can be formed
                // 2. Exclude current element
                dp[i][j] = dp[i + 1][j - arr[i]] || dp[i + 1][j];
        }
    }

    // The result is whether we can form the target sum starting from index 0
    return dp[0][sum];
}


int main(){

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << isSubsetSum(arr, sum);

}