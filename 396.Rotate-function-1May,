class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size(),f=0,maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            f+= i*nums[i];
            sum+=nums[i];
        }
        maxi=max(maxi,f);
        for(int i=1;i<n;i++){
            int t= f+sum-n*nums[n-i];
            f=t;
        maxi=max(maxi,f);

        }
        return maxi;
    }
};
