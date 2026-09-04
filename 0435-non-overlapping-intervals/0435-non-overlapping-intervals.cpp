class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int prev=intervals[0][1];
        int ans=0;
        for(int i=1;i<intervals.size();i++){
          if(prev>intervals[i][0]){
            ans++;
          }
          else{
            prev=intervals[i][1];
          }
        }
        return ans;
    }
};