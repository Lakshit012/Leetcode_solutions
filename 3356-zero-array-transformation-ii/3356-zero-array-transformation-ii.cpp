class Solution {
public:
    bool check(vector<int>&nums,vector<vector<int>>&queries,int k){
        vector<int>diff(nums.size()+1);
        for(int i=0;i<k;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];
            diff[start]+=val;
            diff[end+1]-=val;
        }
        vector<int>ans(nums.size(),0);
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=diff[i];
            ans[i]=curr;
        }
        for(int i=0;i<nums.size();i++){
            if(ans[i]<nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums,vector<vector<int>>& queries) {
        int low=0;
        int high=queries.size();
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,queries,mid)){
                ans=min(ans,mid);
                 high=mid-1;
            }
            else low=mid+1;
        }
        if(ans==INT_MAX) return -1;
        else
        return ans;
    }
};