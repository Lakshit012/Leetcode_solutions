class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int  maxi=nums[nums.size()-1];
        vector<int>ans;
        int j=0;
        for(int i=mini;i<=maxi;i++){
           if(nums[j]==i) j++;
           else if(nums[j]!=i) ans.push_back(i);
        }
        return ans;
    }
};