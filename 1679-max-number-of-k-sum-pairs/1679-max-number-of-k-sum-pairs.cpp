class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int num=k-nums[i];
            if(num==nums[i]){
                if(mpp[num]>1){
                    mpp[num]--;
                    mpp[num]--;
                    if(mpp[num]==0) mpp.erase(num);
                    ans++;
                }
            }
            else if (mpp.find(num)!=mpp.end() && mpp[nums[i]]>=1 && mpp[num]>=1){
                mpp[num]--;
                mpp[nums[i]]--;
                if(mpp[num]==0) mpp.erase(num);
                if(mpp[nums[i]]==0) mpp.erase(nums[i]);
                ans++;
            }
        }
        return ans;
    }
};