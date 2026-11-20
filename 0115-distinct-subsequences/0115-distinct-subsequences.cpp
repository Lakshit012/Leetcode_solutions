class Solution {
public:
     long long dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j){
        if(j==s2.size()) return 1;
        if(i==s1.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int skip=solve(s1,s2,i+1,j);
        int take=0;
        if(s1[i]==s2[j]){
            take=solve(s1,s2,i+1,j+1);
        }
            return dp[i][j]=skip+take;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};