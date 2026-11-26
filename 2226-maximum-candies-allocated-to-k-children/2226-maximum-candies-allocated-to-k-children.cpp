class Solution {
public:
    bool solve(vector<int>&candies,long long mid,long long k){
        long long count=0;
        for(int i=0;i<candies.size();i++){
           count+=candies[i]/mid;
           if(count>=k) return true;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       long long low=1;
       long long high = *max_element(candies.begin(), candies.end());
        int ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(solve(candies,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};