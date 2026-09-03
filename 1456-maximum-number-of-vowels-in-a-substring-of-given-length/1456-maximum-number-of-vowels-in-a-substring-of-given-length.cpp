class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int ans=0;
        int countVowel=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                countVowel++;
            }
        }
        ans=countVowel;
            for(int i=k;i<s.length();i++){
                if(isVowel(s[i])) countVowel++;
                if(isVowel(s[i-k])) countVowel--;
                ans=max(ans,countVowel);
            }
        return ans;
    }
};