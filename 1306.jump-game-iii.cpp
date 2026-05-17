/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> visited(n, 0);
        queue<int> qu;
        qu.push(start);
        while (not qu.empty())
        {
            int a = qu.front();
            cout << a << " ";
            qu.pop();
            if (visited[a] == -1)
                continue;
            visited[a] = -1;
            if (arr[a] == 0)
                return true;
            int right = a + arr[a], left = a - arr[a];
            if (left >= 0 and left < n and visited[left] != -1)
                qu.push(left);
            if (right >= 0 and right < n and visited[right] != -1)
                qu.push(right);
        }
        return false;
    }
};
// @lc code=end
