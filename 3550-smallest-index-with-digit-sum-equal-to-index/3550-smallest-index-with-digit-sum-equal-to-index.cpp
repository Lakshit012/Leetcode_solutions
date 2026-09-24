class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            string s=to_string(num);
            int sum=0;
            for(int i=0;i<s.length();i++){
                sum+=s[i]-'0';
            }
            if(sum==i) return i;
        }
        return -1;
    }
};