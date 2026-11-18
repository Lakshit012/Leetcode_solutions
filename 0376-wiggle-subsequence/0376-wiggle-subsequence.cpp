class Solution {
public: 
    int n;
     vector<vector<vector<int>>> dp;
    int solve(vector<int>&nums,int idx,int prev,int flag){
        if(idx>=nums.size()) return 0;
        if(dp[idx][prev+1][flag]!=-1)
            return dp[idx][prev+1][flag];
        //skip
        int skip=solve(nums,idx+1,prev,flag);
        //take
        int take=0;
        if(prev==-1){
            take=1+solve(nums,idx+1,idx,2);
        }
        else if(flag==2){
           if(nums[idx]>nums[prev]){
            take=1+solve(nums,idx+1,idx,0);
           }
           else if(nums[idx]<nums[prev]){
            take=1+solve(nums,idx+1,idx,1);
           }
        }
        else if(flag==0 && nums[idx]<nums[prev]){
            take=1+solve(nums,idx+1,idx,1);
        }
        else if(flag==1 && nums[idx]>nums[prev]){
            take=1+solve(nums,idx+1,idx,0);
        }
        return dp[idx][prev+1][flag]=max(skip,take);
        }
    int wiggleMaxLength(vector<int>& nums) {
        n=nums.size();
        dp.assign(n, vector<vector<int>>(n+1, vector<int>(3, -1)));
        int idx=0;
        int flag=2;
        int prev=-1;
       return  solve(nums,idx,prev,flag);
    }
};