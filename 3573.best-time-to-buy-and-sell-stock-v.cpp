/*
 * @lc app=leetcode id=3573 lang=cpp
 *
 * [3573] Best Time to Buy and Sell Stock V
 */

// @lc code=start
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        long long n = prices.size();
        // int NEG = INT_MIN;
         long long NEG = LLONG_MIN/2;
        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(k + 1, vector<long long>(3, NEG)));
        for(int i=0;i<=k;i++) dp[n][i][0]=0;// i>=n return 0
        for(int i=0;i<=n;i++) dp[i][0][0]=0;// k<=0 return 0
        for (long long i = n - 1; i >= 0; i--) {    
            for (long long j = k; j >= 1; j--) {
                for (long long kk = 0; kk < 3; kk++) {
                    if (kk == 0) {
                        long long a = dp[i + 1][j][1] - prices[i];
                        long long b = dp[i + 1][j][2] + prices[i];
                        long long c = dp[i + 1][j][0];
                        dp[i][j][kk] = max({a, b, c});
                    } else if (kk == 1) {
                        long long a = dp[i + 1][j][kk];
                        long long b = dp[i + 1][j - 1][0] + prices[i];
                        dp[i][j][kk] = max(a, b);
                    } else {
                        long long a = dp[i + 1][j][kk];
                        long long b = dp[i + 1][j - 1][0] - prices[i];
                        dp[i][j][kk] = max(a, b);
                    }
                }
            }
        }
        //  for(long long  i=n-1;i>=0;i--){
        //     for(long long  j=k;j>=1;j--){
        //         for(long long  kk=0;kk<3;kk++){
        //             cout<<dp[i][j][kk]<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl<<endl;
        // }
        return dp[0][k][0];
    }
};
// @lc code=end

