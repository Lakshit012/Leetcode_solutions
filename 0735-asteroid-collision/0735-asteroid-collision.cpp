class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty()) {
                st.push(asteroids[i]);
            } else if (!st.empty() && st.top() > 0 && asteroids[i] > 0){
                 st.push(asteroids[i]);
            }
            else if (!st.empty() && st.top() < 0 && asteroids[i] < 0)
                 st.push(asteroids[i]);
            else if (!st.empty() && st.top() < 0 && asteroids[i] > 0)
                st.push(asteroids[i]);
            else {
                int curr = st.top();
                int num = asteroids[i];
                while (curr > 0 && num < 0) {
                    if (abs(curr) == abs(num)) {
                        st.pop();
                        num = 0;
                        break;
                    } else if (abs(curr) > abs(num)) {
                        num = 0;
                        break;
                    } else {
                        st.pop();

                        if (st.empty())
                            break;

                        curr = st.top();
                    }
                }
                if (num != 0)
                    st.push(num);
            }
        }
        vector<int> ans;
        if (st.empty())
            return {};
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};