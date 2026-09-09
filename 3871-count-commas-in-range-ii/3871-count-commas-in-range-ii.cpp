class Solution {
public:
    long long countCommas(long long n) {
        long long commas=0;
        long long start=1000;
        while(start<=n){
            commas+=n-start+1;
            start*=1000;
        }
        return commas;
    }
};