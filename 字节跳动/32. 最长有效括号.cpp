class Solution {
public:
    int longestValidParentheses(string s) {
        
        int m = s.size();
        stack<int> st;
        int ans = 0;
        int start = -1;

        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == '(') st.push(i);
            else {
                if (st.size()) {
                    st.pop();
                    if (st.size()) ans = max(ans, i - st.top());
                    else ans = max(ans, i - start);
                }
                else start = i;
            }
        }

        return ans;
    }
};