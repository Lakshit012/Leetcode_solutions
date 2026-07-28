class Solution {
public:
    string smallestPalindrome(string s){
        string ans;
        int n=s.length();
        if(n==1) return s;
        for(int i=0;i<n/2;i++){
            ans.push_back(s[i]);
        }
        sort(ans.begin(),ans.end());
        string ans1;
        for(int i=0;i<ans.length();i++){
            ans1.push_back(ans[i]);
        }
        if(n%2!=0) ans1.push_back(s[n/2]);
        for(int i=ans.length()-1;i>=0;i--){
            ans1.push_back(ans[i]);
        }
        return ans1;
    }
};