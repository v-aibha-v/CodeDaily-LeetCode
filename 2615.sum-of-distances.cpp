/*
 * @lc app=leetcode id=2615 lang=cpp
 *
 * [2615] Sum of Distances
 */

// @lc code=start
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
         unordered_map<long long,pair<long long,long long>> mp;
        long long n=nums.size();
         vector<long long > ans(n,0);
        //ele as key , {sum,count occ}
        for(long long i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                auto x=mp[nums[i]];
                x.first+=i;
                x.second+=1;
                mp[nums[i]]=x;
                ans[i]= abs(x.first - (x.second*i));
            }
            else{
                mp[nums[i]]={i,1};
            }
        }
        unordered_map<long long,pair<long long,long long>> np;
        //ele as key , {sum,count occ}
        for(long long i=n-1;i>=0;i--){
            if(np.find(nums[i])!=np.end()){
                auto x=np[nums[i]];
                x.first+=i;
                x.second+=1;
                np[nums[i]]=x;
                ans[i]+= abs(x.first - (x.second*i));
            }
            else{
                np[nums[i]]={i,1};
            }
        }
        return ans;
    }
};
// @lc code=end

