class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>>lineSweep;
        for(int i=0;i<logs.size();i++){
            int start=logs[i][0];
            int end=logs[i][1];
            lineSweep.push_back({start,+1});
            lineSweep.push_back({end,-1});
        }
        sort(lineSweep.begin(),lineSweep.end());
        int maxi=lineSweep[0][1];
        int ans=lineSweep[0][0];
         int currpop=lineSweep[0][1];
        for(int i=1;i<lineSweep.size();i++){
            currpop=currpop+lineSweep[i][1];
            if(currpop>maxi){
                ans=lineSweep[i][0];
                maxi=currpop;
            }
        }
        return ans;
    }
};