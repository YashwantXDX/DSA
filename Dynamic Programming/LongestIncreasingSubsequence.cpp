#include<bits/stdc++.h>
using namespace std;

/*
    
    Problem Link :- https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

    Algorithm :- 

    1. Initialize:

        Let LIS[] be an auxiliary array of size n.

        Set LIS[0] = arr[0]

        Set size = 0 (represents the last index of the valid part of LIS)

    2. Iterate through the input array from i = 1 to n - 1:

        Set start = 0, end = size, and index = size + 1

    3. Binary Search in LIS[0...size] to find the correct position (index) where arr[i] can be placed:

        While start <= end:

            Compute mid = start + (end - start) / 2

            If LIS[mid] < arr[i], search right → start = mid + 1

            Else:

                Set index = mid

                Search left → end = mid - 1

    4. Update LIS:

        Set LIS[index] = arr[i]
        (This either extends the LIS or replaces a value to maintain a better subsequence tail)

    5. Update size:

        If index > size, set size = index

    6. After the loop ends, the length of LIS is size + 1

*/

// Function to find the length of the Longest Increasing Subsequence (LIS) using binary search
int lis(vector<int>& arr) {
    
    // Get the number of elements in the input array
    int n = arr.size();
    
    // Create a vector to store the smallest possible tail for increasing subsequences of all lengths
    vector<int> LIS(n);
    
    // Initialize the size of LIS to 0 (we'll build on this)
    int size = 0, start, end, index, mid;
    
    // Initialize the first element of LIS with the first element of the array
    LIS[0] = arr[0];
    
    // Loop through the rest of the elements
    for(int i = 1; i < n; i++) {
        
        // Set binary search bounds
        start = 0;
        end = size;
        
        // Initialize index where arr[i] might be inserted or replace an element
        index = size + 1;
        
        // Perform binary search on LIS array
        while(start <= end) {
            
            // Calculate the middle index
            mid = start + (end - start) / 2;
            
            // If current LIS element is less than arr[i], search in the right half
            if(LIS[mid] < arr[i])
                start = mid + 1;
            
            // If equal, we found the position directly
            else if(LIS[mid] == arr[i]) {
                index = mid;
                break;
            }
            
            // If LIS[mid] > arr[i], search in the left half
            else {
                index = mid;
                end = mid - 1;
            }
        }
        
        // Place arr[i] at the correct position to maintain increasing subsequence tails
        LIS[index] = arr[i];
        
        // Update the size if needed (we've extended LIS)
        size = max(size, index);
    }
    
    // Return the length of the longest increasing subsequence
    return size + 1;
}


int main(){

    vector<int> arr = {5,8,3,7,9,1};

    cout << lis(arr);

}