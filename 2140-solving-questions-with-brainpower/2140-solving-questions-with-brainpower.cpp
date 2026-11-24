class Solution {
public: 
    long long t[100001];
    long long solve(vector<vector<int>>&nums,int idx){
        if(idx>=nums.size()) return 0;
        if(t[idx]!=-1) return t[idx];
        // skip
        long long skip=solve(nums,idx+1);
        //take
        long long take=0;
        take=nums[idx][0]+solve(nums,idx+nums[idx][1]+1);
        return t[idx]=max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(t,-1,sizeof(t));
        int idx=0;
        return solve(questions,idx);
    }
};