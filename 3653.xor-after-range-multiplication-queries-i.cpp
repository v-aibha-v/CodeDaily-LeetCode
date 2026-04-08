/*
 * @lc app=leetcode id=3653 lang=cpp
 *
 * [3653] XOR After Range Multiplication Queries I
 */

// @lc code=start
class Solution {
public:
    const int mod= 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         int n=nums.size();
        int ans=0;
        vector<long long >temp(n);
         
        for(int i=0;i<n;i++) temp[i]=(long long ) nums[i];
      
        for(long long  i=0;i<queries.size();i++){
            long long  start=queries[i][0],end=queries[i][1];
            for(long long  j=start;j<=end;j+=queries[i][2]){
                temp[j] =( temp[j]* queries[i][3] ) % mod;
            }
        }
        for(long long  ele:temp) ans^=ele;
        return (int) ans;
    }
};
// @lc code=end

