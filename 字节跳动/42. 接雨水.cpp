class Solution {
public:
    int trap(vector<int>& height) {

        // 对于 低柱子 直接 入栈。
        // 对于 高柱子， 应当 出栈。
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); i ++ ) {
            
            while (!st.empty() && height[st.top()] < height[i]) {
                // 第一个 出栈的
                int first = st.top();
                st.pop();
                if (st.empty()) break;
                //  第二个 出栈的
                int second = st.top();
                int h = min(height[i], height[second]) - height[first];
                ans += (i - second - 1) * h;

            }
            st.push(i);
        }
        return ans;
    }
};