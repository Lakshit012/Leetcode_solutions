class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];
            int lastEnd=ans.back()[1];
            if(currStart<=lastEnd){
                ans.back()[1]=max(lastEnd,currEnd);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};