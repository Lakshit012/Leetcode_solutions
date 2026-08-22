class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int add=0;
        int prod=1;
        while(n>=1){
            add+=n%10;
            prod*=n%10;
            n/=10;
        }
         add+=prod;
        return num%add==0;
    }
};