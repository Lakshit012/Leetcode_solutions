class Solution {
public:
    void solve(vector<int>&nums,int idx,vector<int>&curr,set<vector<int>>&st){
        if(idx>=nums.size()){
            if(curr.size()>=2){
            st.insert(curr);
            }
            return;
        }
         if(curr.empty() ||curr.back()<=nums[idx]){
                curr.push_back(nums[idx]);
                solve(nums,idx+1,curr,st);
               curr.pop_back();
            
        }
        solve(nums,idx+1,curr,st);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>curr;
        set<vector<int>>st;
        solve(nums,0,curr,st);
        return  vector<vector<int>>(st.begin(),st.end());
        
    }
};