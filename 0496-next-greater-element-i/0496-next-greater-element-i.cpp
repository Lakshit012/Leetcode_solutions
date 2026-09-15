class Solution {
public:
    void solve(vector<int>&ans,int num,vector<int>&maxi,vector<int>&nums2){
        int index=-1;
        for(int i=0;i<nums2.size();i++){
                if(num==nums2[i]){
                    index=i;
                    break;
                }
        }
        ans.push_back(maxi[index]);
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>maxi(nums2.size(),-1);
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i]){
                maxi[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            solve(ans,nums1[i],maxi,nums2);
        }
        return ans;
    }
};