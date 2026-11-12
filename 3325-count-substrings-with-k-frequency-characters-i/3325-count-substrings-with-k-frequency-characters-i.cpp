class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int i=0,j=0,ans=0;
        unordered_map<char,int>mpp;
        while(j<s.length()){
            mpp[s[j]]++;
            while(mpp[s[j]]>=k){
                mpp[s[i]]--;
                i++;
            }
            ans+=i;
            j++;
        }
        return ans;
    }
};