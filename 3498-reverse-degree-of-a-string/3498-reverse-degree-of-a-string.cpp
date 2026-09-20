class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int num='z'-s[i]+1;
            ans+=num*(i+1);
        }
        return ans;
    }
};