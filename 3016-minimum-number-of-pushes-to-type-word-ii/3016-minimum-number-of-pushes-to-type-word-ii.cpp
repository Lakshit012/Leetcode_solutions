class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        for(char ch:word){
            mpp[ch]++;
        }
        vector<int>nums;
        for(auto it:mpp){
            int freq=it.second;
            nums.push_back(freq);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=0;
        int cost=1;
        int idx=1;
        for(int i=0;i<nums.size();i++){
                if(idx>8){
                    idx=1;
                    ans+=nums[i]*(cost+1);
                    cost++;
                }
                else if(idx<=8){
                    ans+=nums[i]*cost;
                }
                idx++;
        }
        return ans;
    }
};