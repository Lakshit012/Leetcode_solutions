class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                ans.push_back(s[i]);
            }
            else {
                ans.pop_back();
            }
        }
        return ans;
    }
};