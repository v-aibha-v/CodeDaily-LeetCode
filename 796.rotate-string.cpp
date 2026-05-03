/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1=s.size(),n2=goal.size();
        // // for(int i=0;i<n1-n2;i++){
        // //     if(s[i]==goal[0]){
        // //         bool valid=true;
        // //         for(int j=1;j<n2;j++){
        // //             if(s[i+j]!=goal[j]){ valid=false;break;}
        // //         }
        // //         if(valid) return true;
        // //     }
        // // }
        // // return false;
        // if(n1!=n2) return false;
        // for(int i=0;i<n1;i++){
        //     int temp=0,idx=i;
        //     bool valid=true;
        //     while(temp<n1){
        //         if(s[idx]!=goal[temp]) {valid=false; break;}
        //         temp++;
        //         idx=(idx+1 )%n1;
        //     }
        //     if(valid and temp==n2) return true;
        // }
        // return false;
        if(n1!=n2) return false;
        return (s+s).find(goal)!= string::npos;
    }
};
// @lc code=end

