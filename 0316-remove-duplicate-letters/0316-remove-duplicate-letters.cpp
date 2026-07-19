class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>taken(26,false);
        vector<int>pos(26);
        string ans;
        for(int i=0;i<s.length();i++){
            pos[s[i]-'a']=i;
        }
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(taken[ch-'a']==true){
                continue;
            }
            while(ans.length()>0 && ans.back()>ch && pos[ans.back()-'a']>i){
                taken[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[ch-'a']=true;
        }
        return ans;
    }
};