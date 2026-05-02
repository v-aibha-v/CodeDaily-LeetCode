/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution {
public:
    //time -> n log n
    //space -> n
    bool valid(int n){
        bool changed=false;
        while(n>0){
            int digit=n%10;
            n/=10;
            if(digit==2 or digit==5 or digit==6 or digit==9) changed=true;
            else if(digit==3 or digit==4 or digit==7) return false;
        }
        return changed;
    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(valid(i)) {
                cout<<i<<" ";
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

