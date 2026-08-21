class Solution {
public:
    int solve(vector<int>&nums,int i,int end,vector<int>&dp){
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+solve(nums,i+2,end,dp);
        int nottake=solve(nums,i+1,end,dp);
        return dp[i]=max(nottake,take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
       vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
      return max(solve(nums,0,n-2,dp2),solve(nums,1,n-1,dp1));  
    }
};