class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mpp;
        while(j<s.length()){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};