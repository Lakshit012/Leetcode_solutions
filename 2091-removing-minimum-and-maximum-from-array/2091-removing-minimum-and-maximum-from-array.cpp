class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int frontMax=0;
        int frontMini=0;
        int backMax=0;
        int backMin=0;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                frontMax=i;
            }
            if(nums[i]==mini){
                frontMini=i;
            }
        }
         for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==maxi){
                backMax=i;
            }
            if(nums[i]==mini){
                backMin=i;
            }
        }
         int n = nums.size();
        int bothFront=max(frontMax,frontMini)+1;
        int bothBack=n-min(backMax,backMin);
        int mixed=min(
            frontMax + 1 + n - backMin,
            frontMini + 1 + n -backMax
        );

        return min({bothFront, bothBack, mixed});
        
    }
};