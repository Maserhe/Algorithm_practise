class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       
        if (nums.size() == 1) return;
        for (int i = nums.size() - 1; i > 0; i -- ) {
            if (nums[i] > nums[i - 1]) {
                sort(nums.begin() + i, nums.end());
                
                // 找到 第一个 数 大于 nums[i - 1];
                for (int j = i; j < nums.size();j ++ ) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[j], nums[i - 1]);
                        return;
                    }
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};