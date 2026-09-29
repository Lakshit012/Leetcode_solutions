class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j && s[i]==s[j]){
            char ch=s[i];
            char ch2=s[j];
            while(i<=j && s[j]==ch){
                j--;
            }
            while(i<=j && s[i]==ch2){
                i++;
            }
        }
        return j-i+1;
    }
};