class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        else return a[0]<b[0];
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       vector<vector<int>>nums;
       for(int i=0;i<profit.size();i++){
          nums.push_back({difficulty[i], profit[i]});
       }
       sort(nums.begin(),nums.end(),cmp);
       sort(worker.begin(),worker.end());
       int ans=0;
       int j=0;
       int maxi=0;
       for(int i=0;i<worker.size();i++){
        int ability=worker[i];
        while(j < nums.size() && ability>=nums[j][0]){
            maxi=max(nums[j][1],maxi);
            j++;
        }
        ans+=maxi;
       }
       return ans;
    }
};