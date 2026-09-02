class Solution {
public:
    bool solve(vector<int>&nums,int k){
        long long operation=0;
        for(int i=0;i<nums.size();i++){
            operation+=ceil((double)nums[i]/k);
            if(operation>(long long)k*k) return false;
        }
        if(operation>(long long)k*k) return false;
        else return true;
    }
    int minimumK(vector<int>& nums) {
        int low=1;
        int high = max((int)nums.size(),*max_element(nums.begin(),nums.end()));
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid)){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};