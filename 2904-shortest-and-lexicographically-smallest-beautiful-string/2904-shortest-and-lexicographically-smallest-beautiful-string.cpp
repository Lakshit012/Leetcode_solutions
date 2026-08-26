class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int  j=0;
         string ans = "";
        int count=0;
        while(j<s.length()){
            if(s[j]=='1') count++;
            while(count==k) {
                string curr = s.substr(i, j - i + 1);
                if(ans=="" || curr.length()<ans.length() || curr.length()==ans.length() && curr<ans){
                    ans=curr;
                }
                if(s[i]=='1') count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};