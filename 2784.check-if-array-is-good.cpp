/*
 * @lc app=leetcode id=2784 lang=cpp
 *
 * [2784] Check if Array is Good
 */

// @lc code=start
class Solution {
public:
    bool isGood(vector<int>& nums) {
        // unordered_set<int>st;
        // int ans=0,n=nums.size(),sum=0;
        // for(int ele: nums){ sum+=ele;st.insert(ele);}
        // if((n*(n-1)/2) != (sum-n+1))  {cout<<"a";return false;}
        // if(st.size()!=n-1) {cout<<"b";return false;}
        // return true;
        int n=nums.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>=n) return false;
            if(nums[i]!=n-1 and visited[nums[i]]==1) return false;
            if(nums[i]==n-1 and visited[nums[i]]>=2) return false;

            visited[nums[i]]++;
        }
        return true;
    }
};
// @lc code=end

