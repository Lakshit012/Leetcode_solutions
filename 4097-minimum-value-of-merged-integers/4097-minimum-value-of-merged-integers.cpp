class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i+=2){
            int num=to_string(nums[i+1]).size();
            int temp=nums[i]*pow(10,num)+nums[i+1];
            ans=min(ans,temp);
        }

        return ans;
    }
};