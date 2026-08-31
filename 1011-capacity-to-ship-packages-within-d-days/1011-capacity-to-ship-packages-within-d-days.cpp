class Solution {
public: 
    bool solve(vector<int>&weights,int days,int maxi){
        int count=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>maxi)
                 return false;
            if(sum+weights[i]>maxi){
                sum=weights[i];
                count++;
                if(count>days) return false;
            }
            else {
                sum+=weights[i];
            }
        }
         return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(weights,days,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};