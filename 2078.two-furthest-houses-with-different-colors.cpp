/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution {
public:
    int maxDistance(vector<int>& color) {
        int n=color.size(),ans=0;
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(end>i and color[end]==color[i]) end--;
            if(end>i) ans=max(ans,end-i);
            while(start<i and color[start]==color[i] )start++;
            if(start<i) ans=max(ans,i-start);
        }
        return ans;
    }
};
// @lc code=end

