/*
 * @lc app=leetcode id=3783 lang=cpp
 *
 * [3783] Mirror Distance of an Integer
 */

// @lc code=start
class Solution {
public: 
    int rev(int n){
        int ans=0;
        while(n>0){
            int t=n%10;
            ans =ans*10 +t;
            n/=10;

        }
        return ans;
    }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};
// @lc code=end

