class Solution {
public:
    int n;
    int solve(vector<int>&nums,int prev,int idx,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        //take
        if(dp[idx][prev+1]!=-1)  return dp[idx][prev+1];
        int take=-1;
        int skip=-1;
        if(prev==-1 || nums[prev]<nums[idx]){
            take= 1+solve(nums,idx,idx+1,dp);
        }
        //skip
         skip=solve(nums,prev,idx+1,dp);
       return dp[idx][prev+1]=max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       ans= solve(nums,-1,0,dp);
       return ans;
    }
};