class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      int ans=0;
      int i=0;
      int j=0;
      unordered_map<int,int>mpp;
      while(j<nums.size())
      {
        mpp[nums[j]]++;
        while(mpp[nums[j]]>k){
            mpp[nums[i]]--;
            if(mpp[nums[i]]==0){
                mpp.erase(nums[i]);
            }
            i++;
        }
        ans=max(ans,j-i+1);
         j++;
      }
      return ans;
    }
};