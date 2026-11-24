class Solution {
public: 
    int t[301][5001];
    int solve(int &amount,vector<int>&coins,int idx,int coin){
        if(coin>amount) return 0;
        if(coin==amount) return 1;
         if(idx>=coins.size()) return 0;
         if(t[idx][coin]!=-1) return t[idx][coin];
        int same=0;
        int next=0;
        // take same coin
        same=solve(amount,coins,idx,coin+coins[idx]);
        // take next  coin
        if(idx+1<coins.size()){
            next=solve(amount,coins,idx+1,coin);
        }
        return t[idx][coin]=same+next;
    }
    int change(int amount, vector<int>& coins) {
        memset(t,-1,sizeof(t));
       return solve(amount,coins,0,0);

    }
};