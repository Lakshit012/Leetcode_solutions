class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>nums;
        for(int i=0;i<rocks.size();i++){
            int need=capacity[i]-rocks[i];
            nums.push_back(need);
        }
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans++;
                continue;
            }
            else if(nums[i]<=additionalRocks){
                additionalRocks-=nums[i];
                nums[i]=0;
                ans++;
            }
            else if(additionalRocks<nums[i]){
                break;
            }
        }
        return ans;
    }
};