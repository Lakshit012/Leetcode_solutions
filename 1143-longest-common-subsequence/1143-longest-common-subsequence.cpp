class Solution {
public:
    int dp[1001][1001];
    int solve(string &t1,string &t2,int i,int j){
        if(i>=t1.size() || j>=t2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]){
            return 1+solve(t1,t2,i+1,j+1);
        }
        return  dp[i][j]=max(solve(t1,t2,i+1,j),solve(t1,t2,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,0,0);
    }
};