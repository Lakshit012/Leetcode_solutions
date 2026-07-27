class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>diff(s.length()+1,0);
        for(int i=0;i<shifts.size();i++){
            int start=shifts[i][0];
            int end=shifts[i][1];
            int sign=shifts[i][2];
            if(sign==1){
                diff[start]+=1;
                diff[end+1]-=1;
            }
            else if(sign==0){
                diff[start]-=1;
                diff[end+1]+=1;
            }
        }
        int curr=0;
        vector<int> ans(s.length(), 0);
        for(int i=0;i<s.length();i++){
           curr+=diff[i];
           ans[i]+=curr;
        }
        for (int i = 0; i < s.length(); i++) {
    int x = s[i] - 'a';
    x = ((x + ans[i]) % 26 + 26) % 26;
    s[i] = x + 'a';
}

return s;
    }
};