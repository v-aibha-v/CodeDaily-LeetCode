/*
 * @lc app=leetcode id=1320 lang=cpp
 *
 * [1320] Minimum Distance to Type a Word Using Two Fingers
 */

// @lc code=start
class Solution {
public:
    // int dis(){

    // }
    // unordered_map<char, pair<int, int>> mp;
    // int mini = INT_MAX;
    // void rec(char fig1, char fig2, string& word, int idx, int n, int cost) {
    //     if (idx >= n) {
    //         mini = min(mini, cost);
    //         return;
    //     }
    //     if (fig2 == '0') {
    //         rec(fig1, word[idx], word, idx + 1, n, cost); // move fig 2
    //         int y2 = mp[word[idx]].second, x2 = mp[word[idx]].first;
    //         int y1 = mp[fig1].second, x1 = mp[fig1].first;
    //         int dis = abs(y2 - y1) + abs(x2 - x1);
    //         rec(word[idx], fig2, word, idx + 1, n, cost + dis);
    //     } else {
    //         int y = mp[word[idx]].second, x = mp[word[idx]].first;
    //         int y1 = mp[fig1].second, x1 = mp[fig1].first;
    //         int y2 = mp[fig2].second, x2 = mp[fig2].first;
    //         int d1 = abs(y - y1) + abs(x - x1), d2 = abs(y2 - y) + abs(x2 -
    //         x); rec(word[idx], fig2, word, idx + 1, n, cost + d1); rec(fig1,
    //         word[idx], word, idx + 1, n, cost + d2);
    //     }
    //     return;
    // }
    int dist(int a, int b) {
        if (a == 26)
            return 0; // unused finger

        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }
    vector<vector<vector<int>>> dp;
    int mini = INT_MAX;
    int memo(int fig1, int fig2, string& word, int idx, int n) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx][fig1][fig2] != -1)
            return dp[idx][fig1][fig2];
        else {
            int curr = word[idx] - 'A';
            int cost1 = dist( fig1,curr) + memo(curr, fig2, word, idx + 1, n);
            int cost2 = dist( fig2,curr) + memo(fig1, curr, word, idx + 1, n);
            return dp[idx][fig1][fig2] = min(cost1, cost2);
        }
    }
    int minimumDistance(string word) {
        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 6; j++) {
        //         // mp.('A'+ 6*i +j ,{i,j});
        //         mp['A' + 6 * i + j] = {i, j};
        //     }
        // }
        // mp['Y'] = {4, 0};
        // mp['Z'] = {4, 1};
        // rec(word[0], '0', word, 0, word.size(), 0);
        // return mini;
        int n = word.size();
        dp.assign(n, vector<vector<int>>(27, vector<int>(27, -1)));

        return memo(26,26,word,0,n); // both fingers unused
    }
};
// @lc code=end

