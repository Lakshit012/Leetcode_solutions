class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>nums(2050,0);
        int maxi=0;
        for(int i=0;i<logs.size();i++){
            int start=logs[i][0];
            int end=logs[i][1]-1;
            for(int j=start;j<=end;j++){
                nums[j]++;
                maxi=max(maxi,nums[j]);
            }
        }
        for(int i=1950;i<2050;i++){
            if(maxi==nums[i]) return i;
        }
        return -1;
    }
};