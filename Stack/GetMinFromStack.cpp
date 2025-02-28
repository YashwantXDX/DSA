#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

    Problem Logic :- 

    1. Make Two stack, one normal and one for min as the constraints are 10^5

    2. Push :- Simply push the element in the normal stack.
                To push in the min stack, compare the element with the current top of min. If it is smaller than it can be pushed.
    
    3. Pop :- Before popping the element from normal stack, compare the min stack and normal stack top, if they arre equal then pop both, else just pop normal stack

    4. Peek :- Return normal stack top is it is not empty else return -1.

    5. get min :- return min stack top if not empty, else return -1

*/

class Stack{

 private:
    stack<int> st, minSt;

 public:
    
    // Empty the stack if any
    Stack(){
        while(!st.empty()) st.pop();
        while(!minSt.empty()) minSt.pop();
    }

    void push(int data){

        st.push(data);

        // Check is min stack is empty or data is less the min stack ka top
        if(minSt.empty() || data < minSt.top())
            minSt.push(data);
            
    }

    void pop(){
        
        if(st.empty()) return;

        // Comapre both tops, if found same the pop both
        if(st.top() == minSt.top())
            minSt.pop();
        
        st.pop();

    }

    int peek(){
        return st.empty() ? -1 : st.top();
    }

    int getMin(){
        return minSt.empty() ? -1 : minSt.top();
    }

};