class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int>diff(1e5+1,0);
        for(int i=0;i<nums1.size();i++){
            int num=abs(nums1[i]-nums2[i]);
            diff[num]++;
        }
        int K=k1+k2;
        for(int j=1e5; j>0 && K>0 ; j--){
            // for curr element
            int noOps=min(diff[j],K);
            diff[j]-=noOps; // did curr element-1;
            diff[j-1]+=noOps;
            K-=noOps;
        }
        long long ans=0;
        for(long long i=1;i<=1e5;i++){
            ans+=(diff[i]*i*i);
        }
        return ans;
    }
};