class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        typedef long long ll;
       ll ans=1LL*cost1*need1+1LL*cost2*need2;
       ll ans1=min(ans,1LL*costBoth*max(need1,need2));
       ll both=min(need1,need2);
       ll total=1LL*both*costBoth;
       need1-=both;
       need2-=both;
       if(need1>0){
        total+=1LL*need1*min(cost1,costBoth);
       }
       if(need2>0){
        total+=1LL*need2*min(cost2,costBoth);
       }
       ans1=min(ans1,total);
       return ans1;
    }
};