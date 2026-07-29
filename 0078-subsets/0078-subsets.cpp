class Solution {
public:
    void solve(vector<int>&nums,int idx,vector<vector<int>>&temp,vector<int>&curr){
        if(idx==nums.size()){
            temp.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(nums,idx+1,temp,curr);
        curr.pop_back();
        solve(nums,idx+1,temp,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>temp;
        vector<int>curr;
        int idx=0;
        solve(nums,idx,temp,curr);
        return temp;
    }
};