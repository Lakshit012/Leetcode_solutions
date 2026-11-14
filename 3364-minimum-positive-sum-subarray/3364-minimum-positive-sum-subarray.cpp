class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
         int ans=INT_MAX;
         for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                int len=j-i+1;
                sum+=nums[j];
                if(len>=l && len<=r){
                    if(sum>0)
                    ans=min(ans,sum);
                }
                if(len>r) break;
            }
         }
         if(ans==INT_MAX) return -1;
         else
         return ans;
    }
};