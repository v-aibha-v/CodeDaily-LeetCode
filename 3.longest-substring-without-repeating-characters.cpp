/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int start=0,maxi=1;
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            if(st.find(s[i])==st.end()) st.insert(s[i]);
            else{
                //we found this ele
                while(s[start]!=s[i]){
                    st.erase(s[start++]);
                }
                start++;
            }
            maxi=max(maxi,i-start+1);
        }

        return maxi;
    }
};
// @lc code=end

