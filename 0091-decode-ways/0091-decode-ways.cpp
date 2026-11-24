class Solution {
public:
    int t[101];
    int solve(string & s,int idx){
        if(idx>s.length()) return 0;
        if(idx==s.length()) return 1;
        if(s[idx]=='0') return 0;
        if(t[idx]!=-1) return t[idx];
        int takeone=solve(s,idx+1);
        int takeTwo=0;
        if(s.length()-idx>=2){
            string s1=s.substr(idx,2);
            int num=stoi(s1);
            if(num>=10 && num<=26){
                takeTwo=solve(s,idx+2);
            }
        }
        return t[idx]=takeone+takeTwo;
    }
    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
      return solve(s,0);
    }
};