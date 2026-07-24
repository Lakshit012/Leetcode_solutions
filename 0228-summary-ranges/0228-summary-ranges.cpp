class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()==0) return {};
        int start=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                continue;
            }
            ans.push_back({start,nums[i-1]});
            start=nums[i];
        }
        ans.push_back({start, nums.back()});
        vector<string>Ans;
        for(int i=0;i<ans.size();i++){
            int start=ans[i][0];
            int end=ans[i][1];
            if(start==end){
                Ans.push_back(to_string(start));
            }
            else Ans.push_back(to_string(start) + "->" + to_string(end));

        }
        return Ans;
    }
};