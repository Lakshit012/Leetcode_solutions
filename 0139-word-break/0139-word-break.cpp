class Solution {
public:
    int t[301];
  unordered_set<string>st;
  bool solve(int idx,string &s){
    if(idx>=s.length()) return true;
    if(st.find(s)!=st.end()) return true;
    if(t[idx]!=-1) return t[idx];
    for(int l=0;l<s.length();l++){
        string temp=s.substr(idx,l);
        if(st.find(temp)!=st.end()){
            if(solve(idx+l,s)) return t[idx]=true;
        }
    }
    return t[idx]=false;
  }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t,-1,sizeof(t));
       for(string &word:wordDict){
        st.insert(word);
       }
        return solve(0,s);
    }
};