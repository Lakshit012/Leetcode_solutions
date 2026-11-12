class Solution {
public:
    int freq(string &s,int k,int j){
         vector<int>ch(27,0);
        while(j<s.length()){
            ch[s[j]-'a']++;
            if(ch[s[j]-'a']>=k){
                break;
            }
            j++;
        }
        return s.size()-j;
    }
    int numberOfSubstrings(string s, int k) {
        int Ans=0;
       for(int i=0;i<s.length();i++){
       int ans=freq(s,k,i);
        if(ans==0) break;
        else Ans+=ans;
       }
       return Ans;
    }
};