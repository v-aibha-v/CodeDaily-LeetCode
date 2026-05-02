/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution
{
public:
    // basic
    //  time -> n log n
    //  space -> n
    //   bool valid(int n){
    //       bool changed=false;
    //       while(n>0){
    //           int digit=n%10;
    //           n/=10;
    //           if(digit==2 or digit==5 or digit==6 or digit==9) changed=true;
    //           else if(digit==3 or digit==4 or digit==7) return false;
    //       }
    //       return changed;
    //   }
    //  vector<int> vec;
    //  //memo..
    //  int valid(int n) {
    //      if(vec[n]!=-2) return vec[n];
    //      if (n <= 0)
    //          return vec[n]=0;
    //      int digit = n % 10, temp;
    //      if (digit == 2 or digit == 5 or digit == 6 or digit == 9)
    //          temp = 1;
    //      else if (digit == 3 or digit == 4 or digit == 7)
    //          temp = -1;
    //      else
    //          temp = 0;
    //      int a = valid(n / 10);
    //      if(a==-1 or temp==-1) return vec[n]=-1;
    //      if(a==1 or temp==1) return vec[n]=1;
    //      else return vec[n]= 0;
    //  }
    //    //dp
    vector<int> vec;
    int valid(int n)
    {
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            vec[0] = 0;
            int digit = i % 10;
            int temp;
            if (digit == 2 or digit == 5 or digit == 6 or digit == 9)
                temp = 1;
            else if (digit == 3 or digit == 4 or digit == 7)
                temp = -1;
            else
                temp = 0;
            int a = vec[i / 10];
            if (a == -1 or temp == -1)
                vec[i] = -1;
            else if (a == 1 or temp == 1)
            {
                vec[i] = 1;
                ans++;
            }
            else
                vec[i] = 0;
        }
        return ans;
    }
    int rotatedDigits(int n)
    {
        // int ans = 0;
        vec.resize(n + 1, 0);
        // for (int i = 1; i <= n; i++) {
        //     if (valid(i)==1) {
        //         ans++;
        //     }
        // }
        // return ans;
        return valid(n);
    }
};
// @lc code=end
