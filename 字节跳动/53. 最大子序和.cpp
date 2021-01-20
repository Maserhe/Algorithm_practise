class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = nums[0];
        int count = nums[0];
        
        for (int i = 1; i < nums.size(); i ++ ) {
            count = max(count + nums[i], nums[i]);
            ans = max(ans, count);
        }
        return ans;
    }
};