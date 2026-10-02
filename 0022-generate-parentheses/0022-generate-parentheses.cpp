class Solution {
public:
    void solve(int n,vector<string>&ans,string &curr,int open,int close){
        if(curr.length()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solve(n,ans,curr,open+1,close);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(n,ans,curr,open,close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string>ans;
        solve(n,ans,curr,0,0);
        return ans;
    }
};