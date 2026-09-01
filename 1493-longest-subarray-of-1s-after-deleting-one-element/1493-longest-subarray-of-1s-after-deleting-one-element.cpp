class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int countZero=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0) countZero++;
            while(countZero>1){
                if(nums[i]==0) countZero--;
                i++;
            }
            ans=max(j-i,ans);
            j++;
        }
        return ans;
    }
};