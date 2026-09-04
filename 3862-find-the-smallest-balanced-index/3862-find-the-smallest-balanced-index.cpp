class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<long double>prefix(nums.size());
        prefix[0]=0;
        for(int i=1;i<nums.size();i++){
            prefix[i]=(long double)prefix[i-1]+nums[i-1];
        }
        vector<long double>suffix(nums.size());
        suffix[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=(long double)(suffix[i+1]*nums[i+1]);
        }
        for(int i=0;i<nums.size();i++){
            if(suffix[i]==prefix[i]) return i;
        }
        return -1;
    }
};