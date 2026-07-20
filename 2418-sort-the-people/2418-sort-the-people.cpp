class Solution {
public:
    static bool mySort(pair<string,int> a,pair<string,int>b){
        if(a.second>b.second) return true;
        else return false;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<string,int>>v;
    for(int i=0;i<heights.size();i++){
        v.push_back({names[i],heights[i]});
    }
    sort(v.begin(),v.end(),mySort);
    vector<string>ans;
    for(int i=0;i<heights.size();i++){
        ans.push_back(v[i].first);
    }
    return ans;
    }
};