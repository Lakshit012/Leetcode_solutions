class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int n=nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
        }
        for(int i=0;i<arr1.size();i++){
           nums[i]=arr1[i];
        }
        int j=0;
        for(int i=arr1.size();i<nums.size();i++){
            nums[i]=arr2[j];
            j++;
        }
        return nums;
    }
};