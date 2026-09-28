class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') count++;
            if(s[i]==')') count--;
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};