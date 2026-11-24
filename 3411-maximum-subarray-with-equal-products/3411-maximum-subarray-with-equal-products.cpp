class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            long long l=1;
            long long g=0;
            long long p=1;
            for(int j=i;j<nums.size();j++){
                g=gcd(g,(long long)nums[j]);
                l=l/gcd(l,(long long)nums[j])*nums[j];

                if(p>(l*g)/nums[j]) break;

                p*=nums[j];

                if(p==l*g){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};
