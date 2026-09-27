class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string ans;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(s[i]);
           else if(s[i]==')'){
                string temp;
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char ch:temp){
                    st.push(ch);
                }
           }
           else {
            st.push(s[i]);
           }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};