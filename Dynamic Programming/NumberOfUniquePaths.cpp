#include<bits/stdc++.h>
using namespace std;

/*

    Note :- IMPORTANT QUESTION
    
    Problem Link :- https://www.geeksforgeeks.org/problems/number-of-unique-paths5339/1

    Dynamic Programming is Nothing other than "MEMORIZATION"

    1D , 2D, 3D ya 4D DP lab lgana hai Trick

    Bas check kr lo ki function pass kren ke baad kon kon si values change ho rhi hai

    2 ho rhe to 2D dp

    3 ho rhe to 3D dp and so on

    NOTE :- Just Remember One Thing, If you are able to create Recursion Logic, Then just comvert it into the Top Down Approach by analyzing the code, after that do the same with Top Down Approach and convert it into Bottom Up Approach

    Now, For Further Optimization, Convert the Bottom Up Approach to Space Optimized Approach (Have to build some logic)

*/



int main(){

    vector<int> arr = {1,7,10,13,14,19};

    cout << lengthOfLongestAP(arr);

}