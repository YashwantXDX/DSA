#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://leetcode.com/problems/minimum-window-substring/description/

    Refer Video :- https://www.youtube.com/watch?v=lni2JkC9_1Y&t=1506s

*/

string minWindow(string str, string target) {
    
    // Variables declared for future
    int start = 0, end = 0, total = target.length();
    int ans = INT_MAX, index = -1;

    // make array to store characters count
    vector<int> chars(256, 0);

    // Store the count to target characters
    for(int i = 0; i < total; i++)
        chars[target[i]]++;
    
    // Go till end less than str ka length
    while(end < str.length()){

        // Decrease the character count of the current charcter in the character array
        chars[str[end]]--;

        // Check if the character count of the current character is greater or equal to 0
        // If it is than decrease the total
        if(chars[str[end]] >= 0)
            total--;
        
        // If we found that total is zero and start is less than end
        while(!total && start <= end){

            // Check the length of the subarray with the length of answer
            // if subarray length is less than ans than update the ans with that subarray length and index with start
            if(ans > end - start + 1){

                ans = end - start + 1;
                index = start;

            }

            // Increase the count of character as window size decreases
            chars[str[start]]++;

            // Check is the character count goes greater than 0
            // If it is than increase the total
            // we know that total will increase if the target character is bigger than 0
            if(chars[str[start]] > 0)
                total++;
            
            // Decrease the window size
            start++;

        }

        // Character not found, increase the window size
        end++;

    }

    // if the index is still -1 then we know that the target is not present in the str
    if(index == -1) return "";

    // for the answer
    string answer = "";

    // now store all the characters in the answer string from index to index + ans
    for(int i = index; i < index + ans; i++)
        answer += str[i];
    
    return answer;

}

int main(){

    string str = "ADOBECODEBANC";
    string target = "ABC";

    cout << minWindow(str, target);

    

}