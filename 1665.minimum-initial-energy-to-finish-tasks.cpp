/*
 * @lc app=leetcode id=1665 lang=cpp
 *
 * [1665] Minimum Initial Energy to Finish Tasks
 */

// @lc code=start
class Solution {
public:
    static bool custom(const vector<int>&a,const vector<int>&b){
        // if(a[1]>b[1]) return true;
        // else if(a[1]==b[1] and a[0]<b[0]) return true;
        // else return false;
        // if((a[1]-a[0]) > (b[1]-b[0])) return true;
        // // if(a[1]>b[1]) return true;
        // // // if(a[0]>b[0] ) return true;
        // // return false;
        // return a[1]>b[1];
        int d1=a[1]-a[0],d2=b[1]-b[0];
        if(d1>d2) return true;
        if(d1==d2) return a[1]>b[1];
        return false;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),custom);
        int ans=0,curr=0;
        for(auto x: tasks){
            int a=x[0],b=x[1];
            // cout<<a<<" "<<b<<" ";
            if(curr>=b){
                curr-=a;
            }
            else{
                int add=b-curr;
                ans+=add;
                curr+=add;
                curr-=a;
            }
            // cout<<endl;
        }
        return ans;
    }
};
// @lc code=end

