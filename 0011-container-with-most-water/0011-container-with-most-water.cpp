class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=INT_MIN;
        while(i<j){
            int num=min(height[i],height[j]);
            ans=max(num*(j-i),ans);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};