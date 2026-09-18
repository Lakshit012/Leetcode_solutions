class Solution {
public: 
   bool vowel(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
    else return false;
   }
    string reverseVowels(string s) {
        string ans;
        for(int i=0;i<s.length();i++){
            if(vowel(s[i])){
                ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        string Ans;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(!vowel(s[i])) Ans.push_back(s[i]);
            else if(vowel(s[i])){
                Ans.push_back(ans[j]);
                j++;
            }
        }
        return Ans;
    }
};