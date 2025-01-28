#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

    Logic :- How we know that if some one is celebrity or not?

    When all of the persons know him but he dont know any of them, then he is the celebrity

    Just put all the elements in the stack, and pop by two till the stack is empty,

    the time will come when only one element will be left in stack, and now, we have to check if 
    
    mat[i][that_element] == 1 && mat[that_element][i] == 0

    Now from that we are sure that this is the element which is celebrity

    Understand by the code

    Time Complexity - O(n)
    Space Complexity - O(n)

*/


int celebrity(vector<vector<int> >& mat) {

    stack<int> st;

    int first, second;

    // Step - 1 - Push All the indexes into the stack
    for(int i = mat.size() - 1; i >= 0; i--)
        st.push(i);
    
    // Step - 2 - Iterate till stack is empty
    while(!st.empty()){

        first = st.top();
        st.pop();

        // To check if the first one is the last element
        if(st.empty())
            break;
        
        second = st.top();
        st.pop();

        // Check for celebrity - If first dont know second and second know first then push the first
        if(mat[first][second] == 0 && mat[second][first] == 1)
            st.push(first);
        
        // Check for celebrity - If first know second and second dont know first then push the second
        else if(mat[first][second] == 1 && mat[second][first] == 0)
            st.push(second);

    }

    // Step - 3
    int index = first;


    // Last Check if all of them know the first elemet and first element dont know all of them
    for(int i = 0; i < mat.size(); i++){
        
        // First will always be 0 so skip it
        if(i == index)
            continue;

        if(mat[i][index] == 1 && mat[index][i] == 0)
            continue;
        
        else
            return -1;

    }

    return index;
}

int main(){

    vector<vector<int>> arr = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };
    
    cout << "Celebrity is : " << celebrity(arr);

}