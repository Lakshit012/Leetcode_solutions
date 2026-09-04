class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>suffix(nums.size());
        int prev=nums[0];
        suffix[0]=prev;
        for(int i=1;i<nums.size();i++){
            suffix[i]=max(nums[i],suffix[i-1]);
        }
        vector<int>prefix(nums.size());
        prev=nums[nums.size()-1];
        prefix[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            prefix[i]=min(nums[i],prefix[i+1]);
        }
        for(int i=0;i<nums.size();i++){
            if(suffix[i] - prefix[i]<=k){
                return i;
            }
        }
        return -1;
    }
};