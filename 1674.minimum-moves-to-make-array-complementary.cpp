/*
 * @lc app=leetcode id=1674 lang=cpp
 *
 * [1674] Minimum Moves to Make Array Complementary
 */

// @lc code=start
class Solution {
public:
    // int help(vector<int>&nums,int limit,int target){
    //     int n=nums.size();
    //     int nn=nums.size()/2,t=0;
    //     for(int i=0;i<nn;i++){
    //         int sum=nums[i]+nums[n-1-i];
    //         if(target==sum) t+=0;
    //         else if ((target-nums[i]<=limit and target-nums[i]>=1) or
    //          (target-nums[n-1-i]<=limit and target-nums[n-1-i]>=1) ) t+=1;
    //         else t+=2;
            
    //     }
    //     return t;
    // }
    int minMoves(vector<int>& nums, int limit) {
        // int n=nums.size();
        // int mini=n;
        // for(int i=2;i<=2*limit;i++){
        //     // mini=min(mini,help(nums,limit,i));
        //     int a=help(nums,limit,i);
        //     if(a<mini){
        //         cout<<i<<" ";
        //         mini=a;
        //     }
        // }
        // return mini;
        int n=nums.size();
        vector<int> diff(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int low=min(nums[i],nums[n-1-i]);
            int high=max(nums[i],nums[n-1-i]);
            int sum=nums[i]+nums[n-1-i];
            //range limit is low +1 to high+limit
            diff[low+1]-=1;//start here
            diff[high+limit+1]+=1;//stop here
            diff[sum]-=1;
            diff[sum+1]+=1;
        }
        int curr=n,ans=INT_MAX;
        for(int i=2;i<=2*limit;i++){
            curr+=diff[i];
            ans=min(ans,curr);
        }
        return ans;
    }
};
// @lc code=end

