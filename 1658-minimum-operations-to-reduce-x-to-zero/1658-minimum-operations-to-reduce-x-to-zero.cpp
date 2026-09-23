class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0;
        int j=0;
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int target=totalSum-x;
        int sum=0;
        int ans=-1;
        if(target<0)
            return -1;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>target){
                sum-=nums[i];
                i++;
            }
            if(sum==target){
            ans=max(ans,j-i+1);
            }
            j++;
        }
        if(ans == -1)
            return -1;
        return nums.size()-ans;
    }
};