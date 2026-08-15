class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=nums[0];
        bool nz=nums[0]!=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=0) nz=true;
             x=x^nums[i];
        }
        if(!nz) return 0;
        if(x==0) return n-1;
        else return n;
    }
};