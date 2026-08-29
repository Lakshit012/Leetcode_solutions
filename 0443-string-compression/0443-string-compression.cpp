class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int j=0;
        while(j<chars.size()){
            int no=0;
            char ch=chars[j];
            while(j<chars.size() && chars[j]==ch){
                j++;
                no++;
            }
            chars[i++]=ch;
            if(no>1){
                string ans;
                ans+=to_string(no);
                for(char s:ans){
                    chars[i++]=s;
                }
            }
        }
        return i;
    }
};