class Solution {
public:
    int solve(vector<int>&piles,int l,int r,int person,vector<vector<vector<int>>>&dp){
        if(l>r) return 0;
        if(dp[l][r][person]!=-1) return dp[l][r][person];
        if(l==r){
            if(person==1){
              return dp[l][r][person]=piles[l];
            }
            else  return dp[l][r][person]=0;
        }
        if(person==1){
            int left=piles[l]+solve(piles,l+1,r,0,dp);
            int right=piles[r]+solve(piles,l,r-1,0,dp);
            return dp[l][r][person]=max(right,left);
        }
        else if(person==0){
            int right=solve(piles,l,r-1,1,dp);
            int left=solve(piles,l+1,r,1,dp);
            return dp[l][r][person]=min(left,right);
        }
        return 0;
    }
    bool stoneGame(vector<int>& piles) {
        int sum=accumulate(piles.begin(),piles.end(),0);
        int n=piles.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector(2,-1)));
        int l=0;
        int r=piles.size()-1;
        int player1=solve(piles,l,r,1,dp);
        int player2=sum-player1;
        return player1>=player2;
    }
};