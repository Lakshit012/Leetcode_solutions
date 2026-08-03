class Solution {
public:
    int n;
    int solve(vector<int>&stoneValue,int i,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int take=0;
        int ans=INT_MIN;
        for(int k=0;k<3&& i+k<n;k++){
            take+=stoneValue[i+k];
            ans=max(take-solve(stoneValue,i+k+1,dp),ans);
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<int>dp(n+1,-1);
       int Ans= solve(stoneValue,0,dp);
        if(Ans==0)return "Tie";
        if(Ans>0)  return "Alice";
        else  return "Bob";
    }
};