class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>diff(nums.size()+1,0);
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            diff[start]++;
            diff[end+1]--;
        }
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=diff[i];
            if(curr<nums[i]) return false;
        }
        return true;
    }
};