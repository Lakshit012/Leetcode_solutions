class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};