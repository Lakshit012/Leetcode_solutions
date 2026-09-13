class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto it:mpp){
            int num=it.first;
            vector<int>&arr=it.second;
            if(arr.size()>=3){
                bool ok=true;
                int j=0;
                int prev=arr[j+1]-arr[j];
                for(int i=1;i<arr.size()-1;i++){
                    if(prev!=arr[i+1]-arr[i]){
                        ok=false;
                        break;
                    }
                }
                if(ok==true) ans++;
        }
    }
    return ans;
    }
};
