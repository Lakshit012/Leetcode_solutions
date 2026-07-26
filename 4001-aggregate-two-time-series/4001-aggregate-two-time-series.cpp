class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i=0;
        int j=0;
        vector<vector<int>>ans;
        while(i<series1.size() && j<series2.size()){
            int time1=series1[i][0];
            int time2=series2[j][0];
            if(time1==time2){
                ans.push_back({time1,series1[i][1]+series2[j][1]});
                i++;
                j++;
            }
            else if (time1>time2){
                ans.push_back({time2,series1[i][1]+series2[j][1]});
                j++;
            }
            else if(time1<time2){
                ans.push_back({time1,series1[i][1]+series2[j][1]});
                i++;
            }
        }
       while(i < series1.size()){
    ans.push_back({series1[i][0], series1[i][1]});
    i++;
}

while(j < series2.size()){
    ans.push_back({series2[j][0], series2[j][1]});
    j++;
}
        return ans;
    }
};