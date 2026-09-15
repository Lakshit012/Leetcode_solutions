class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        ans=sum;
        int count=k;
        int j=cardPoints.size()-1;
        int i=k-1;
        while(count--){
            sum+=cardPoints[j];
            sum-=cardPoints[i];
            j--;
            i--;
            ans=max(sum,ans);
        }
        return ans;

    }
};