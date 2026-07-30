class Solution {
public:
    int minimumPushes(string word) {
       int n=word.length();
        if(n<9) return n;
       int ans=0;
       int remaining =n;
       int cost=1;
       while(remaining>0){
        int take=min(8,remaining);
        ans+=take*cost;
        cost++;
        remaining-=take;
       }
       return ans;
    }
};