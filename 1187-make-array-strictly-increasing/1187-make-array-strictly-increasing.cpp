class Solution {
public:
    map<pair<int,int>,int>mpp;
    int solve(vector<int>&arr1,vector<int>&arr2,int idx,int prev){
        if(idx>=arr1.size()) return 0;
        int skip=INT_MAX/2;
        int take=INT_MAX/2;
        if(mpp.find({idx,prev})!=mpp.end()) return mpp[{idx,prev}];
        if(prev<arr1[idx]){
             skip=solve(arr1,arr2,idx+1,arr1[idx]);
        }
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it!=arr2.end()){
            int num=it-arr2.begin();
            take=1+solve(arr1,arr2,idx+1,arr2[num]);
        }
        return mpp[{idx,prev}]=min(take,skip);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int ans= solve(arr1,arr2,0,INT_MIN);
        return ans>=INT_MAX/2 ? -1 : ans;
    }
};