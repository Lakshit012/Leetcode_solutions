class Solution {
public:
    int solve(int i,int p,vector<int>&nums,vector<vector<int>>& t){
        if(i>=nums.size()) return 0;
        // take
        if(t[i][p+1]!=-1) return t[i][p+1];
        int take=0;
        if(p==-1 || nums[i]>nums[p])
         take=1+solve(i+1,i,nums,t);
        // exclude
        int skip=solve(i+1,p,nums,t);
        return t[i][p+1]=max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
        vector<vector<int>> t(n, vector<int>(n+1, -1));
         return solve(0,-1,nums,t);
    }
};