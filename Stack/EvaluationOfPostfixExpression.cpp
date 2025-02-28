#include<bits/stdc++.h>
using namespace std;

int evaluate(vector<string> &arr){

    stack<int>st;

    // Loop through all the string in array
    for(string i : arr){

        // Check for operators and do the same for all the operators
        if(i == "+"){

            // Pop out the top and put it in second and fisrt
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();

            // push the operations into stack
            st.push(first + second);
        }

        else if(i == "-"){
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            st.push(first - second);
        }

        else if(i == "*"){
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            st.push(first * second);
        }

        else if(i == "/"){
            int second = st.top(); st.pop();
            int first = st.top(); st.pop();
            st.push(first / second);
        }

        // If it is an integer string then convert it into integer and push it into the stack
        // stoi is a string function which converts string into integer
        else 
            st.push(stoi(i));

    }

    // Return the element in top of the stack
    return st.top();

}

int main(){

    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    
    cout << evaluate(arr);

}