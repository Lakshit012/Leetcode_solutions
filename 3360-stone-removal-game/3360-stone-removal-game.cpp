class Solution {
public:
    bool canAliceWin(int n) {
      bool ans=true;
      int i=10;
      while(n>=i){
            n-=i;
            i--;
            ans=!ans;
      }  
      return !ans;
    }
};