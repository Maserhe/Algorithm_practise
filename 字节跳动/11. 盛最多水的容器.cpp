class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int ans = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            int h = height[left] > height[right] ? height[right -- ]: height[left ++ ];
            ans = max(ans, h * (right - left + 1));
        }
        return ans;
    }
};