class Solution {
public:
  static bool cmp(const pair<int,int>&a,const pair<int,int>&b){
        if(a.first==b.first) return a.second<b.second;
        else return a.first<b.first;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>ans;
        for(int i=0;i<arr.size();i++){
           ans.push_back({abs(arr[i] - x), arr[i]});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>Ans;
        for(int i=0;i<k;i++){
            Ans.push_back(ans[i].second);
        }
        sort(Ans.begin(),Ans.end());
        return Ans;
    }
};