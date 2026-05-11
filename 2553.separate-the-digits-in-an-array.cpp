/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 */

// @lc code=start
class Solution {
public:
    // vector<int> help(int ele){
    //     vector<int> vec;
    //     while(ele>0){
    //         int a=ele%10;
    //         ele/=10;
    //         vec.push_back(a);
    //     }
    //     reverse(vec.begin(),vec.end());
    //     return vec;
    // }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ele=nums[i];
            // cout<<ele<<" ";
            vector<int> vec;
        while(ele>0){
            int a=ele%10;
            ele/=10;
            vec.push_back(a);
        }
        reverse(vec.begin(),vec.end());
            // ans.insert(ans.end(), reverse(vec.begin(),vec.end()));
            ans.insert(ans.end(), vec.begin(),vec.end());

        }
        return ans;
    }
};

// @lc code=end

