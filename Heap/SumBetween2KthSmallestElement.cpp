#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1

    Refer Video :- https://www.youtube.com/watch?v=Lk-QYXyPL3g&t=2132&t=3163

    Problem Logic :- 

    1. Make a Max Heap
    2. Find K1 smallest element and store it in a variable
    3. Similarly find K2 smallest elemnt
    4. no loop through the array and write the find condition i.e. first < element && element < second
    5. sum that elements which fulfil the condition and return it.
*/

long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
{   
    priority_queue<long long> p;
    long long first, second, sum = 0;
    
    for(long long i = 0; i < K1; i++)
        p.push(A[i]);
    
    for(long long i = K1; i < N; i++){
        if(A[i] < p.top()){
            p.pop();
            p.push(A[i]);
        }
    }
    
    first = p.top();
    while(!p.empty())
        p.pop();
    
    for(long long i = 0; i < K2; i++)
        p.push(A[i]);
    
    for(long long i = K2; i < N; i++){
        if(A[i] < p.top()){
            p.pop();
            p.push(A[i]);
        }
    }
    
    second = p.top();
    
    for(long long i = 0; i < N; i++)
        if(first < A[i] && A[i] < second){
            sum += A[i];
            cout << A[i] << " ";
        }
    
    cout << "\nFirst : " << first << endl;
    cout << "Second : " << second << endl;
    return sum;
}

int main(){

    long long arr[] = {20, 8, 22, 4, 12, 10, 14};
    long long size = 7;
    long long k1 = 3, k2 = 6;
    
    cout << "K th Smallest Element :- " << sumBetweenTwoKth(arr, size, k1, k2);

}