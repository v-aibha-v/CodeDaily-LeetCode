/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
public:

    bool dfs(vector<int>& arr, int start, vector<int>& visited){
        int n = arr.size();
        if(start < 0 || start >= n || visited[start] == -1)
            return false;
        if(arr[start] == 0)
            return true;
        visited[start] = -1;
        int left = start - arr[start];
        int right = start + arr[start];
        return dfs(arr, left, visited) || dfs(arr, right, visited);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited(n, 0);
        return dfs(arr, start, visited);
    }
};
// @lc code=end

