class Solution {
public:
    void solve(vector<int>&nums,int index,vector<vector<int>>&ans,vector<int>temp){
        if(index>=nums.size()){
            ans.push_back(temp);
            return;
    }
    // exclude
    solve(nums,index+1,ans,temp);
    // include
    int el=nums[index];
    temp.push_back(el);
    solve(nums,index+1,ans,temp);
    }
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        solve(nums,index,ans,temp);
        return ans;
    }
};