class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
         int sum=0;
         int ans=0;
         int cust=0;
         for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                sum+=customers[i];
            }
            else{
                cust+=customers[i];
            }
         }
         ans=sum;
         for(int i=minutes;i<customers.size();i++){
            if(grumpy[i-minutes]==1){
                sum-=customers[i-minutes];
            }
            if(grumpy[i]==1){
                sum+=customers[i];
            }
            else if(grumpy[i]==0) cust+=customers[i];
            ans=max(sum,ans);
         }
       return cust+ans;
    }
};