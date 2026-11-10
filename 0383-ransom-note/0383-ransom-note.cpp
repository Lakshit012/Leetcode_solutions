class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mpp;
        for(char ch:magazine){
            mpp[ch]++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(mpp[ransomNote[i]]==0) return false;
            else mpp[ransomNote[i]]--;
        }
        return true;
    }
};