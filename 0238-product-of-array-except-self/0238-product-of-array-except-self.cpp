class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        prefix[0]=1;
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }
        vector<int>suffix(nums.size());
        suffix[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(suffix[i]*prefix[i]);
        }
        return ans;
    }
};