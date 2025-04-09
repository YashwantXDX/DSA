#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/assign-mice-holes3053/0

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=1699s

*/

int assignMiceHoles(int N , int M[] , int H[]) {

    // Sort the positions of mice
    sort(M, M + N);

    // Sort the positions of holes
    sort(H, H + N);

    // This variable will keep track of the maximum time any mouse takes to reach a hole
    int time = 0;

    // Assign each mouse to a hole in order (after sorting, this minimizes the max distance)
    for(int i = 0; i < N; i++) {

        // Calculate how much time (distance) it takes for current mouse to reach the assigned hole
        // We take absolute value because positions can be negative or positive
        time = max(abs(M[i] - H[i]), time);  // Update the maximum time if current one is larger
    }

    // Return the time it takes for the slowest (farthest) mouse to get into a hole
    return time;
}



int main(){
    
    int n = 2;
    int M[] = {4, 2};
    int H[] = {1, 7};

    int ans = assignMiceHoles(n, M, H);

    cout << ans;

}