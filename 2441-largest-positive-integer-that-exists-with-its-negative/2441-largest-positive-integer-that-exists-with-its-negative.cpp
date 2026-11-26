class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int x:nums) mpp[x]++;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i]*(-1))!=mpp.end()) return -1*nums[i];
        }
        return -1;
    }
};