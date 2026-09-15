class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        int sum=0;
        unordered_map<int,int>mpp;
        int i=0;
        int j=0;
        while(j<nums.size()){
             sum+=nums[j];
              mpp[nums[j]]++;
            while(mpp[nums[j]]>1){
                sum-=nums[i];
                mpp[nums[i]]--;
                i++;
            }
            ans=max(sum,ans);
            j++;
        }
        return ans;
    }
};