class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]) return a[0]>b[0];
        else return a[1]<b[1];
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int x:nums){
            mpp[x]++;
        }
        vector<vector<int>>ans;
        for(auto it :mpp){
            int el=it.first;
            int freq=it.second;
            ans.push_back({el,freq});
        }
        vector<int>Ans;
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0;i<ans.size();i++){
            int el=ans[i][0];
            int freq=ans[i][1];
            while(freq--){
                Ans.push_back(el);
            }
        }
        return Ans;
    }
};