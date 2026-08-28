class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        int ans=0;
        int i=0;
        while(i<nums.size()){
            int num=nums[i];
            int sum=k-num;
            if(mpp[num] > 0 && mpp[sum] > 0){
                if(num == sum && mpp[num] < 2) {
                    i++;
                    continue;
                }
                mpp[num]--;
                if(mpp[num]==0) mpp.erase(num);
                mpp[k-num]--;
                if(mpp[k-num]==0) mpp.erase(k-num);
                ans++;
            }
            i++;
        }
        return ans;
    }
};