class Solution {
public:
    bool solve(string &str1,string &s){
        if(str1.size() % s.size() != 0) return false;
        for(int i=0;i<str1.size();i+=s.size()){
            string temp=str1.substr(i,s.size());
            if(temp!=s) return false;
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        int k=1;
        int Size = min(str1.size(), str2.size());
        while(k<=Size){
            string s=str2.substr(0,k);
            if(solve(str1,s) && solve(str2,s)){
                if(ans.length()<s.length()){
                    ans=s;
                }
            }
           k++;
        }
        return ans;
    }
};