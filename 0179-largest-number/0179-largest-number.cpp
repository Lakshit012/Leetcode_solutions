class Solution {
public: 
    static bool mySort(int  a ,int b){
        string s=to_string(a)+to_string(b); 
        string s1=to_string(b)+to_string(a); 
        return s>s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),mySort);
        string ans="";
        for(int x:nums){
            ans+=to_string(x);
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};