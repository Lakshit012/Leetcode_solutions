class Solution {
public:
    int t[366];
    int solve(vector<int>&days,vector<int>&costs,int idx){
        if(idx>=days.size()) return 0;
        if(t[idx]!=-1) return t[idx];
        int s1=costs[0]+solve(days,costs,idx+1);
        
        int id2=upper_bound(days.begin()+idx,days.end(),days[idx]+6)-days.begin();
        int s2=costs[1]+solve(days,costs,id2);

        int id3=upper_bound(days.begin()+idx,days.end(),days[idx]+29)-days.begin();
        int s3=costs[2]+solve(days,costs,id3);
        
        return t[idx]=min({s1,s2,s3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solve(days,costs,0);
    }
};