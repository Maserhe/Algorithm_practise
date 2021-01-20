class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;
    
    bool falg = true;

    void search(int index, int target, vector<int> & nums) {

        if (temp.size() == 3) {
            if (target == 0) ans.push_back(temp);
            return;
        }
        
        if (index < nums.size()) {

            // 去除重复。
            if (falg || (index > 0 && nums[index - 1] != nums[index])) {
                temp.push_back(nums[index]);
                bool t = falg;
                falg = true;
                search(index + 1, target + nums[index], nums);
                temp.pop_back();   
                falg = t;
            }
            // 不选择当前数。
            falg = false;
            search(index + 1, target, nums);
        }

    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        search(0, 0, nums);
        return ans;
    }
};