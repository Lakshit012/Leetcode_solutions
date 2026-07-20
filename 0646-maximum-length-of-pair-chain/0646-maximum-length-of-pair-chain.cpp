class Solution {
public:
    static bool cmp(vector<int>&a ,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int prevEnd=pairs[0][1];
        int ans=1;
        for(int i=1;i<pairs.size();i++){
            if(prevEnd<pairs[i][0]){
                ans++;
                prevEnd=pairs[i][1];
            }
        }
        return ans;
    }
};