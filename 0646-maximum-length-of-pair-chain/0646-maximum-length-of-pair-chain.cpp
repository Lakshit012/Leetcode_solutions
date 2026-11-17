class Solution {
public:
    int t[1001][1001];
    int solve(vector<vector<int>>&pairs,int i,int p){
        if(i>=pairs.size()) return 0;
        // take
        if(t[i][p+1]!=-1) return t[i][p+1];
        int take=0;
        if(p==-1 || pairs[i][0]>pairs[p][1]){
            take=1+solve(pairs,i+1,i);
        }
        // exclude
        int skip=solve(pairs,i+1,p);
        return t[i][p+1]=max(skip,take);

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(t,-1,sizeof(t));
        return solve(pairs,0,-1);
    }
};