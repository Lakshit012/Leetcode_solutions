class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==nums.size()) return *max_element(nums.begin(),nums.end());
       vector<vector<int>>arr;
       for(int j=0;j<=nums.size()-k;j++){
        vector<int>temp;
        int i=j;
        int num=0;
        while(num<k){
            temp.push_back(nums[i]);
            i++;
            num++;
        }
        arr.push_back(temp);
       }
 unordered_map<int,int>mpp;
 for(int i=0;i<arr.size();i++){
    int Size=arr[i].size();
    for(int j=0;j<k;j++){
        mpp[arr[i][j]]++;
    }
 }
 int ans=-1;
 for(auto it :mpp){
    int no=it.first;
    int freq=it.second;
    if(freq==1){
        ans=max(ans,no);
    }
 }
 return ans;
    }
};