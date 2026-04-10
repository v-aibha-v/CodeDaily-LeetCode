/*
 * @lc app=leetcode id=3740 lang=cpp
 *
 * [3740] Minimum Distance Between Three Equal Elements I
 */

// @lc code=start
class Solution {
public:
    int mini=INT_MAX;
    // int helper(vector<int> &a){
    //     //logic for this abs(i - j) + abs(j - k) + abs(k - i),
    //     int n=a.size(),m=INT_MAX;
    //     // for(int i=1;i<n;i++){
    //     //     for(int j=i+1;j<n;j++){
    //     //         for(int k=j+1;k<n;k++){
    //     //            int aa=a[i],b=a[j],c=a[k];
    //     //             int d= abs(aa-b) + abs(b-c) + abs(c-aa);
    //     //             m=min(m,d);
    //     //         }
    //     //         cout<<endl;
    //     //     }
    //     // }
    //     for(int i=2;i<n-1;i++){
    //         int aa=a[i],b=a[i-1],c=a[i+1];
    //         int d= abs(aa-b) + abs(b-c) + abs(c-aa);
    //        m=min(m,d);
    //     }
    //     return m;
    // }
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> temp(101,vector<int>(1,0));
        int n=nums.size();
        for(int i=0;i<n;++i){
            temp[nums[i]][0]++;
            temp[nums[i]].push_back(i);
             if(temp[nums[i]][0]==3) {
                int a=temp[nums[i]][1],b=temp[nums[i]][2],c=temp[nums[i]][3];
                int d= abs(a-b) + abs(b-c) + abs(c-a);
                mini=min(mini,d);
            }
            else{
                int nn=temp[nums[i]].size();
                 for(int j=2;j<nn-1;++j){
                    int a=temp[nums[i]][j],b=temp[nums[i]][j-1],c=temp[nums[i]][j+1];
                    int d= abs(a-b) + abs(b-c) + abs(c-a);
                    mini=min(mini,d);
        }
            }
        }
        return mini==INT_MAX? -1: mini;
    }
};
// @lc code=end

