class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+1,0);
        for(int i=0;i<bookings.size();i++){
            int start=bookings[i][0];
            int end=bookings[i][1];
            int seats=bookings[i][2];
            diff[start]+=seats;
            if(end+1<=n){
            diff[end+1]-=seats;
            }
        }
        vector<int>ans;
        int curr=0;
        for(int i=1;i<diff.size();i++){
            curr+=diff[i];
            ans.push_back(curr);
        }
        return ans;
    }
};