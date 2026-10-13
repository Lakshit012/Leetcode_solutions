class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        vector<long long>arr;
        for(int i=0;i<nums.size();i++){
             long long num=nums[i]*nums[i];
            arr.push_back(num);
        }
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<(arr.size()+1)/2;i++){
            ans+=arr[i];
        }
        for(int i=(arr.size()+1)/2;i<arr.size();i++){
            ans-=arr[i];
        }
        return ans;
    }
};