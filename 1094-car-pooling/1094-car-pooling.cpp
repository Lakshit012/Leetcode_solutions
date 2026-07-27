class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        else return a[0]<b[0];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> lineSweep;
        for(int i=0;i<trips.size();i++){
            int cust=trips[i][0];
            int from=trips[i][1];
            int to =trips[i][2];
            lineSweep.push_back({from,cust});
            lineSweep.push_back({to,-cust});
        }
        sort(lineSweep.begin(),lineSweep.end(),cmp);
        int curr=0;
        for(int i=0;i<lineSweep.size();i++){
            curr+=lineSweep[i][1];
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};