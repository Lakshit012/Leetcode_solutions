class Solution {
public:
    int inc(vector<int>&nums){
        int i=0;
        int j=0;
        int ans=1;
        while(j<nums.size()-1){
             if(nums[j]<nums[j+1]){
                j++;
            }
            else{
                ans=max(ans,j-i+1);
                i=j+1;
                j++;
            }
        }
        ans=max(ans,j-i+1);
        return ans;
    }
    int dec(vector<int>&nums){
        int i=0;
        int j=0;
        int ans=1;
        while(j<nums.size()-1){
            if(nums[j]>nums[j+1]){
                j++;
            }
            else{
                ans=max(ans,j-i+1);
                i=j+1;
                j++;
            }
        }
        ans=max(j-i+1,ans);
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(inc(nums),dec(nums));
    }
};