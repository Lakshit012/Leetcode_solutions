class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]) return a[1]<b[1];
        else return a[0]<b[0];
    }
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>nums;
        int prevend=intervals[0][1];
        pq.push(prevend);
        for(int i=1;i<intervals.size();i++){
            int start=intervals[i][0];
           if(!pq.empty() && start>pq.top()){
            pq.pop();
           }
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};