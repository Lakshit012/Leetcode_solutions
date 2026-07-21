class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        vector<int>nums;
        for(auto it:mpp){
            nums.push_back(it.second);
        }
        int ans=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(k>=nums[i]){
                k=k-nums[i];
                ans--;
            }
            else break;
        }
        return ans;
    }
};
