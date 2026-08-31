class Solution {
public:
   bool solve(vector<int>&piles,int h,int k){
    int count=0;
    for(int i=0;i<piles.size();i++){
        count+=ceil((double)piles[i]/k);
        if(count>h) return false;
    }
    if(count>h) return false;
    else return true;
   }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(piles,h,mid)){
                high=mid-1;
                ans=min(mid,ans);
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};