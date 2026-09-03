class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        int prev=nums[0];
        prefix[0]=prev;
        for(int i=1;i<nums.size();i++){
            prefix[i]=max(prefix[i-1],nums[i]);
        }
        prev=nums[nums.size()-1];
        suffix[nums.size()-1]=prev;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],nums[i]);
        }
       int ans=-1;
       for(int i=0;i<nums.size();i++){
        int num=prefix[i]-suffix[i];
        if(num<=k){
            return i;
            break;
        }
       }
       return ans;
    }
};