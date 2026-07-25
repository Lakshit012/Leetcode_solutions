class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>diff(2051,0);
        for(int i=0;i<logs.size();i++){
            int start=logs[i][0];
            int end=logs[i][1];
            diff[start]=diff[start]+1;
            diff[end]=diff[end]-1;
        }
        int ans=1950;
        int maxi=diff[1950];
        for(int i=1951;i<=2050;i++){
            diff[i]=diff[i]+diff[i-1];
            if(diff[i]>maxi){
                maxi=diff[i];
                ans=i;
            }
        }
        return ans;
    }
};