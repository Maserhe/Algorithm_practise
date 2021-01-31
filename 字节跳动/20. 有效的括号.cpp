class Solution {
public:
    bool isValid(string s) {
        if (!s.size()) return false;
        stack<char> st;
        set<char> bucket;
        bucket.insert('(');
        bucket.insert('[');
        bucket.insert('{');

        for (int i = 0; i < s.size(); i ++ ) {
            if (bucket.find(s[i]) != bucket.end()) {
                st.push(s[i]);
            }
            else if (st.size()) {
                char t = st.top();
                if (s[i] == ')' && t == '(') st.pop();
                else if (s[i] == ']' && t == '[') st.pop();
                else if (s[i] == '}' && t == '{') st.pop();
                else return false;
            }
            else return false;
        }
        if (st.empty())return true;
        else return false;
    }
};