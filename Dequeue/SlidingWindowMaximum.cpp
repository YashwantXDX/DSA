#include <bits/stdc++.h>
using namespace std;

/*

    We are using Deque here for flexible insertion and deletion

    Problem Link :- https://leetcode.com/problems/sliding-window-maximum/

    Refer Video :- Coder Army - https://www.youtube.com/watch?v=loLfzoeeyEQ

    - Time Stamp - 9 : 07

*/

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

    deque<int> q;
    vector<int> ans;

    for (int i = 0; i < k - 1; i++)
    {
        if (q.empty())
            q.push_back(i);
        else
        {
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);
        }
    }

    for (int i = k - 1; i < nums.size(); i++)
    {

        while (!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();
        
        q.push_back(i);

        if(q.front() <= i - k)
            q.pop_front();

        ans.push_back(nums[q.front()]);
    }

    return ans;
}

int main()
{

    vector<int> arr = {4, 3, 7, 5, 2, 3, 1, 2, 8, 7};
    int k = 4;

    vector<int> ans = maxSlidingWindow(arr, k);

    for (int i : ans)
        cout << i << " ";
}