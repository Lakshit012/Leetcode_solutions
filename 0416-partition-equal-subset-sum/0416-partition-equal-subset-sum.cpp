class Solution {
public: 
    int t[201][10001];
    bool solve(vector<int>&nums,int n,int sum){
        if(sum==0) return true;
        if(n==0) return false;
        if(t[n][sum]!=-1) return t[n][sum];
        bool skip=solve(nums,n-1,sum);
        bool take=false;
        if(nums[n-1]<=sum)
         take=solve(nums,n-1,sum-nums[n-1]);
        return t[n][sum]=skip || take;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        memset(t,-1,sizeof(t));
        if(sum%2!=0) return false;
        int num=sum/2;
        return solve(nums,nums.size()-1,num);
    }
};