#include<bits/stdc++.h>
using namespace std;

/*

    Problem Link :- https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

    Refer Video - Coder Army - Lecture 98 - 55:17

*/

string firstNoRepeatCharInString(string &str){

    vector<int> charCount(26,0);
    string ans = "";
    queue<char> q;

    for(int i = 0; i < str.length(); i++){

        if(charCount[str[i] - 'a'] >= 1){

            charCount[str[i] - 'a']++;

            while(!q.empty() && charCount[q.front() - 'a'] > 1)
                q.pop();

            if(q.empty())
                ans.push_back('#');

            else
                ans.push_back(q.front());
        }

        else{

            charCount[str[i] - 'a']++;
            q.push(str[i]);

            while(!q.empty() && charCount[q.front() - 'a'] > 1)
                q.pop();

            ans.push_back(q.front());
        }

    }

    return ans;

}

int main(){

    string str = "abcacdbd";

    cout << firstNoRepeatCharInString(str);

}