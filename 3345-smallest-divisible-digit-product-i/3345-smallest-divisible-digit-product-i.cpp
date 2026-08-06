class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=n;
        int product=1;
        while(n>=1){
            product*=n%10;
            n/=10;
        }
        if(product%t==0) return ans;
        int temp=ans;
        while(true){
            ans++;
            temp++;
            int prod=1;
            while(temp>=1){
                prod*=temp%10;
                temp/=10;
            }
            if(prod%t==0){
                return ans;
            }
            temp=ans;
        }
        return -1;
    }
};