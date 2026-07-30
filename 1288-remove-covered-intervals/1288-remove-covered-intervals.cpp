class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int a=intervals[0][0];
        int b=intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            int c=intervals[i][0];
            int d=intervals[i][1];
            if(c>=a && b>=d){
                ans++;
            }
            else{
            a=intervals[i][0];
            b=intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};