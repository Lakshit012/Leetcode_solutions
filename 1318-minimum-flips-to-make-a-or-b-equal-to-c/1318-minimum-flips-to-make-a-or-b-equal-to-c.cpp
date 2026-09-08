class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a>0 || b>0 || c>0 ){
            int A=a&1;
            int B=b&1;
            int C=c&1;
            if(A==0 && B==0 && C==1){
                ans++;
            }
        else if(A==1 && B==1 && C==0){
            ans+=2;
        }
        else if(A==0 && B==1 &&C==0){
            ans++;
        }
        else if(A==1 && B==0 && C==0){
            ans++;
        }
        a=a>>1;
        b=b>>1;
        c=c>>1;
        }
        return ans;
    }
};