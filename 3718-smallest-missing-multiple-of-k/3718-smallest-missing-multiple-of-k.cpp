class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        int multiple=k;
        int ans=0;
        while(mpp.find(multiple)!=mpp.end()){
                multiple+=k;
                }
                 return multiple;
       }
};