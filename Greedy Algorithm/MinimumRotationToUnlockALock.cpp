#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/minimum-rotations-to-unlock-a-circular-lock1001/1

    Refer Video :- https://www.youtube.com/watch?v=-wqKvpYGg1I&t=2312s

*/

int rotationCount(long long R, long long D)
{
    // Variable to store the total number of rotations needed
    int ans = 0;

    // Variables to hold the current digit of R and D
    int first, second;

    // Loop through all digits of R and D from right to left
    while(R) {

        // Get the last digit of R
        first = R % 10;

        // Get the last digit of D
        second = D % 10;

        /*
         * Calculate the minimum number of rotations needed to convert
         * the digit from R to the digit from D on a circular dial (0–9).
         * We use:
         * - abs(first - second): direct distance
         * - 10 - abs(second - first): wrapping around the dial
         */
        ans += min(abs(first - second), 10 - abs(second - first));

        // Remove the last digit from both R and D
        R /= 10;
        D /= 10;
    }

    // Return the total rotations needed for all digits
    return ans;
}



int main(){
    
    long long r = 2345;
    long long d = 5432;

    int ans = rotationCount(r, d);

    cout << ans;

}