class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;
    set<int> st;

    void search(vector<int> & nums) {
        
        if (temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i ++ ) {
            if (st.find(nums[i]) != st.end()) continue;

            st.insert(nums[i]);
            temp.push_back(nums[i]);
            
            search(nums);

            st.erase(nums[i]);
            temp.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        search(nums);
        return ans;
    }
};