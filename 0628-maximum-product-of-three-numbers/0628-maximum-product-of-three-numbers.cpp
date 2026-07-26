class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first=INT_MIN;
        int second=INT_MIN;
        int third=INT_MIN;
        int small=INT_MAX;
        int small2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>first){
                third=second;
                second=first;
                first=nums[i];
            }
            else if(nums[i]>second){
                third=second;
                second=nums[i];
            }
            else if(nums[i]>third){
                third=nums[i];
            }
             if(nums[i]<small){
                small2=small;
                small=nums[i];
            }
            else if(nums[i]<small2){
                small2=nums[i];
            }
        }
        int ans=1LL*(first*second*third);
        int ans1=1LL*(first*small*small2);
        return max(ans,ans1);
    }
};