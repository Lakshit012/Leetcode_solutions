class Solution {
public:
    string reverseWords(string s) {
        vector<string>nums;
        for(int i=0;i<s.length();i++){
                while( i < s.length() && s[i]==' '){
                    i++;
                }
            string word;
            while(i<s.length() && s[i]!=' '){
                word.push_back(s[i]);
                i++;
            }
            if(!word.empty())
            nums.push_back(word);
        }
        string ans;
        for(int i=nums.size()-1;i>=0;i--){
            ans+=nums[i];
            if(i != 0)
            ans+=' ';
        }
        return ans;
    }
};