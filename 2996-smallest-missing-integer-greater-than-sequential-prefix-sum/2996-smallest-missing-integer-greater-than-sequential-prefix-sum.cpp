class Solution {
public:
int count;
    int solve(vector<int>&nums,int sum){
        for(int i=0;i<nums.size();i++){
        if(sum==nums[i]) return true;
        }
         return false;
    }
    int missingInteger(vector<int>& nums) {
         count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                  count++;
            }
            else{
              
                break;
            }
           
        }
        int sum=nums[0];
        for(int i=1;i<count;i++){
            sum+=nums[i];
        }
        int ans=sum;

   while(solve(nums, ans)){
    ans++;
}

return ans;
  
    }
};