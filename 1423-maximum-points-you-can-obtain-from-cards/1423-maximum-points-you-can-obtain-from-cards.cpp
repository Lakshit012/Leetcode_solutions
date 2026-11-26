class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0;
        int j=cardPoints.size()-1;
        int ans=0;
        int total=0;
        while(i<k){
            total+=cardPoints[i];
            i++;
        }
        ans=total;
        while(i>0){
        total-=cardPoints[i-1];
        total+=cardPoints[j];
        ans=max(total,ans);
        i--;
        j--;
    }
     return ans;
    }
};