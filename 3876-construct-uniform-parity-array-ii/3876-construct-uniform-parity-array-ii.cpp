class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int countOdd=0;
        int smallOdd=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2!=0){
                countOdd++;
                smallOdd=min(smallOdd,nums1[i]);
            }
        }
        if(countOdd==0) return true;
        if(countOdd == nums1.size()) return true;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i] % 2 == 0){
        if(nums1[i] <= smallOdd)
            return false;
    }
        }
        return true;
    }
};