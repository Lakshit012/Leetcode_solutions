class Solution {
public:
    typedef long long ll;
    ll t[100001][2];
    ll solve(vector<int>&nums,int idx,bool flag){
        if(idx>=nums.size()) return 0;
        if(t[idx][flag]!=-1) return t[idx][flag];
        ll skip=solve(nums,idx+1,flag);
        ll val=nums[idx];
        if(!flag) val=-nums[idx];
        ll take=solve(nums,idx+1,!flag)+val;
        return t[idx][flag]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        ll ans=solve(nums,0,true);
        return ans;
    }
};