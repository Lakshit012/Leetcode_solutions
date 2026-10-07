class Solution {
public:
    char findTheDifference(string s, string t) {
       unordered_map<char,int>mpp;
       for(char &ch:s){
        mpp[ch]++;
       } 
       for(char &ch:t){
        if(mpp[ch]==0) {
                return ch;
            }
            mpp[ch]--;
       }
       return '\0';
    }
};