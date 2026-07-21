class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        vector<int>ans1;
        vector<int>ans2;
        int n=nums.size();
        int size1;
        if(n%2!=0){
            size1=n/2+1;
        }
        else  size1=n/2;
        for(int i=0;i< size1;i++){
            ans1.push_back(nums[i]);
        }
        for(int i=size1;i<nums.size();i++){
            ans2.push_back(nums[i]);
        }
        reverse(ans1.begin(),ans1.end());
        reverse(ans2.begin(),ans2.end());
        vector<int>ans;
        for(int i=0;i<nums.size()/2;i++){
            ans.push_back(ans1[i]);
            ans.push_back(ans2[i]);
        }
        if (ans1.size() > ans2.size()) {
    ans.push_back(ans1.back());
}

        for(int i=0;i<nums.size();i++){
            nums[i]=ans[i];
        }
    }
};