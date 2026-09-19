class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>ans(temperatures.size(),0);
       st.push(temperatures.size()-1);
        for(int i=temperatures.size()-2;i>=0;i--){
            int count=0;
           while(!st.empty() &&temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
    ans[i]=st.top()-i;
}
            st.push(i);
        }
        return ans;
    }
};