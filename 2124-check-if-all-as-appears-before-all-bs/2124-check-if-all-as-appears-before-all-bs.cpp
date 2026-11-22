class Solution {
public:
    bool checkString(string s) {
       int count=0;
       for(char ch:s){
        if(ch=='b'){
            count++;
        }
        if(ch=='a'){
            if(count>0) return false;
        }
       } 
       return true;
    }
};