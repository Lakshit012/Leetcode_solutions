class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &it:mpp){
            int num=it.first;
            vector<int>&arr=it.second;
            if(arr.size()==3){
                int i=0;
                if(arr[i+1]-arr[i]==arr[i+2]-arr[i+1]) ans++;    
        }
    }
    return ans;
    }
};