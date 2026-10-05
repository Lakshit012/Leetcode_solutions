class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=1;
        int ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='(') depth++;
            else {
            if(s[i-1]=='('){
                ans+=(1 << depth-1);
            }
            depth--;
        }
        }
        return ans;
    }
};