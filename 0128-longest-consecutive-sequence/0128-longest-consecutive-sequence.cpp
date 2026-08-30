class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mpp;
        for(int x:nums){
            mpp.insert(x);
        }
        int ans=0;
        for(int num:mpp){
           int cnt=1;
           if(mpp.find(num-1)==mpp.end()){
            while(mpp.find(num+1)!=mpp.end()){
                num++;
                cnt++;
            }
            ans=max(ans,cnt);
           }
        }
        return ans;
    }
};