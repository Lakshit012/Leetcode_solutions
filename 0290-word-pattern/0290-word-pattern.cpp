class Solution {
public:
    string del(string &nums) {
        return "";
    }
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string nums;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                nums.push_back(s[i]);
            }
            else {
                words.push_back(nums);
                nums = del(nums);
            }
        }
        words.push_back(nums);
        if(words.size() != pattern.size()) return false;
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        for(int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            if(mp1.count(ch) && mp1[ch] != word)
                return false;

            if(mp2.count(word) && mp2[word] != ch)
                return false;

            mp1[ch] = word;
            mp2[word] = ch;
        }
        return true;
    }
};