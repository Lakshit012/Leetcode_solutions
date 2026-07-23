class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int x:arr){
            mpp[x]++;
        }
        vector<int>nums;
        for(auto it:mpp){
            nums.push_back(it.second);
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]) return false;
        }
        return true;
    }
};
