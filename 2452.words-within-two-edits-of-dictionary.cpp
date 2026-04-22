/*
 * @lc app=leetcode id=2452 lang=cpp
 *
 * [2452] Words Within Two Edits of Dictionary
 */

// @lc code=start
class Solution {
public:
    int cmp(string &a,string &b){
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) ans++;
        }
        return ans;
    }
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int n=q.size();
        for(int i=0;i<n;i++){
            bool valid=false;
            for(auto x: d){
                int cm=cmp(q[i],x);
                if(cm<=2) {valid=true;ans.push_back(q[i]);}
                if(valid) break;
            }
        }
        return ans;
    }
};
// @lc code=end

