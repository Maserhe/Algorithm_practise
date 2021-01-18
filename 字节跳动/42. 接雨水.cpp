class Solution {
public:
    int trap(vector<int>& height) {

        // ���� ������ ֱ�� ��ջ��
        // ���� �����ӣ� Ӧ�� ��ջ��
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); i ++ ) {
            
            while (!st.empty() && height[st.top()] < height[i]) {
                // ��һ�� ��ջ��
                int first = st.top();
                st.pop();
                if (st.empty()) break;
                //  �ڶ��� ��ջ��
                int second = st.top();
                int h = min(height[i], height[second]) - height[first];
                ans += (i - second - 1) * h;

            }
            st.push(i);
        }
        return ans;
    }
};